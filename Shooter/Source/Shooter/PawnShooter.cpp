// Ascii banners made with Bagill's ASCII Signature Generator using the Font: "Small" (width:53)

// ___________________________________________________ //
//           ___         _         _                   //
//          |_ _|_ _  __| |_  _ __| |___ ___           //
//           | || ' \/ _| | || / _` / -_|_-<           //
//          |___|_||_\__|_|\_,_\__,_\___/__/           //
// ___________________________________________________ //

#include "PawnShooter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "Engine.h"
#include "Engine/World.h"
#include "DamageTypeExplosion.h"
#include "Shooter.h"

// ___________________________________________________ //
//   ___             _               _                 //
//  / __|___ _ _  __| |_ _ _ _  _ __| |_ ___ _ _ ___   //
// | (__/ _ \ ' \(_-<  _| '_| || / _|  _/ _ \ '_(_-<   //
//  \___\___/_||_/__/\__|_|  \_,_\__|\__\___/_| /__/   //
// ___________________________________________________ //

// Sets default values
APawnShooter::APawnShooter()
{
	this->MaxHealth = this->Health = 100;
	this->ExplosionDamage = 100;
	this->ExplosionRange = 1000;
	this->bCanExplode = false;
	this->TeamID = MONSTER_TEAM;
	this->bIsGodMode = false;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// ___________________________________________________ //
//              ___             _                      //
//             | __|_ _____ _ _| |_ ___                //
//             | _|\ V / -_) ' \  _(_-<                //
//             |___|\_/\___|_||_\__/__/                //
// ___________________________________________________ //

// Called when the game starts or when spawned
void APawnShooter::BeginPlay()
{
	Super::BeginPlay();

	this->Health = this->MaxHealth;

}

float APawnShooter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if(!this->bIsGodMode)
		this->Health -= Damage;
	
	if (this->Health <= 0)
		this->Destroy();

	return Damage;
}

// Called every frame
void APawnShooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// ___________________________________________________ //
//              ___     _   _                          //
//             / __|___| |_| |_ ___ _ _ ___            //
//            | (_ / -_)  _|  _/ -_) '_(_-<            //
//             \___\___|\__|\__\___|_| /__/            //
// ___________________________________________________ //

int32 APawnShooter::GetTeamID() const
{
	return this->TeamID;
}

TArray<APawnShooter*> APawnShooter::GetPlayerPawnsInRange(float range) const
{
	TArray<APawnShooter*> retval = TArray<APawnShooter*>();

	const UWorld* const world = this->GetWorld();
	if (world == nullptr)
	{
		return retval;
	}

	APawn* pawn;
	APawnShooter* ship;
	float distance;

	for (FConstPawnIterator itPawn = world->GetPawnIterator(); itPawn; ++itPawn)
	{
		pawn = itPawn->Get();
		if (pawn != nullptr)
		{
			ship = Cast<APawnShooter>(pawn);
			if (ship != nullptr && !IS_MONSTER_TEAM(ship->GetTeamID()))
			{
				distance = this->GetDistanceTo(ship);

				if (distance < range)
				{
					retval.Add(ship);
				}
			}
		}
	}

	return retval;
}

int32 APawnShooter::GetCurrentHealth() const
{
	return this->Health;
}

int32 APawnShooter::GetMaxHealth() const
{
	return this->MaxHealth;
}

float APawnShooter::GetPercentHealth() const
{
	return (float)this->Health / this->MaxHealth;
}

// ___________________________________________________ //
//             ___      _   _                          //
//            / __| ___| |_| |_ ___ _ _ ___            //
//            \__ \/ -_)  _|  _/ -_) '_(_-<            //
//            |___/\___|\__|\__\___|_| /__/            //
// ___________________________________________________ //

void APawnShooter::SetTeamID(int32 teamID)
{
	this->TeamID = teamID;
}

// ___________________________________________________ //
//        ___                              _           //
//       / __|___ _ __  _ __  __ _ _ _  __| |___       //
//      | (__/ _ \ '  \| '  \/ _` | ' \/ _` (_-<       //
//       \___\___/_|_|_|_|_|_\__,_|_||_\__,_/__/       //
// ___________________________________________________ //

void APawnShooter::Explode()
{
	if (this->bCanExplode)
	{
		TArray<AActor*> actorsToIgnore = TArray<AActor*>();
		actorsToIgnore.Add(this);

		bool hasDamagedSomeone = UGameplayStatics::ApplyRadialDamage(this,
			this->ExplosionDamage, this->GetActorLocation(), this->ExplosionRange,
			TSubclassOf<UDamageType>(UDamageTypeExplosion::StaticClass()),
			actorsToIgnore, this, NULL,
			false, ECollisionChannel::ECC_Visibility);

		this->Destroy();
	}
}