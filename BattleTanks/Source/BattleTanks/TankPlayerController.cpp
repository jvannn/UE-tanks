// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();
	ATank* TestTank = GetControlledTank();
	if (!TestTank) {
		UE_LOG(LogTemp, Warning, TEXT("Tank player controller missing!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player controller tank: %s"), *TestTank->GetName());
	}
}