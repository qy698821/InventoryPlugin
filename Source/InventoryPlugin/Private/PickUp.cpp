// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"
#include "InventoryWidget.h"
#include "InventoryActor.h"

void APickUp::ObjectInteract(AInventoryActor* InventoryActor) 
{
	if (InventoryActor) 
	{
		InventoryActor->AddInventoryItemByID(ID);
		InventoryActor->InventoryWB->LoadInventory();
		this->Destroy();
	}
}