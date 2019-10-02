// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Tanky.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
   

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast <ATanky>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATanky>(GetPawn());
	if (PlayerTank)
	{
		// Move towards player

		
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		
		ControlledTank->Fire();
	}
}






