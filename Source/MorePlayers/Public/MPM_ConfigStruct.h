#pragma once
#include "CoreMinimal.h"
#include "Configuration/ConfigManager.h"
#include "Engine/Engine.h"
#include "MPM_ConfigStruct.generated.h"

/* Struct generated from Mod Configuration Asset '/MorePlayers/MPM_Config' */
USTRUCT(BlueprintType)
struct FMPM_ConfigStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    int32 ModdedMaxPlayers{};

    /* Retrieves active configuration value and returns object of this struct containing it */
    static FMPM_ConfigStruct GetActiveConfig(UObject* WorldContext) {
        FMPM_ConfigStruct ConfigStruct{};
        FConfigId ConfigId{"MorePlayers", ""};
        if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContext, EGetWorldErrorMode::ReturnNull)) {
            UConfigManager* ConfigManager = World->GetGameInstance()->GetSubsystem<UConfigManager>();
            ConfigManager->FillConfigurationStruct(ConfigId, FDynamicStructInfo{FMPM_ConfigStruct::StaticStruct(), &ConfigStruct});
        }
        return ConfigStruct;
    }
};

