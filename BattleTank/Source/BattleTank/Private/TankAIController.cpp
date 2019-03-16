// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		
		// TODO Move Toward Player
		// Aim At Player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//Fire if Ready
		ControlledTank->Fire(); //TODI Dont fire every frame, Limit firing rate.
	}
}

void ATankAIController::BeginPlay( )
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
	
}
