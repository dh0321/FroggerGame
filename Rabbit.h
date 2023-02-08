
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Rabbit.generated.h"

class USpringArmComponent;
class UCameraComponent;


UCLASS()
class FROGGERGAME_API ARabbit : public ACharacter
{
	GENERATED_BODY()

public:

	ARabbit();

protected:

	virtual void BeginPlay() override;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void Turn(float Value);

	//void LookUp(float Value);



private:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;



public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
