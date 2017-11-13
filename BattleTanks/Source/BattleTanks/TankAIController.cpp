// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* TestTank = GetControlledTank();
	if (!TestTank) {
		UE_LOG(LogTemp, Warning, TEXT("Tank player controller missing!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI controller tank: %s"), *TestTank->GetName());
	}

	ATank* PlayerController = GetPlayerTank();
	if (!PlayerController) {
		UE_LOG(LogTemp, Warning, TEXT("Player controller not found!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player controller found: %s"), *PlayerController->GetName());
	}
}

ATank* ATankAIController::GetPlayerTank() const 
{
	auto PlayerController = GetWorld()->GetFirstPlayerController();
	return Cast<ATank>(PlayerController->GetPawn());
}