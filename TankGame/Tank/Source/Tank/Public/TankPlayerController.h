// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tanky.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATanky* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//Start the tank moving the barrel so that a shot would hit where
	//the crosshair intersects the world
	void AimTowardsCrossHair();
	
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333;

	bool GetLookDirection(FVector2D ScreenLoaction, FVector& LookDirection) const;
};
