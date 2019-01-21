// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Tank.h"
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
		GetControlledTank()->AimAt(HitLocation);
	}
	
		//If it hits the landscape 
			//Tell the Controlled tank to aim at this point
	
}

//Get world location if linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocation( FVector& HitLocation) const
{
	///find cross hair position in pixels
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
	
	//UE_LOG(LogTemp, Warning, TEXT("Screen Location: %s"), *ScreenLocation.ToString());
	FVector LookDirection;
	// deproject value from 2d screen into 3d world location
	if (GetHitDirection(ScreenLocation, LookDirection))
	{
		///Line trace along lookDirection to see what we hit
		GetLookHitVectorHitLocation(LookDirection, HitLocation);

	}
	

	return true;
}
bool ATankPlayerController::GetLookHitVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto Startlocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = Startlocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			Startlocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility
			))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

bool ATankPlayerController::GetHitDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}



	

