
#include "Actor_R.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AActor_R::AActor_R()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	RotationSpeed = FRotator(0.f, 90.f, 0.f);

}

// Called when the game starts or when spawned
void AActor_R::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActor_R::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(RotationSpeed * DeltaTime);

}

