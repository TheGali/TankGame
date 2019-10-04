// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::InitializeComponent(UTankTrack* LeftTracktoSet, UTankTrack* RightTracktoSet)
{
	if (!LeftTracktoSet || !RightTracktoSet) { return;}
	LeftTrack = LeftTracktoSet;
	RightTrack = RightTracktoSet;

}



void UTankMovementComponent::IntendMoveForward(float Throw)
{
	
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward %f "), Throw);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODO prevent double speed overdrive

}