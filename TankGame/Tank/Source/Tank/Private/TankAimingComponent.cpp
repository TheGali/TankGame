// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Vector.h"
#include "Math/Rotator.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; //TODO Should this really tick?

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector StartLocation = Barrel->GetSocketLocation(FName ("Projectile"));
	FVector OutLaunchVelocity(0);
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false, 0, 0,
		ESuggestProjVelocityTraceOption::DoNotTrace  // Must have all parameters to avoid bug
		);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		auto  Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f Aim solution found"), Time);
	}
	else
	{
		auto  Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f No aim solve found"), Time);
	}

	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation(); 
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	

	Barrel->Elevate(DeltaRotator.Pitch); 
	Turret->Rotate(DeltaRotator.Yaw);
}