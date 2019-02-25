// Fill out your copyright notice in the Description page of Project Settings.


#include "GridManager.h"
#include "Components/StaticMeshComponent.h"

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
	TileObj->AttachToComponent(ColisionPlane, FAttachmentTransformRules::KeepRelativeTransform);
	UE_LOG(LogTemp, Warning, TEXT("%s adding to Tiles"), *TileObj->GetName())
	AddTile(Tiles, TileObj);
}

void AGridManager::AddTile(TArray<UGridTileComponent*>& TileArray, UGridTileComponent *Tile)
{
	TileArray.Emplace(Tile);
}

void AGridManager::GenerateTileLocations()
{
	TileLocations.Empty();
	float offset = TileSize + TileSpacing;
	for (int x = 0; x < ScaleX; x++) {
		for (int y = 0; y < ScaleY; y++) {
			TileLocations.Emplace(FVector(offset*x, offset*y, 0));
		}
	}
	ScaleXOld = ScaleX; ScaleYOld = ScaleY;
}

void AGridManager::DeleteTiles()
{
	
	//if (ScaleXOld > ScaleX) {
	//	int i = ScaleX * ScaleY;
	//	for (int x = ScaleX; x < ScaleXOld; x++) {
	//		for (int y = 0; y < ScaleY; y++) {
	//			UE_LOG(LogTemp, Warning, TEXT("%i"), i)
	//			Tiles[i]->DestroyComponent();
	//			UE_LOG(LogTemp, Warning, TEXT("%s (indx %i) Marked for delete"), *Tiles[i]->GetName(), i)
	//			i++;
	//		}
	//	}
	//}
	//else if (ScaleX == ScaleXOld && ScaleY < ScaleYOld) {
	//	
	//	for (int x = 0; x < ScaleXOld; x++) {
	//		int i = ScaleY*(x+1)+x;
	//		for (int y = ScaleY; y < ScaleYOld; y++) {
	//			UE_LOG(LogTemp, Warning, TEXT("%i"), i)
	//			Tiles[i]->DestroyComponent();
	//			UE_LOG(LogTemp, Warning, TEXT("%s (indx %i) Marked for delete"), *Tiles[i]->GetName(), i)
	//			i++;
	//		}
	//	}
	//}

	for (UGridTileComponent *Tile : Tiles) {
		if (Tile) {
			UE_LOG(LogTemp, Warning, TEXT("%s marked for delete"), *Tile->GetName())
				Tile->DestroyComponent();
		}
	}
	Tiles.Empty();
}

void AGridManager::GenerateTiles()
{
	DeleteTiles();
	if (ColisionPlane)
		ColisionPlane->DestroyComponent();

	GetWorld()->ForceGarbageCollection();

	ColisionPlane = NewObject<UGridTileComponent>(this);
	ColisionPlane->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	GenerateTileLocations();

	int indx = 0;
	for (int x = 0; x < ScaleX; x++) {
		for (int y = 0; y < ScaleY; y++) {
			CreateTile(indx);
			indx++;
		}
	}
}

