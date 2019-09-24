// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
	
}

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

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation; // Out Paramater
	UE_LOG(LogTemp, Warning, TEXT("Hit Location : %s"), *HitLocation.ToString());

	//Get world location of line trace through through crosshair
	//if it hits the landscape
		//tell controlled tank to aim at this point


}