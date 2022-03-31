
#include "EnemyPawn.h"

void AEnemyPawn::Hunt()
{
	State = EEnemyState::Default;
	StateChangedEvent.Broadcast(State);
}

void AEnemyPawn::Idle()
{
	State = EEnemyState::Idle;
	StateChangedEvent.Broadcast(State);
}
