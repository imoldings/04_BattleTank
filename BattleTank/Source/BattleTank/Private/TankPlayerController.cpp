// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller: %s"), *(ControlledTank->GetName()));
	}
}



void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("TICK TICK TICK"));
}

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation; //Out Parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
	}
	
		//If it hits the landscape 
			//Tell the Controlled tank to aim at this point
	
}

//Get world location if linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocation( FVector& HitLocation) const
{
	HitLocation = FVector(1.f);
	return true;
}
