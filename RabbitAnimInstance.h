#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RabbitAnimInstance.generated.h"


UCLASS()
class FROGGERGAME_API URabbitAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class ARabbit* Rabbit;

	UPROPERTY(BlueprintReadOnly)
	class UCharacterMovementComponent* RabbitMovement;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool IsFalling;

	
};
