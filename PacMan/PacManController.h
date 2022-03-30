#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "PacManController.generated.h"

class APacManPawn;

UCLASS()
class PACMAN_API APacManController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FName MoveUpInputActionMapName;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FName MoveDownInputActionMapName;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FName MoveLeftInputActionMapName;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FName MoveRightInputActionMapName;

	UPROPERTY(EditAnywhere)
		bool IsAFrog;

	void Move(FVector Direction);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	
protected:
	void SetupInputComponent() override;
	APacManPawn* GetPacManPawn() const;
};
