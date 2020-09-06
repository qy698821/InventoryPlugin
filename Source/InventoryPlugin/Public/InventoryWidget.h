// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryActor.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYPLUGIN_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AInventoryActor* InventoryPtrInGame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EInventoryItemType LastLoadType = EInventoryItemType::EQUIPMENTS;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void LoadInventory();
};
