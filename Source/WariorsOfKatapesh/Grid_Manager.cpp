// Fill out your copyright notice in the Description page of Project Settings.

#include "Grid_Manager.h"
#include "Classes/Components/SceneComponent.h"
#include "Classes/Components/StaticMeshComponent.h"

// Sets default values
AGrid_Manager::AGrid_Manager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

int AGrid_Manager::GetScaleX()
{
	return 0;
}

int AGrid_Manager::GetScaleY()
{
	return 0;
}

TArray<FVector> AGrid_Manager::GetTileLocations()
{
	return TileLocations;
}

void AGrid_Manager::AddTile(UStaticMeshComponent *Tile)
{
}


// Called when the game starts or when spawned
void AGrid_Manager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGrid_Manager::GenerateTileLocations()
{
	TileLocations.Empty();
	Tiles.Empty();
	float offset = TileSize + TileSpacing;
	for (int x = 0; x < ScaleX; x++) {
		for (int y = 0; y < ScaleY; y++) {
			TileLocations.Emplace(FVector(offset*x, offset*y, 0));
		}
	}
}

// Called every frame
void AGrid_Manager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

