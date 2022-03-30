
#include "PacManController.h"
#include "PacManPawn.h"
#include "Components/InputComponent.h"

void APacManController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("MoveUp", IE_Pressed, this, &APacManController::MoveUp);
	InputComponent->BindAction("MoveDown", IE_Pressed, this, &APacManController::MoveDown);
	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APacManController::MoveLeft);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &APacManController::MoveRight);
}

APacManPawn* APacManController::GetPacManPawn() const
{
	return Cast<APacManPawn>(GetPawn());
}

void APacManController::Move(FVector Direction)
{
	APacManPawn* PacManPawn = GetPacManPawn();
	if (PacManPawn != nullptr) PacManPawn->SetDirection(Direction);
}

void APacManController::MoveUp()
{
	Move(FVector::UpVector);
}

void APacManController::MoveDown()
{
	Move(FVector::DownVector);
}

void APacManController::MoveLeft()
{
	Move(FVector::LeftVector);
}

void APacManController::MoveRight()
{
	Move(FVector::RightVector);
}
