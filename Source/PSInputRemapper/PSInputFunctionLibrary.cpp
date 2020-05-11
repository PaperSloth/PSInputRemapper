// Copyright(c) 2020 PaperSloth

#include "PSInputFunctionLibrary.h"
#include "UObject/UObjectIterator.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetInputLibrary.h"

bool UPSInputFunctionLibrary::ChangeActionMapping(const FString& ActionName, const FKey& CurrentInputKey, const FKey NewInputKey, const EPSInputType InputType)
{
	const UInputSettings* Settings = GetDefault<UInputSettings>();
	if (!Settings) return false;

	bool isUpdate = false;
	for (const auto& Action : Settings->GetActionMappings())
	{
		if (Action.ActionName.ToString() != ActionName || Action.Key != CurrentInputKey)
		{
			continue;
		}
		switch (InputType)
		{
		case EPSInputType::Keyboard:
			isUpdate = (UKismetInputLibrary::Key_IsKeyboardKey(CurrentInputKey) && UKismetInputLibrary::Key_IsKeyboardKey(NewInputKey));
			break;
		case EPSInputType::Mouse:
			isUpdate = (CurrentInputKey.IsMouseButton() && NewInputKey.IsMouseButton());
			break;
		case EPSInputType::KeyboardOrMouse:
			isUpdate = (!CurrentInputKey.IsGamepadKey() && !NewInputKey.IsGamepadKey());
			break;
		case EPSInputType::Gamepad:
			isUpdate = (CurrentInputKey.IsGamepadKey() && NewInputKey.IsGamepadKey());
			break;
		}
		if (isUpdate)
		{
			const_cast<FKey&>(Action.Key) = NewInputKey;
			break;
		}
	}
	if (isUpdate)
	{
		const_cast<UInputSettings*>(Settings)->SaveKeyMappings();
		for (TObjectIterator<UPlayerInput> It; It; ++It)
		{
			It->ForceRebuildingKeyMaps(true);
		}
	}
	return isUpdate;
}

void UPSInputFunctionLibrary::GetAllActionMappingName(TArray<FPSInputWrapper>& InputArray)
{
	const UInputSettings* Settings = GetDefault<UInputSettings>();
	if (!Settings) return;

	InputArray.Empty();
	for (const auto& Action : Settings->GetActionMappings())
	{
		InputArray.Emplace(FPSInputWrapper(Action.ActionName.ToString(), Action.Key));
	}
}

void UPSInputFunctionLibrary::FindCurrentActionMappings(const FString& ActionName, TArray<FPSInputWrapper>& InputArray)
{
	const UInputSettings* Settings = GetDefault<UInputSettings>();
	if (!Settings) return;

	InputArray.Empty();
	for (const auto& Action : Settings->GetActionMappings())
	{
		const FString& ActionName = Action.ActionName.ToString();
		if (ActionName == ActionName)
		{
			InputArray.Emplace(FPSInputWrapper(ActionName, Action.Key));
		}
	}
}

#if 0
bool UPSInputFunctionLibrary::ChangeAxisMapping(const FString& AxisName, const FKey& NewInputKey, const float Scale)
{
	const UInputSettings* Settings = GetDefault<UInputSettings>();
	if (!Settings) return false;

	bool isUpdate = false;
	for (const auto& Axis : Settings->GetAxisMappings())
	{
		if (Axis.AxisName.ToString() == AxisName)
		{
			const_cast<FKey&>(Axis.Key) = NewInputKey;
			const_cast<float&>(Axis.Scale) = Scale;
			isUpdate = true;
			break;
		}
	}
	if (isUpdate)
	{
		const_cast<UInputSettings*>(Settings)->SaveKeyMappings();
		for (TObjectIterator<UPlayerInput> It; It; ++It)
		{
			It->ForceRebuildingKeyMaps(true);
		}
	}
	return isUpdate;
}

void UPSInputFunctionLibrary::GetAllAxisMappingName(TArray<FString>& AxisNames)
{
	const UInputSettings* Settings = GetDefault<UInputSettings>();
	if (!Settings) return;

	AxisNames.Empty();
	for (const auto& Axis : Settings->GetAxisMappings())
	{
		AxisNames.Emplace(Axis.AxisName.ToString());
	}
}

void UPSInputFunctionLibrary::FindCurrentAxisMappings(const FString& AxisName, TArray<FKey>& KeyArray)
{
	const UInputSettings* Settings = GetDefault<UInputSettings>();
	if (!Settings) return;

	KeyArray.Empty();
	for (const auto& Axis : Settings->GetAxisMappings())
	{
		if (Axis.AxisName.ToString() == AxisName)
		{
			KeyArray.Emplace(Axis.Key);
		}
	}
}
#endif
