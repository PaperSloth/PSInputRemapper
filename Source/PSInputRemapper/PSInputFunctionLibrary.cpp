// Copyright(c) 2020 PaperSloth

#include "PSInputFunctionLibrary.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"

void UPSInputFunctionLibrary::ChangeMapping(const UObject* WorldContextObject, const FName& BindName, const FKey& Key, const EBindType BindType, const int32 PlayerIndex)
{
	switch (BindType)
	{
	case EBindType::Action:
		ChangeActionMapping(WorldContextObject, BindName, Key, PlayerIndex);
		break;
	case EBindType::Axis:
		ChangeAxisMapping(WorldContextObject, BindName, Key, PlayerIndex);
		break;
	}
}

void UPSInputFunctionLibrary::ChangeActionMapping(const UObject* WorldContextObject, const FName& ActionName, const FKey& Key, const int32 PlayerIndex)
{
	const APlayerController* const PC = UGameplayStatics::GetPlayerController(WorldContextObject, PlayerIndex);
	if (!PC || !PC->PlayerInput) return;
	UPlayerInput* const PlayerInput = PC->PlayerInput;
	PlayerInput->ActionMappings.RemoveAll([&ActionName](const FInputActionKeyMapping& NowMapping)
	{
		return (NowMapping.ActionName == ActionName);
	});

	const FInputActionKeyMapping AddMapping(ActionName, Key);
	PlayerInput->AddActionMapping(AddMapping);
}

void UPSInputFunctionLibrary::ChangeAxisMapping(const UObject* WorldContextObject, const FName& AxisName, const FKey& Key, const float Scale, int32 PlayerIndex)
{
	const APlayerController* const PC = UGameplayStatics::GetPlayerController(WorldContextObject, PlayerIndex);
	if (!PC || !PC->PlayerInput) return;
	UPlayerInput* const PlayerInput = PC->PlayerInput;
	PlayerInput->AxisMappings.RemoveAll([&AxisName](const FInputAxisKeyMapping& NowMapping)
	{
		return (NowMapping.AxisName == AxisName);
	});

	const FInputAxisKeyMapping AddMapping(AxisName, Key, Scale);
	PlayerInput->AddAxisMapping(AddMapping);
}

void UPSInputFunctionLibrary::GetAllActionMappingNames(TArray<FName>& ActionNames)
{
	const UInputSettings* Settings = GetDefault<UInputSettings>();
	if (!Settings) return;

	ActionNames.Empty();
	for (const FInputActionKeyMapping& Action : Settings->GetActionMappings())
	{
		ActionNames.Emplace(Action.ActionName);
	}
}

void UPSInputFunctionLibrary::GetAllAxisMappingNames(TArray<FName>& AxisNames)
{
	const UInputSettings* Settings = GetDefault<UInputSettings>();
	if (!Settings) return;

	AxisNames.Empty();
	for (const FInputAxisKeyMapping& Axis : Settings->GetAxisMappings())
	{
		AxisNames.Emplace(Axis.AxisName);
	}
}
