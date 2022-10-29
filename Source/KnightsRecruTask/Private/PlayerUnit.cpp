// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerUnit.h"

// Sets default values
APlayerUnit::APlayerUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("RootStaticMesh"));

	SetRootComponent(RootStaticMesh);
}

// Called when the game starts or when spawned
void APlayerUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsMovingToDestination)
	{
		FVector Direction = DestinationWorldLocation - this->GetActorLocation();
		Direction.Normalize();
		Direction.Z = 0.f;

		FHitResult HitResult;

		this->AddActorWorldOffset(Direction * MovementSpeed * DeltaTime, true, &HitResult);

		if ((HitResult.bBlockingHit) || Direction.Equals(FVector::ZeroVector))
		{
			bIsMovingToDestination = false;
			UE_LOG(LogTemp, Warning, TEXT("Finished Movement"))
		}
	}
}

