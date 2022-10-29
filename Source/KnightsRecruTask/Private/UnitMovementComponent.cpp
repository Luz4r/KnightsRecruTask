// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitMovementComponent.h"

// Sets default values for this component's properties
UUnitMovementComponent::UUnitMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUnitMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UUnitMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (bIsMovingToDestination)
	{
		if (DestinationActor)
		{
			DestinationWorldLocation = DestinationActor->GetActorLocation();
		}

		FVector Direction = DestinationWorldLocation - this->GetOwner()->GetActorLocation();
		Direction.Normalize();
		Direction.Z = 0.f;

		FHitResult HitResult;

		this->GetOwner()->AddActorWorldOffset(Direction * MovementSpeed * DeltaTime, true, &HitResult);

		if ((HitResult.bBlockingHit) || Direction.Equals(FVector::ZeroVector))
		{
			bIsMovingToDestination = false;
			UE_LOG(LogTemp, Warning, TEXT("Finished Movement"))
		}
	}
}


void UUnitMovementComponent::MoveToWorldLocation(float InMovementSpeed, FVector InDestinationWorldLocation)
{
	MovementSpeed = InMovementSpeed;
	DestinationWorldLocation = InDestinationWorldLocation;
	DestinationActor = nullptr;
	bIsMovingToDestination = true;
}

void UUnitMovementComponent::MoveToActor(float InMovementSpeed, AActor* InDestinationActor)
{
	MovementSpeed = InMovementSpeed;
	DestinationActor = InDestinationActor;
	bIsMovingToDestination = true;
}

