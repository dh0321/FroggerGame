#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Car.generated.h"

class UBoxComponent;
class UStaticMeshComponent;


UCLASS()
class FROGGERGAME_API ACar : public AActor
{
	GENERATED_BODY()
	
public:	

	ACar();

protected:

	virtual void BeginPlay() override;

	FVector ActorStartLocation;
	FVector ActorEndLocation;
	//FVector Distance;

	UPROPERTY(EditAnywhere, Category = "MoveActor")
	float Speed = 100.f;

	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	


public:	

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CarMesh;

	
};
