

#include "PlayerControllerPadle.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Paddles.h"
#include "ball.h"

APlayerControllerPadle::APlayerControllerPadle()
{

}


void APlayerControllerPadle::BeginPlay()
{

	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
	FViewTargetTransitionParams Params;

	//shows camera for the player at the zero index
	SetViewTarget(CameraActors[0], Params);

	SpawnNewball();

}

void APlayerControllerPadle::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Enables this movement on player controller created in unreal under edit project/input.
	EnableInput(this);
	InputComponent->BindAxis("MoveHorizontal", this, &APlayerControllerPadle::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APlayerControllerPadle::Launch);
}
//AxisValue is for scale parameter in movement
void APlayerControllerPadle::MoveHorizontal(float AxisValue)
{
	//auto will detect value on the right side as the same type

	auto MyPawn = Cast<APaddles>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveHorizontal(AxisValue);
	}
}

void APlayerControllerPadle::Launch()
{

	Myball->Launch();

}

void APlayerControllerPadle::SpawnNewball()
{

	if (!Myball)
		Myball = nullptr;

	if (ballObj) {

		Myball = GetWorld()->SpawnActor<Aball>(ballObj, SpawnLocation, SpawnRotation, SpawnInfo);

	}

}