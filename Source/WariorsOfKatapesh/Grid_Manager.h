// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid_Manager.generated.h"

UCLASS(Blueprintable)
class WARIORSOFKATAPESH_API AGrid_Manager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrid_Manager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ScaleX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ScaleY;

	UPROPERTY(EditAnywhere)
	float TileSize = 95;

	UPROPERTY(EditAnywhere)
	float TileSpacing = 5;

	UFUNCTION(BlueprintCallable)
	int GetScaleX();

	UFUNCTION(BlueprintCallable)
	int GetScaleY();

	UFUNCTION(BlueprintCallable)
	TArray<FVector> GetTileLocations();

	UFUNCTION(BlueprintCallable)
	void AddTile(UStaticMeshComponent *Tile);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	TArray<FVector> TileLocations;
	TArray<UStaticMeshComponent> Tiles;

	UFUNCTION(BlueprintCallable)
	void GenerateTileLocations();

};
