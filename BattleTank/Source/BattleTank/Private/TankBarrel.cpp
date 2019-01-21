// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{

	// Move the barrel the right amount of this frame.
	// Given a max elevation speed and frame time.
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	auto ElevationSpeed = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationSpeed;

	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation, 0.f, 0.f));
}