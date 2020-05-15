// Copyright(c) 2020 PaperSloth

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PSGamepadFunctionLibrary.generated.h"

UCLASS()
class UGamePadCursor : public UObject
{
	GENERATED_BODY()

public:
	TSharedPtr<class FAnalogCursor> AnalogCursor;
};

UCLASS()
class PSINPUTREMAPPER_API UPSGamepadFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	* Enable the mouse cursor operation on the Gamepad.
	*/
	UFUNCTION(BlueprintCallable, Category = "PS|Input|Gamepad", meta = (WorldContext = WorldContextObject))
	static bool EnableGamepadCursor(const UObject* WorldContextObject);
	/**
	* Disable the mouse cursor operation on the Gamepad.
	*/
	UFUNCTION(BlueprintCallable, Category = "PS|Input|Gamepad", meta = (WorldContext = WorldContextObject))
	static bool DisableGamepadCursor(const UObject* WorldContextObject);
};
