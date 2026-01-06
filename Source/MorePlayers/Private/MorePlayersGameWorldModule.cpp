// Copyright 2025 Jesse Hodgson

#include "MorePlayersGameWorldModule.h"

#include "FGAdminInterface.h"
#include "FGGameSession.h"
#include "Engine/World.h"
#include "FGPlayerController.h"
#include "MorePlayers.h"
#include "MPM_ConfigStruct.h"

void UMorePlayersGameWorldModule::Init()
{
	{
	#if WITH_EDITOR
		UE_LOG(LogMorePlayers, Verbose, TEXT("Cannot load config in editor"));
	#else
		ModConfig = FMPM_ConfigStruct::GetActiveConfig(GetWorld());
	#endif
	}

	const int32 ModdedMaxPlayers = ModConfig.ModdedMaxPlayers;

	#if WITH_SERVER_CODE // Server-side code

	if(this->GetWorld()->GetNetMode() != NM_DedicatedServer){

		AFGPlayerController* PlayerController = Cast<AFGPlayerController>(GetWorld()->GetFirstPlayerController());
		if (IsValid(PlayerController))
		{
			PlayerController->GetAdminInterface()->GetGameSession()->MaxPlayers = ModdedMaxPlayers;

			UE_LOG(LogMorePlayers, Verbose, TEXT("Max Players Registered: %d"), PlayerController->GetAdminInterface()->GetGameSession()->MaxPlayers);
		}
		else
		{
			UE_LOG(LogMorePlayers, Verbose, TEXT("Player Controller not valid"));
		}

	}

	#endif // Client-side code
}
