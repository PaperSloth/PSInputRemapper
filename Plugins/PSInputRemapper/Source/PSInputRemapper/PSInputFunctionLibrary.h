// Copyright(c) 2020 PaperSloth

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputCoreTypes.h"
#include "GameFramework/PlayerInput.h"
#include "PSInputFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum class EPSInputType : uint8
{
	Keyboard,
	Mouse,
	Gamepad,
	KeyboardOrMouse,
};

USTRUCT(BlueprintType)
struct FPSInputWrapper
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PS|Input")
	FString BindName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PS|Input")
	FKey Key;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PS|Input")
	FString KeyAsString;

	FPSInputWrapper(){}
	FPSInputWrapper(const FInputActionKeyMapping& Action)
		: BindName(Action.ActionName.ToString()), Key(Action.Key), KeyAsString(Action.Key.GetDisplayName().ToString())
	{
	}
	FPSInputWrapper(const FString& InBindName, const FKey& InKey)
		: BindName(InBindName), Key(InKey), KeyAsString(InKey.GetDisplayName().ToString())
	{
	}
};

UCLASS()
class PSINPUTREMAPPER_API UPSInputFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	static bool UpdateActionMapping(const FString& ActionName, const FKey& CurrentInputKey, const FKey NewInputKey, const EPSInputType InputType);

public:
	/**
	 * If the update is successful, it will be saved in Saved/Config/Windows/Input.ini.
	 */
	UFUNCTION(BlueprintCallable, Category = "PS|Input")
	static bool UpdateActionMapping(const FString& ActionName, const FKey NewInputKey, const EPSInputType InputType);
	UFUNCTION(BlueprintPure, Category = "PS|Input")
	static void GetAllActionMappingName(TArray<FPSInputWrapper>& InputArray);
	UFUNCTION(BlueprintCallable, Category = "PS|Input")
	static void FindCurrentActionMappings(const FString& ActionName, TArray<FPSInputWrapper>& InputArray);
	UFUNCTION(BlueprintCallable, Category = "PS|Input")
	static void FindCurrentActionMapping(const FString& ActionName, FPSInputWrapper& Input, const EPSInputType InputType);

#if 0
	UFUNCTION(BlueprintCallable, Category = "PS|Input")
		static bool ChangeAxisMapping(const FString& AxisName, const FKey& NewInputKey, const float Scale = 1.0f);
	UFUNCTION(BlueprintPure, Category = "PS|Input")
		static void GetAllAxisMappingName(TArray<FString>& AxisNames);
	UFUNCTION(BlueprintCallable, Category = "PS|Input")
		static void FindCurrentAxisMappings(const FString& AxisName, TArray<FKey>& KeyArray);
#endif
};
