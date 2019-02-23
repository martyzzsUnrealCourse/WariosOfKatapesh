// Fill out your copyright notice in the Description page of Project Settings.


#include "GridManager.h"

// Sets default values
AGridManager::AGridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	auto MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	RootComponent = MeshComponent;

}

// Called when the game starts or when spawned
void AGridManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGridManager::CreateTile(int indx)
{
	//auto TileName = FString("Tile_") + FString::FromInt(indx);
	//auto TileObj = CreateDefaultSubobject<UGridTileComponent>(FName(*TileName));

	auto TileObj = NewObject<UGridTileComponent>(this);
	TileObj->SetRelativeLocation(TileLocations[indx]);
	TileObj->SetStaticMesh(DefaultMesh);
	TileObj->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	UE_LOG(LogTemp, Warning, TEXT("%s adding to Tiles"), *TileObj->GetName())
	AddTile(Tiles, TileObj);
}

void AGridManager::AddTile(TArray<UGridTileComponent*>& TileArray, UGridTileComponent *Tile)
{
	TileArray.Emplace(Tile);
}

void AGridManager::GenerateTileLocations()
{
	DeleteTiles();
	TileLocations.Empty();
	float offset = TileSize + TileSpacing;
	for (int x = 0; x < ScaleX; x++) {
		for (int y = 0; y < ScaleY; y++) {
			TileLocations.Emplace(FVector(offset*x, offset*y, 0));
		}
	}
}

void AGridManager::DeleteTiles()
{
	for (UGridTileComponent *Tile : Tiles) {
		if (Tile) {
			UE_LOG(LogTemp,Warning,TEXT("%s marked for delete"), *Tile->GetName())
			Tile->DestroyComponent();
		}
	}
	Tiles.Empty();
}

void AGridManager::GenerateTiles()
{
	GenerateTileLocations();

	int TileCount = ScaleX * ScaleY;
	for (int i = 0; i < TileCount; i++) {
		CreateTile(i);
	}
}

