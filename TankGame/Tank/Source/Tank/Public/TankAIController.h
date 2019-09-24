// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tanky.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

private:

	ATanky* GetPlayerTank() const;

	ATanky* PlayerTank = nullptr;

};
