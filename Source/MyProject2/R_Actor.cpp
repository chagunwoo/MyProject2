// Fill out your copyright notice in the Description page of Project Settings.


#include "R_Actor.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AR_Actor::AR_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	RotationSpeed = FRotator(0.0f, 90.0f, 0.0f);
}

// Called when the game starts or when spawned
void AR_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AR_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(RotationSpeed * DeltaTime);


}

