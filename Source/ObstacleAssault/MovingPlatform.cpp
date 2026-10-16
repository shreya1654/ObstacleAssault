// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void MyTestFunction(float MyFloat, int MyInt, FString MyString)
{
	UE_LOG(LogTemp, Display, TEXT("MyFloat is %f"), MyFloat);
	UE_LOG(LogTemp, Display, TEXT("MyInt is %d"), MyInt);
	UE_LOG(LogTemp, Display, TEXT("MyString is %s"), *MyString);
}



// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	FString MyName = GetName();
	MyTestFunction(200.5f, 19, MyName);

	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);

	SetActorLocation(CurrentLocation);

	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	// Rotates the platform
}

