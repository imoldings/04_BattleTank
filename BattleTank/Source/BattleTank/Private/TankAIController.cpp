// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	auto PlayerTank = GetAIController();

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

ATank * ATankAIController::GetAIController() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return NULL; }
	return Cast<ATank>(PlayerPawn);
}
