// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController not possessing a tank "));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possessing: %s"),*(ControlledTank->GetName()));
	}
	
}

ATanky* ATankPlayerController::GetControlledTank() const
{
	
	return Cast<ATanky>(GetPawn());
}