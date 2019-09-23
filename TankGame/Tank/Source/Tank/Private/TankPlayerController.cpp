// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATanky* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATanky>(GetPawn());
}