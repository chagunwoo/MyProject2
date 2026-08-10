// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomSpwaner.h"

// Sets default values
ARandomSpwaner::ARandomSpwaner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARandomSpwaner::BeginPlay()
{
	Super::BeginPlay();

	if (ActorToSpawn == nullptr)
	{
		return;
	}

    for (int i = 0; i < SpawnCount; i++)
    {
        float RandomX = FMath::RandRange(-SpawnRange, SpawnRange);
        float RandomY = FMath::RandRange(-SpawnRange, SpawnRange);

        FVector SpawnLocation =
            GetActorLocation() +
            FVector(RandomX, RandomY, 0.0f);

        FRotator SpawnRotation =
            FRotator(0.0f, 0.0f, 0.0f);

        GetWorld()->SpawnActor<AActor>(
            ActorToSpawn,
            SpawnLocation,
            SpawnRotation
        );
    }

}

// Called every frame
void ARandomSpwaner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

