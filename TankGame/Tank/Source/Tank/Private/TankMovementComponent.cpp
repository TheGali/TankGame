// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::InitializeComponent(UTankTrack* LeftTracktoSet, UTankTrack* RightTracktoSet)
{
	
	LeftTrack = LeftTracktoSet;
	RightTrack = RightTracktoSet;

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