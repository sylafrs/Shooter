// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnShooter.h"
#include "PawnBuilding.h"
#include "Engine/GameInstance.h"
#include "GameInstanceShooter.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class SHOOTER_API UGameInstanceShooter : public UGameInstance
{
	GENERATED_BODY()
	
private:

	TArray<TArray<APawnShooter*>> TeamUnits;
	TArray<TArray<APawnShooter*>> Enemies;
	TArray<APawnShooter*> Players;
	TArray<APawnShooter*> Monsters;
	TArray<APawnBuilding*> Buildings;

public:

	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Category = "Units", BlueprintPure)
	const TArray<APawnShooter*> GetAllies(int32 teamID) const;

	UFUNCTION(BlueprintCallable, Category = "Units", BlueprintPure)
	const TArray<APawnShooter*> GetEnemies(int32 teamID) const;

	UFUNCTION(BlueprintCallable, Category = "Units", BlueprintPure)
	const TArray<APawnShooter*> GetPlayers() const;

	UFUNCTION(BlueprintCallable, Category = "Units", BlueprintPure)
	const TArray<APawnShooter*> GetMonsters() const;

	UFUNCTION(BlueprintCallable, Category = "Units", BlueprintPure)
	const TArray<APawnBuilding*> GetBuildings() const;
	
	UFUNCTION(BlueprintCallable, Category = "Teams")
	void AddTeamUnit(APawnShooter* unit);

	UFUNCTION(BlueprintCallable, Category = "Teams")
	void RemoveTeamUnit(APawnShooter* unit);
	
	
};
