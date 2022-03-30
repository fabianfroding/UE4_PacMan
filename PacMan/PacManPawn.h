#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacManPawn.generated.h"

UCLASS()
class PACMAN_API APacManPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APacManPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetDirection(const FVector Direction);

	bool IsFrozen() { return Frozen; }

	UFUNCTION(BlueprintCallable)
		void SetFrozen(bool Value) { Frozen = Value; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
		bool Frozen = true;

private:

	UFUNCTION()
		void OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor);

};
