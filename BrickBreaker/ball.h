
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ball.generated.h"

class UProjectileMovementComponent;

UCLASS()
class BRICKBREAKER_API Aball : public AActor
{
	GENERATED_BODY() 
	
public:	
	// Sets default values for this actor's properties
	Aball();
	
	virtual void Launch();

	bool ballLaunched;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Ball;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UProjectileMovementComponent* ProjectileMovement;
	// need to forward declare ProjectileMovementComponent above UCLASS


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		UStaticMeshComponent* Getball();

};
