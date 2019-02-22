// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "WariorsOfKatapeshGameMode.h"
#include "WariorsOfKatapeshPlayerController.h"
#include "WariorsOfKatapeshCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWariorsOfKatapeshGameMode::AWariorsOfKatapeshGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AWariorsOfKatapeshPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}