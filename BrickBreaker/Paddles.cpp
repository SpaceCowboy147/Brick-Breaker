

//#include is a way of including a standard or user-defined file in the program.
//read by the preprocessor and orders it to insert the content of a user-defined or system header file into the following program
#include "Paddles.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"




APaddles::APaddles()
{
 	// Set this pawn to call Tick() every frame.  
	//PrimaryActorTick function calls TickActor() .
	//Tick functions can be configured to control whether ticking is enabled, a time during a frame the update occurs, and set up tick dependencies
	//Ticking" refers to running a piece of code or Blueprint script on an actor or component at regular intervals
	PrimaryActorTick.bCanEverTick = true;

	SM_Padle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Padle"));
	RootComponent = SM_Padle;

	//No gravity so the padle won't fall on the ground
	SM_Padle->SetEnableGravity(false);

	//EDOF allows me to constrain the movement of the object. The  paddle will only move on a XZ plane. Can be changed to XY, YZ, XYZ, Custom, etc 
	SM_Padle->SetConstraintMode(EDOFMode::XZPlane);

	//Allows collision so the paddle can hit the ball back
	SM_Padle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//Make sure the name you set is spelled CORRECTLY
	SM_Padle->SetCollisionProfileName(TEXT("PhysicsActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating pawn movement"));
}

// Called when the game starts or when spawned
void APaddles::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddles::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APaddles::MoveHorizontal(float AxisValue)
{
	//False Statement because we don't want to use force 
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0f), 1.0f, false);
}



