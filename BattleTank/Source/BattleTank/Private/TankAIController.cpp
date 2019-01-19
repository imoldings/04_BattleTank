// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		if (GetPlayerTank())
		{
		
		// TODO Move Toward Player
		// Aim At Player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//Fire if Ready
		}
}

void ATankAIController::BeginPlay( )
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot found Player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Found Player Tank: %s"), *(PlayerTank->GetName()));
	}
}
ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return NULL; }
	return Cast<ATank>(PlayerPawn);
}
