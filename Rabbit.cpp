// Fill out your copyright notice in the Description page of Project Settings.


#include "Animals/Rabbit.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


ARabbit::ARabbit()
{
	PrimaryActorTick.bCanEverTick = true;


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 500.f;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	AutoPossessPlayer = EAutoReceiveInput::Player0;


	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


}


void ARabbit::BeginPlay()
{
	Super::BeginPlay();
	
}


void ARabbit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARabbit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ARabbit::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ARabbit::MoveRight);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ARabbit::Turn);
	/*PlayerInputComponent->BindAxis(FName("LookUp"), this, &ARabbit::LookUp);*/

	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ARabbit::Jump);
}

void ARabbit::MoveForward(float Value)
{
	if (Controller && (Value != 0.f))
	{
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ARabbit::MoveRight(float Value)
{
	if (Controller && (Value != 0.f))
	{
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ARabbit::Turn(float Value)
{
	AddControllerYawInput(Value);
}

//void ARabbit::LookUp(float Value)
//{
//	AddControllerPitchInput(Value);
//}

