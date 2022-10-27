// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerPawn.h"
#include "PlayerPawnMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), Blueprintable, meta=(BlueprintSpawnableComponent) )
class UPlayerPawnMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerPawnMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	FVector CurrentMovementVector = FVector::ZeroVector;
	APawn* OwnerPawn = nullptr;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float MovementSpeed = 100.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float CameraMovementInterpSpeed = 1.f;
};
