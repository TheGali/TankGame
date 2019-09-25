// Fill out your copyright notice in the Description page of Project Settings.


#include "Tanky.h"

void ATanky::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

// Sets default values
ATanky::ATanky()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//No need to protect point as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName ("Aiming Component"));

}

// Called when the game starts or when spawned
void ATanky::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATanky::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATanky::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATanky::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation);
	
}
