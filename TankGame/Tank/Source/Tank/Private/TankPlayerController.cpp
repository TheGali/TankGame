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
	
	FVector OutHitLocation; // Out Paramater
	if (GetSightRayHitLocation(OutHitLocation)) // has "side effect", is goin to line trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction : %s"), *OutHitLocation.ToString());
		// TODO tell controlled tank to aim at this point
	}
}

//Get world location of line trace through through crosshair , True if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	


	// "De-project" the screen position of the crosshair to a world direction
	FVector CameraWorldLocation;
	FVector WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction : %s"), *WorldDirection.ToString());
	}




	//Line-trace along that look direction, and see what we hit (up to max)
	return true;
}