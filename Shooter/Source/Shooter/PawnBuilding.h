// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnShooter.h"
#include "PawnBuilding.generated.h"

/** PawnBuilding is the base class of all building pawns in a Shooter game */
UCLASS(BlueprintType, Blueprintable, meta = (ShortTooltip = "A PawnBuilding is a pawn that acts as a building for a Shooter game."))
class SHOOTER_API APawnBuilding : public APawnShooter
{
	GENERATED_BODY()
			
// Public Constructors
public:	

	/** Sets default values and links some components */
	APawnBuilding();

// Protected Initializers
protected:

	/** Initialises the building collision properties */
	UFUNCTION(Category = "Building|Construction", BlueprintCallable, meta = (DefaultToSelf))
	void InitBuildingCollision();

// Public Commands
public:

	/** 
	  * Adds a directional command
	  * @param input Directional command to add 
	  */
	UFUNCTION(Category = "Movement", BlueprintCallable)
	virtual void AddInputVector(const FVector& input) override;

	/** 
	  * Adds a rotation command (as controller's input)
	  * @param input Rotation command to add
	  */
	UFUNCTION(Category = "Movement", BlueprintCallable)
	virtual void AddInputRotationVector(const FVector2D& input) override;

	/** 
	  * Adds a rotation command (as world forward)
	  * @param input Rotation command to add
	  */
	UFUNCTION(Category = "Movement", BlueprintCallable)
	virtual void AddInputForwardVector(const FVector2D& input) override; 

};
