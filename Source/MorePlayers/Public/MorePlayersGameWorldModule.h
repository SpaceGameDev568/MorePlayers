// Copyright 2025 Jesse Hodgson

#pragma once

#include "CoreMinimal.h"
#include "MPM_ConfigStruct.h"
#include "Module/GameWorldModule.h"
#include "MorePlayersGameWorldModule.generated.h"

/**
 * 
 */
UCLASS()
class MOREPLAYERS_API UMorePlayersGameWorldModule : public UGameWorldModule
{
	GENERATED_BODY()

public:

	FMPM_ConfigStruct ModConfig;

	UFUNCTION(BlueprintCallable)
	void Init();
	
};
