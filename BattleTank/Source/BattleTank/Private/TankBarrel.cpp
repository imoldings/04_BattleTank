// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{

	// Move the barrel the right amount of this frame.
	// Given a max elevation speed and frame time.

	UE_LOG(LogTemp, Warning, TEXT("BArrel Elevates now in %f seconds"), DegreesPerSecond);

}