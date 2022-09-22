// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddles.generated.h"

class UFloatingPawnMovement;

UCLASS()
class BRICKBREAKER_API APaddles : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//UProperty variables are declared using standard C++ syntax with additional descriptors, such as variable specifiers and metadata placed above the declaration.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		//* 
		UStaticMeshComponent* SM_Padle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		
		UFloatingPawnMovement* FloatingMovement;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void MoveHorizontal(float AxisValue);

};
