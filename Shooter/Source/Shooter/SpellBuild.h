// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "PawnBuilding.h"
#include "SpellBuild.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Spell), BlueprintType, meta = (BlueprintSpawnableComponent))
class SHOOTER_API USpellBuild : public USpell
{
	GENERATED_BODY()
	
public:
	// Sets default values for this component's properties
	USpellBuild();
	
	UPROPERTY(Category = "Spell|Spawn", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<APawnBuilding> BuildingToBuild;
	
protected:
	virtual void Casted_Implementation(APawn* caster, USceneComponent* castingComponent) override;
	
	
};
