// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATanky;

/**
 * 
 */
UCLASS()
class TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// How close can AI Tank get?
	float AcceptanceRadius = 300;

};
