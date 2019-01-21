// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
public:
	ATank* GetControlledTank() const;

	

	virtual void Tick(float DeltaTime) override;

	void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;

	GENERATED_BODY()
	
private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetHitDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookHitVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
