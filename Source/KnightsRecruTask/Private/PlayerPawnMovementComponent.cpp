// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnMovementComponent.h"

// Sets default values for this component's properties
UPlayerPawnMovementComponent::UPlayerPawnMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerPawnMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerPawn = Cast<APawn>(GetOwner());
	
}


// Called every frame
void UPlayerPawnMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (OwnerPawn->GetPendingMovementInputVector() != FVector::ZeroVector)
	{
		FVector NewMovementInputVector = OwnerPawn->ConsumeMovementInputVector();
		NewMovementInputVector.Normalize();

		NewMovementInputVector *= DeltaTime * MovementSpeed;

		CurrentMovementVector = FMath::VInterpTo(CurrentMovementVector, NewMovementInputVector, DeltaTime, CameraMovementInterpSpeed);

		OwnerPawn->AddActorWorldOffset(CurrentMovementVector);
	}
	else if (CurrentMovementVector != FVector::ZeroVector)
	{
		CurrentMovementVector = FMath::VInterpTo(CurrentMovementVector, FVector::ZeroVector, DeltaTime, CameraMovementInterpSpeed);
		OwnerPawn->AddActorWorldOffset(CurrentMovementVector);
	}
}

