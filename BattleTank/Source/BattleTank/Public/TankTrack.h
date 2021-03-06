// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 *	Set Maximum Applied force and set momentum to the Tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	

	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TankTrackDrivingForce = 400000; //Forty ton tank and 1g acceleration
};
