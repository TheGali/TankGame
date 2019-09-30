// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Tanky.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
    auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not finding player tank "));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController aimin at %s"), *(GetPlayerTank()->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// Move towards player

		// Aim towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready
	}
}




ATanky* ATankAIController::GetPlayerTank() const
{
	return Cast <ATanky>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

ATanky* ATankAIController::GetControlledTank() const
{

	return Cast<ATanky>(GetPawn());
}