// Copyright(c) 2020 PaperSloth

#include "PSInputFunctionLibrary.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"

void UPSInputFunctionLibrary::ChangeMapping(const UObject* WorldContextObject, const FName& BindName, const FKey& Key, const EBindType BindType, const int PlayerIndex)
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

void UPSInputFunctionLibrary::ChangeActionMapping(const UObject* WorldContextObject, const FName& ActionName, const FKey& Key, const int PlayerIndex)
{
	const APlayerController* const PC = UGameplayStatics::GetPlayerController(WorldContextObject, PlayerIndex);
	UPlayerInput* const PlayerInput = PC->PlayerInput;
	PlayerInput->ActionMappings.RemoveAll([&ActionName](const FInputActionKeyMapping& NowMapping)
	{
		return (NowMapping.ActionName == ActionName);
	});

	const FInputActionKeyMapping AddMapping(ActionName, Key);
	PlayerInput->AddActionMapping(AddMapping);
}

void UPSInputFunctionLibrary::ChangeAxisMapping(const UObject* WorldContextObject, const FName& AxisName, const FKey& Key, int PlayerIndex)
{
	const APlayerController* const PC = UGameplayStatics::GetPlayerController(WorldContextObject, PlayerIndex);
	UPlayerInput* const PlayerInput = PC->PlayerInput;
	PlayerInput->AxisMappings.RemoveAll([&AxisName](const FInputAxisKeyMapping& NowMapping)
	{
		return (NowMapping.AxisName == AxisName);
	});

	const FInputAxisKeyMapping AddMapping(AxisName, Key);
	PlayerInput->AddAxisMapping(AddMapping);
}

void UPSInputFunctionLibrary::GetAllActionMappingNames(TArray<FName>& MappingNames)
{
	MappingNames.Empty();

	const UInputSettings* Settings = GetDefault<UInputSettings>();
	for (const FInputActionKeyMapping& Action : Settings->GetActionMappings())
	{
		MappingNames.Emplace(Action.ActionName);
	}
}

void UPSInputFunctionLibrary::GetAllAxisMappingNames(TArray<FName>& AxisNames)
{
	AxisNames.Empty();

	const UInputSettings* Settings = GetDefault<UInputSettings>();
	for (const FInputAxisKeyMapping& Axis : Settings->GetAxisMappings())
	{
		AxisNames.Emplace(Axis.AxisName);
	}
}
