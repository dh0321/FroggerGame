

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

	ActorStartLocation = GetActorLocation();
	//UE_LOG(LogTemp, Warning, TEXT("position: %s"), *ActorLocation.ToString());

	Box->OnComponentBeginOverlap.AddDynamic(this, &ACar::OnBoxOverlap);

}


void ACar::OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Blue, TEXT("Overlapped"));

	}

	ActorEndLocation = GetActorLocation();

	SetActorLocation(ActorStartLocation);

}


void ACar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	Location += GetActorForwardVector() * Speed * DeltaTime;

	SetActorLocation(Location);

}

