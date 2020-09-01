// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractBase.h"
#include "PickUp.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYPLUGIN_API APickUp : public AInteractBase
{
	GENERATED_BODY()
	
public:
	virtual void ObjectInteract(AInventoryActor* InventoryActor) override;
};
