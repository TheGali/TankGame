// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "Tank.h"
#include "Tanky.h"

void ATanky::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATanky::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

// Sets default values
ATanky::ATanky()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No need to protect point as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName ("Aiming Component"));

}

// Called when the game starts or when spawned
void ATanky::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called to bind functionality to input
void ATanky::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATanky::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	
}
