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
	ATanky* ControlledTank = nullptr;


public:
	ATanky* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	

};
