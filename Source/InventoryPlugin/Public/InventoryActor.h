// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "PickUp.h"
#include "Engine/DataTable.h"
#include "InventoryActor.generated.h"

UENUM(BlueprintType)
enum class EInventoryItemType : uint8
{
	EQUIPMENTS,
	CONSUMABLES,
	QUESTITEMS,
	OTHERS
};
USTRUCT(BlueprintType)
struct FInventoryItem : public FTableRowBase 
{
	GENERATED_BODY()

public:
	FInventoryItem()
	{
		ItemID = TEXT("请输入ID");
		Description = TEXT("请描述该物品");
		Number = 1;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class APickUp> PickUpClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Number;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanBeUse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EInventoryItemType Type;
};

UCLASS()
class INVENTORYPLUGIN_API AInventoryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Inventory map
	TMap< EInventoryItemType, TArray< FInventoryItem > > InventoryMap;

	void InitInventory();

	UFUNCTION(BlueprintCallable)
		TArray< FInventoryItem > GetInventoryByType(EInventoryItemType InventoryType);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class AInteractBase* CurrentInteractActor = nullptr;

	//UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UInGameWidget* InGameWB;

private:
	UPROPERTY(EditDefaultsOnly)
		UDataTable* InventoryTable;

};
