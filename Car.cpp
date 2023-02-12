#include "Vehicles/Car.h"
#include "Components/BoxComponent.h"


ACar::ACar()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	SetRootComponent(Box);

	CarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarMesh"));
	CarMesh->SetupAttachment(GetRootComponent());

}


void ACar::BeginPlay()
{
	Super::BeginPlay();

	Box->OnComponentBeginOverlap.AddDynamic(this, &ACar::OnBoxOverlap);

	//FVector Location = GetActorForwardVector();
	//float Direction = Location.Y;
	Direction = GetActorForwardVector().Y;

}


void ACar::OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Blue, TEXT("Overlapped"));
		//UE_LOG(LogTemp, Warning, TEXT("position: %s"), *ActorEndLocation.ToString());
	}
	
}


void ACar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MovingLocation = GetActorLocation();
	MovingLocation += GetActorForwardVector() * Speed * DeltaTime;

	SetActorLocation(MovingLocation);

	/*if (Direction > 0 )
	{
		if (MovingLocation.Y > MaxPosition)
		{
			SetActorLocation(FVector(MovingLocation.X, MinPosition, MovingLocation.Z));
		}
	}

	else
	{
		if (MovingLocation.Y < MinPosition)
		{
			SetActorLocation(FVector(MovingLocation.X, MaxPosition, MovingLocation.Z));
		}
	}*/

	bool IsRightward = Direction > 0;
	float StartPosition = IsRightward ? MinPosition : MaxPosition;
	if (MovingLocation.Y < MinPosition || MovingLocation.Y > MaxPosition)
		SetActorLocation(FVector(MovingLocation.X, StartPosition, MovingLocation.Z));
}
