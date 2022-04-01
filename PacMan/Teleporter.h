
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teleporter.generated.h"

class USoundCue;

UCLASS()
class PACMAN_API ATeleporter : public AActor
{
	GENERATED_BODY()
	
public:	
	ATeleporter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void TeleportToTarget(AActor* Actor);

	UPROPERTY(EditAnywhere)
		ATeleporter* Target = nullptr;

	UPROPERTY(EditAnywhere)
		USoundCue* TeleportSound;

	UFUNCTION()
		void OnOverlapBegin(AActor* TeleporterActor, AActor* OtherActor);

};
