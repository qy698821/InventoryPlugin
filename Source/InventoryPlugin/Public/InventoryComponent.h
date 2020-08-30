// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "InventoryComponent.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYPLUGIN_API UInventoryComponent : public USphereComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AInventoryActor* InventoryPtr;

	virtual void BeginPlay() override;
};
