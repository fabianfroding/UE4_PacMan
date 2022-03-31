
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Foodie.generated.h"

class USoundCue;

UENUM(BlueprintType)
enum class EFoodieType : uint8
{
	Regular,
	Powerup
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFoodieEatenEvent, EFoodieType, FoodieType);

UCLASS()
class PACMAN_API AFoodie : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodie();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Consume();

	UPROPERTY(EditAnywhere)
		EFoodieType FoodieType = EFoodieType::Regular;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FFoodieEatenEvent FoodieEatenEvent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		USoundCue* ConsumptionSound;

};
