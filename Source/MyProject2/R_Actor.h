// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "R_Actor.generated.h"

UCLASS()
class MYPROJECT2_API AR_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	//생성자
	AR_Actor();

protected:
	//플레이 시작시 이벤트
	virtual void BeginPlay() override;

public:	
	//프레임마다 호출
	virtual void Tick(float DeltaTime) override;

	//메쉬 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	//회전값
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	FRotator RotationSpeed;


};
