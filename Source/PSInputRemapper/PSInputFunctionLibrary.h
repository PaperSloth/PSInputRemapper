// Copyright(c) 2020 PaperSloth

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PSInputFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum class EBindType : uint8
{
	Action,
	Axis,
};

UCLASS()
class PSINPUTREMAPPER_API UPSInputFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "PS|Input", meta = (WorldContext = "WorldContextObject", AdvancedDisplay = "PlayerIndex"))
	static void ChangeMapping(const UObject* WorldContextObject, const FName& BindName, const FKey& Key, EBindType const BindType, const int32 PlayerIndex = 0);
	UFUNCTION(BlueprintCallable, Category = "PS|Input", meta = (WorldContext = "WorldContextObject", AdvancedDisplay = "PlayerIndex"))
	static void ChangeActionMapping(const UObject* WorldContextObject, const FName& ActionName, const FKey& Key, const int32 PlayerIndex = 0);
	UFUNCTION(BlueprintCallable, Category = "PS|Input", meta = (WorldContext = "WorldContextObject", AdvancedDisplay = "PlayerIndex"))
	static void ChangeAxisMapping(const UObject* WorldContextObject, const FName& AxisName, const FKey& Key, const float Scale = 1.0f, const int32 PlayerIndex = 0);

	UFUNCTION(BlueprintCallable, Category = "PS|Input")
	static void GetAllActionMappingNames(TArray<FName>& ActionNames);
	UFUNCTION(BlueprintCallable, Category = "PS|Input")
	static void GetAllAxisMappingNames(TArray<FName>& AxisNames);
};
