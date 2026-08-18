// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomSpwaner.generated.h"

UCLASS()
class MYPROJECT2_API ARandomSpwaner : public AActor
{
	GENERATED_BODY()
	
public:	
	// 생성자
	ARandomSpwaner();

protected:
	// 시작시 호출
	virtual void BeginPlay() override;

public:	
	// 프레임마다 호출
	virtual void Tick(float DeltaTime) override;

	//스폰할 액터 지정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spwan")
	TSubclassOf<AActor> ActorToSpawn;



	//얼마나 스폰할지 지정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spwan")
	int SpawnCount = 5;


	//범위 지정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spwan")
	float SpawnRange = 1000.0f;

};
