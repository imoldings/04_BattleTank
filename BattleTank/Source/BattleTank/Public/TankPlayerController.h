// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
public:
	ATank* GetControlledTank() const;

	

	virtual void Tick(float DeltaTime) override;

	void BeginPlay() override;

	GENERATED_BODY()
	
private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
