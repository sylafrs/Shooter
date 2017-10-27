// Fill out your copyright notice in the Description page of Project Settings.

#include "SpellBuild.h"
#include "PawnBuilding.h"
#include "Runtime/Engine/Classes/Engine/World.h"

USpellBuild::USpellBuild() : USpell()
{

}

void USpellBuild::Casted_Implementation(APawn* caster, USceneComponent* castingComponent)
{
	if (this->BuildingToBuild == nullptr)
		return;

	UWorld* world = caster->GetWorld();

	FActorSpawnParameters spawnParams = FActorSpawnParameters();
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	APawnBuilding* spawnBuilding = world->SpawnActor<APawnBuilding>(
		this->BuildingToBuild,
		castingComponent->GetComponentLocation(),
		caster->GetActorRotation(),
		spawnParams);
	
}



