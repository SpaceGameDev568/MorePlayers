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

	int32 ModdedMaxPlayers = ModConfig.ModdedMaxPlayers;

	#if WITH_SERVER_CODE // Server-side code

		//UCLASS(notplaceable)
		//class FACTORYGAME_API AFGAdminInterface : public AInfo
		//{
		//	GENERATED_BODY()
		//
		//	friend class UMorePlayersGameWorldModule;

		// IF THIS ERRORS IN NEWER VERSIONS, ADD 'friend class UMorePlayersGameWorldModule;' TO THE AREA ABOVE ON FGAdminInterface.h

		AFGPlayerController* PlayerController = Cast<AFGPlayerController>(GetWorld()->GetFirstPlayerController());
		PlayerController->GetAdminInterface()->GetGameSession()->MaxPlayers = ModdedMaxPlayers;

		UE_LOG(LogMorePlayers, Verbose, TEXT("Max Players Registered: %d"), PlayerController->GetAdminInterface()->GetGameSession()->MaxPlayers);

	#endif // Client-side code
}
