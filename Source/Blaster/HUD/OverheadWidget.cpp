// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn)
{
    const APlayerState* PlayerState = InPawn->GetPlayerState();
    if (!PlayerState || !*PlayerState->GetPlayerName() && TotalTime < PlayerNameTimeout)
    {
        FTimerHandle PlayerStateTimer;
        FTimerDelegate TryAgainDelegate;
        TryAgainDelegate.BindUFunction(this, FName("ShowPlayerName"), InPawn);
        GetWorld()->GetTimerManager().SetTimer(PlayerStateTimer, TryAgainDelegate, PlayerNameInterval, false, 0.1f);
        TotalTime += PlayerNameInterval;
        return;
    }
    const FString PlayerName = InPawn->GetPlayerState()->GetPlayerName();
    SetDisplayText(PlayerName);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
