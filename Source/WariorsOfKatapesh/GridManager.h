// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WariorsOfKatapesh/GridTileComponent.h"
#include "GridManager.generated.h"

UCLASS()
class WARIORSOFKATAPESH_API AGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridManager();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StaticMesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMesh* DefaultMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ScaleX = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ScaleY= 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TileSize = 145;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TileSpacing = 5;

	UPROPERTY(BlueprintReadWrite)
	TArray<UGridTileComponent*> Tiles;

	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> TileLocations;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void GenerateTiles();

	UFUNCTION(BlueprintCallable)
	void DeleteTiles();

private:
	void CreateTile(int indx);

	void AddTile(TArray<UGridTileComponent*> &TileArray, UGridTileComponent *Tile);

	void GenerateTileLocations();

};
