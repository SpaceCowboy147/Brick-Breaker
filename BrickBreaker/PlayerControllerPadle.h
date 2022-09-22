

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerPadle.generated.h"

class Aball;

UCLASS()
class BRICKBREAKER_API APlayerControllerPadle : public APlayerController
{
	GENERATED_BODY()

		APlayerControllerPadle();

	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;
	void MoveHorizontal(float AxisValue);

	//ball references below

	void Launch();

	UPROPERTY(EditAnywhere)
		TSubclassOf<Aball> ballObj;

	Aball* Myball;

	//need these 3 to spawn an actor.
	FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

public:

	void SpawnNewball();

};

