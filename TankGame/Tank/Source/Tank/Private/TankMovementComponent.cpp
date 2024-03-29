// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "Math/Vector.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::InitializeComponent(UTankTrack* LeftTracktoSet, UTankTrack* RightTracktoSet)
{
	
	LeftTrack = LeftTracktoSet;
	RightTrack = RightTracktoSet;

}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call super as we're replacing the functionality

	auto TankForward = GetOwner()->GetActorForwardVector.GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	
	IntendMoveForward(ForwardThrow);

	//UE_LOG(LogTemp, Warning, TEXT("Forward Throw is : %s"), ForwardThrow);

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	
	//TODO prevent double speed overdrive

}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	//TODO prevent double speed overdrive

}