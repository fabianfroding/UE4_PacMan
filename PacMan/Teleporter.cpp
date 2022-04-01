
#include "Teleporter.h"
#include "Engine/Public/TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/SceneComponent.h"

ATeleporter::ATeleporter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATeleporter::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ATeleporter::OnOverlapBegin);
}

void ATeleporter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATeleporter::TeleportToTarget(AActor* Actor)
{
	USceneComponent* TargetSpawn = Cast<USceneComponent>(Target->GetDefaultSubobjectByName("Spawn"));
	UGameplayStatics::PlaySound2D(this, TeleportSound);
	Actor->SetActorLocation(TargetSpawn->GetComponentLocation());
}

void ATeleporter::OnOverlapBegin(AActor* TeleporterActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("PacMan"))
	{
		GetWorldTimerManager().SetTimerForNextTick([OtherActor, this]() { TeleportToTarget(OtherActor); });
	}
}
