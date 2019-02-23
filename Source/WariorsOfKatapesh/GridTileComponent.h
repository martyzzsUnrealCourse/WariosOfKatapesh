// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GridTileComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARIORSOFKATAPESH_API UGridTileComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StaticMesh,  meta = (AllowPrivateAccess = "true"))
		class UStaticMesh* OtherMesh;
	
};
