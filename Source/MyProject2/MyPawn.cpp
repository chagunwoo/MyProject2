// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "EnhancedInputComponent.h"
#include "MyPlayerController.h"
// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;
	
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	Mesh->SetupAttachment(Capsule);
	Mesh->SetSimulatePhysics(false);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUsePawnControlRotation = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	MovementComponent =
		CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));

	MovementComponent->SetUpdatedComponent(Capsule);
	MovementComponent->MaxSpeed = 600.0f;
}



// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetController()))
		{
			if (PlayerController->Move)
			{
				EnhancedInput->BindAction(
					PlayerController->Move, ETriggerEvent::Triggered, this, &AMyPawn::Move
				);
			}

			if (PlayerController->Jump)
			{
				EnhancedInput->BindAction(
					PlayerController->Jump, ETriggerEvent::Triggered, this, &AMyPawn::StartJump
				);
			}

			if (PlayerController->Look)
			{
				EnhancedInput->BindAction(
					PlayerController->Look , ETriggerEvent::Triggered, this, &AMyPawn::Look

				);
			}

		}


	}
}

void AMyPawn::Move(const FInputActionValue& Value)
{
	if (!Controller) return;

	const FVector2D MoveInput = Value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		AddMovementInput(GetActorForwardVector(),MoveInput.X);
	}
	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		AddMovementInput(GetActorRightVector(), MoveInput.Y);
	}
}

void AMyPawn::StartJump(const FInputActionValue& Value)
{
	if (Value.Get<bool>())
	{
		AddMovementInput(FVector::UpVector, Value.Get<float>());
	}
}

void AMyPawn::Look(const FInputActionValue& Value)
{
	const FVector2D Look = Value.Get<FVector2D>();

	const float YawDelta =
		Look.X * LookSensitivity;

	const float PitchDelta =
		-Look.Y * LookSensitivity;

	CameraYaw = FMath::Clamp(
		CameraYaw + YawDelta, MinYaw, MaxYaw
	);


	CameraPitch = FMath::Clamp(
		CameraPitch + PitchDelta,
		MinPitch,
		MaxPitch
	);

	SpringArm->SetRelativeRotation(
		FRotator(CameraPitch, CameraYaw, 0.0f)
	);

}