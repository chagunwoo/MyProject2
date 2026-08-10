// Fill out your copyright notice in the Description page of Project Settings.


#include "L_Actor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AL_Actor::AL_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	MovementSpeed = FVector(100.0f, 0.0f, 0.0f);
	MaxRange = FVector(500.0f, 500.0f, 500.0f);
	minimum = FVector(-500.0f, -500.0f, -500.0f);
}

// Called when the game starts or when spawned
void AL_Actor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void AL_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorLocation().X >= MaxRange.X + StartLocation.X or GetActorLocation().X <= minimum.X + StartLocation.X)
	{
		MovementSpeed.X *= -1;
	}
	if (GetActorLocation().Y >= MaxRange.Y + StartLocation.Y or GetActorLocation().Y <= minimum.Y + StartLocation.Y)
	{
		MovementSpeed.Y *= -1;
	}
	if (GetActorLocation().Z >= MaxRange.Z + StartLocation.Z or GetActorLocation().Z <= minimum.Z + StartLocation.Z)
	{
		MovementSpeed.Z *= -1;
	}
	SetActorLocation(GetActorLocation() + MovementSpeed * DeltaTime);

}

