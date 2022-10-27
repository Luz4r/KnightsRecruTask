// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh;
		FConstructorStatics()
			: SphereMesh(TEXT("/Engine/BasicShapes/Sphere")) {}
	};

	static FConstructorStatics ConstructorStatics;

	RootStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("RootStaticMesh"));
	if (RootStaticMesh)
	{
		RootStaticMesh->SetStaticMesh(ConstructorStatics.SphereMesh.Object);
		RootStaticMesh->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
		RootStaticMesh->SetHiddenInGame(true);
	}

	SetRootComponent(RootStaticMesh);

	MainCamera = CreateDefaultSubobject<UCameraComponent>(FName("MainCamera"));
	MainCamera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

