// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ProjectARPGGameMode.h"
#include "ProjectARPGHUD.h"
#include "ProjectARPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectARPGGameMode::AProjectARPGGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProjectARPGHUD::StaticClass();
}
