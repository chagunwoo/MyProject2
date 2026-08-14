// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "L_Actor.generated.h"

UCLASS()
class MYPROJECT2_API AL_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AL_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector StartLocation;
	FTimerHandle MoveTimerHandle;
	void RandomMove();
public:	
	virtual void Tick(float DeltaTime) override;

	//메쉬
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	//움직임 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector MovementSpeed;

	//최댓값
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector MaxRange;

	//최솟값
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector minimum;
};
