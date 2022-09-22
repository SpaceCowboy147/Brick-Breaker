

#include "ball.h"
#include "Components/StaticMeshComponent.h"
#include "GameFrameWork/ProjectileMovementComponent.h"

// Sets default values
Aball::Aball()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ball"));
	RootComponent = SM_Ball;

	SM_Ball->SetSimulatePhysics(true);
	// want the value true so the ball can bounce  
	SM_Ball->SetEnableGravity(false);
	//dont want gravity pulling ball down.
	SM_Ball->SetConstraintMode(EDOFMode::XZPlane);
	// moves on XZ Plane. X plane needs to be disables below in ProjectileMovement.

	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	// Need to call Physics so the mesh has a physics body
	SM_Ball->SetCollisionProfileName(TEXT("PhysicsActor"));
	//Make sure Physics actor is spelled correctly. Can find preset name in the Paddle_BP blueprints in the details tab under collision presets.

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1f;
	//How much ball will bounce
	ProjectileMovement->Friction = 0.0f;
	//don't want to the ball to slow down when it collides to the bricks
	ProjectileMovement->Velocity.X = 0.0f;
	//Disable X axis here. Don't want the ball falling out of bounds. 


}


// Called when the game starts or when spawned
void Aball::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void Aball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Aball::Launch()
{

	if (!ballLaunched) {
		SM_Ball->AddImpulse(FVector(140.0f, 0.0f, 130.0f), FName(), true);

		ballLaunched = true; 
		//Only want the ball exectuted once after the ball is launched 
	}
}
UStaticMeshComponent * Aball::Getball()
{
	return SM_Ball;
}



