// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "InventoryActor.h"

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	if (!IsValid(InventoryPtr))
	{
		InventoryPtr = NewObject<AInventoryActor>();
	}
}
