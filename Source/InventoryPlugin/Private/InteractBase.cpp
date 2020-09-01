// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractBase.h"
#include "InventoryComponent.h"
#include "InventoryActor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
AInteractBase::AInteractBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionCompoent"));
	ActorVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActorVisual"));
	RootComponent = CollisionComponent;
	ActorVisual->SetupAttachment(RootComponent);
	CollisionComponent->SetSphereRadius(50.0f);
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AInteractBase::BeginOverlap);
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &AInteractBase::EndOverlap);
}

// Called when the game starts or when spawned
void AInteractBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractBase::BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int OtherBodyIndex, bool FromSweep, const FHitResult & SweepResult)
{
	UInventoryComponent* ComponentPtr = Cast<UInventoryComponent>(OtherComp);
	if (ComponentPtr) 
	{
		ComponentPtr->InventoryPtr->CurrentInteractActor = this;
	}
}

void AInteractBase::EndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int OtherBodyIndex)
{
	UInventoryComponent* ComponentPtr = Cast<UInventoryComponent>(OtherComp);
	if (ComponentPtr)
	{
		ComponentPtr->InventoryPtr->CurrentInteractActor = nullptr;
	}
}

void AInteractBase::ObjectInteract(AInventoryActor* InventoryActor)
{

}

