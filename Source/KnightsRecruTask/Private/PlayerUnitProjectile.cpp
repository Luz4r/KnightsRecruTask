// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerUnitProjectile.h"

// Sets default values
APlayerUnitProjectile::APlayerUnitProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("RootStaticMesh"));

	SetRootComponent(RootStaticMesh);

	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileComponent"));
}

// Called when the game starts or when spawned
void APlayerUnitProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerUnitProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

