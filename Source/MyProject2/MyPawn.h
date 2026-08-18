// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyPawn.generated.h"

class UFloatingPawnMovement;
struct FInputActionValue;



UCLASS()
class MYPROJECT2_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//이동
	UFUNCTION()
	void Move(const FInputActionValue& Value);

	//점프
	UFUNCTION()
	void StartJump(const FInputActionValue& Value);

	//카메라이동 
	UFUNCTION()
	void Look(const FInputActionValue& Value);

	float CameraPitch = 0.0f;
	float CameraYaw = 0.0f;

	//카메라이동감도
	UPROPERTY(EditAnywhere, Category = "Camera")
	float LookSensitivity = 1.0f;
	
	//최소 Pitch값
	UPROPERTY(EditAnywhere, Category = "Camera")
	float MinPitch = -80.0f;

	//최대 Pitch값
	UPROPERTY(EditAnywhere, Category = "Camera")
	float MaxPitch = 80.0f;

	//최소 Yaw값
	UPROPERTY(EditAnywhere, Category = "Camera")
	float MinYaw = -80.0f;

	//최대 Yaw값
	UPROPERTY(EditAnywhere, Category = "Camera")
	float MaxYaw = 80.0f;
public:	
	virtual void Tick(float DeltaTime) override;

	//무브먼트 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UFloatingPawnMovement* MovementComponent;
	//캡슐 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UCapsuleComponent* Capsule;

	//메쉬
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USkeletalMeshComponent* Mesh;

	//스프링암
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USpringArmComponent* SpringArm;

	//카메라
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UCameraComponent* Camera;




};
