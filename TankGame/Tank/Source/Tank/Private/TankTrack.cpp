// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	


	//TODO Clamp Throttle

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);
}