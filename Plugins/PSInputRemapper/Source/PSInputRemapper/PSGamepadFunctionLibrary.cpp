// Copyright(c) 2020 PaperSloth

#include "PSGamepadFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Application/AnalogCursor.h"

bool UPSGamepadFunctionLibrary::EnableGamepadCursor(const UObject* WorldContextObject)
{
	const auto PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if (!PC) return false;

	const TSharedPtr<FAnalogCursor> Cursor = MakeShareable(new FAnalogCursor());
	FSlateApplication::Get().RegisterInputPreProcessor(Cursor);
	GetMutableDefault<UGamePadCursor>()->AnalogCursor = Cursor;

	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	InputMode.SetWidgetToFocus(TSharedPtr<SWidget>());
	PC->SetInputMode(InputMode);

	return true;
}

bool UPSGamepadFunctionLibrary::DisableGamepadCursor(const UObject* WorldContextObject)
{
	const auto PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if (!PC) return false;

	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().UnregisterInputPreProcessor(GetMutableDefault<UGamePadCursor>()->AnalogCursor);
	}

	FInputModeGameOnly InputMode;
	PC->SetInputMode(InputMode);

	return true;
}
