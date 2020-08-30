// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActor.h"
#include "GameFramework/Character.h"
//#include "UObject/ConstructorHelpers.h" 

// Sets default values
AInventoryActor::AInventoryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	if (!IsValid(InventoryTable)) 
	{
		//static ConstructorHelpers::FObjectFinder<UTexture2D> ObjectFinder(TEXT("Texture2D'/Game/Textures/tex1.tex1'"));
		//UTexture2D* Texture2D = ObjectFinder.Object;
		InventoryTable = LoadObject<UDataTable>(NULL, UTF8_TO_TCHAR("DataTable'/InventoryPlugin/Data/InventoryDataTable/ItemTable.ItemTable'"));
	}
	InitInventory();
	InventoryCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("InventoryCollisionComponent"));
	InventoryCollisionComponent->SetSphereRadius(50.0f);

}

// Called when the game starts or when spawned
void AInventoryActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventoryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInventoryActor::InitInventory() 
{
	if (InventoryMap.Num() == 0)
	{
		//Init 4 types inventory
		TArray<FInventoryItem> Equipments;
		InventoryMap.Add(EInventoryItemType::EQUIPMENTS, Equipments);
		TArray<FInventoryItem> Consumables;
		InventoryMap.Add(EInventoryItemType::CONSUMABLES, Consumables);
		TArray<FInventoryItem> QuestItems;
		InventoryMap.Add(EInventoryItemType::QUESTITEMS, QuestItems);
		TArray<FInventoryItem> Others;
		InventoryMap.Add(EInventoryItemType::OTHERS, QuestItems);


		if (IsValid(InventoryTable)) 
		{
			FInventoryItem* ItemToAdd1 = InventoryTable->FindRow<FInventoryItem>("1", "");
			FInventoryItem* ItemToAdd2 = InventoryTable->FindRow<FInventoryItem>("2", "");
			FInventoryItem* ItemToAdd3 = InventoryTable->FindRow<FInventoryItem>("3", "");
			FInventoryItem* ItemToAdd4 = InventoryTable->FindRow<FInventoryItem>("4", "");
			if (ItemToAdd1 && ItemToAdd2 && ItemToAdd3 && ItemToAdd4)
			{
				for (int i = 0; i < 32; ++i)
				{
					InventoryMap[EInventoryItemType::EQUIPMENTS].Add(*ItemToAdd1);
					InventoryMap[EInventoryItemType::CONSUMABLES].Add(*ItemToAdd2);
					InventoryMap[EInventoryItemType::QUESTITEMS].Add(*ItemToAdd3);
					InventoryMap[EInventoryItemType::OTHERS].Add(*ItemToAdd4);
				}
			}
		}
	}
}

TArray< FInventoryItem > AInventoryActor::GetInventoryByType( EInventoryItemType InventoryType )
{
	return InventoryMap[InventoryType];
}

void AInventoryActor::AttachComponentToPlayer(ACharacter * CharacterPtr)
{
	InventoryCollisionComponent->SetupAttachment(CharacterPtr->GetRootComponent());
}

