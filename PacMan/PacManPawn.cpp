
#include "PacManPawn.h"
#include "Foodie.h"

// Sets default values
APacManPawn::APacManPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APacManPawn::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &APacManPawn::OnOverlapBegin);
}

// Called every frame
void APacManPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!Frozen)
	{
		AddMovementInput(GetActorForwardVector()); // Propels the actor in it's facing direction.
	}
}

// Called to bind functionality to input
void APacManPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APacManPawn::SetDirection(const FVector Direction)
{
	if (Direction == FVector::UpVector)			SetActorRotation(FRotator(0.0f, 270.0f, 0.0f));
	else if (Direction == FVector::DownVector)	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	else if (Direction == FVector::RightVector) SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	else if (Direction == FVector::LeftVector)	SetActorRotation(FRotator(0.0f, 180.0f, 180.0f));
}

void APacManPawn::OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("Foodie.Regular"))
		Cast<AFoodie>(OtherActor)->Consume();
}
