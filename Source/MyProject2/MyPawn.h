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

	UFUNCTION()
	void Move(const FInputActionValue& Value);
	UFUNCTION()
	void StartJump(const FInputActionValue& Value);
	UFUNCTION()
	void Look(const FInputActionValue& Value);

	float CameraPitch = 0.0f;
	float CameraYaw = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Camera")
	float LookSensitivity = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Camera")
	float MinPitch = -80.0f;

	UPROPERTY(EditAnywhere, Category = "Camera")
	float MaxPitch = 80.0f;


	UPROPERTY(EditAnywhere, Category = "Camera")
	float MinYaw = -80.0f;

	UPROPERTY(EditAnywhere, Category = "Camera")
	float MaxYaw = 80.0f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UFloatingPawnMovement* MovementComponent;
	//Ä¸½¶ ÄÄÆ÷³ÍÆ®
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UCapsuleComponent* Capsule;

	//¸Þ½¬
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USkeletalMeshComponent* Mesh;

	//½ºÇÁ¸µ¾Ï
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USpringArmComponent* SpringArm;

	//Ä«¸Þ¶ó
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UCameraComponent* Camera;




};
