#include "Animals/RabbitAnimInstance.h"
#include "Animals/Rabbit.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void URabbitAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Rabbit = Cast<ARabbit>(TryGetPawnOwner());
	if (Rabbit)
	{
		RabbitMovement = Rabbit->GetCharacterMovement();
	}

}

void URabbitAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (RabbitMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(RabbitMovement->Velocity);
		IsFalling = RabbitMovement->IsFalling();
	}
}
