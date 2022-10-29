// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UnitMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UUnitMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUnitMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void MoveToWorldLocation(float MovementSpeed, FVector InDestinationWorldLocation);

	UFUNCTION(BlueprintCallable)
	void MoveToActor(float MovementSpeed, AActor* InDestinationActor);

	float MovementSpeed = 100.f;

	FVector DestinationWorldLocation = FVector::ZeroVector;

	bool bIsMovingToDestination = false;

	AActor* DestinationActor = nullptr;
};
