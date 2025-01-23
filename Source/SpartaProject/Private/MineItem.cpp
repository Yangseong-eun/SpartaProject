// Fill out your copyright notice in the Description page of Project Settings.


#include "MineItem.h"
#include "Components/SphereComponent.h"

AMineItem::AMineItem()
{
	ExplosionDelay = 5.0f;
	ExplosionDamage = 30.0f;
	ExplosionRadius = 300.f;

	ItemType = "Mine";

	ExplosionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
	ExplosionCollision->InitSphereRadius(ExplosionRadius);
	ExplosionCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	ExplosionCollision->SetupAttachment(Scene);
}

void AMineItem::ActivateItem(AActor* Activator)
{
	//게임월드-> 여러 개의 타이머 핸들러가 존재 -> 타이머 매니저 존재
	//타이머 핸들러: 시계

	GetWorld()->GetTimerManager().SetTimer(ExPlosionTimerHandle, this, &AMineItem::Explode, ExplosionDelay, false);
}

void AMineItem::Explode()
{
	TArray<AActor*> OverlappingActors;
	ExplosionCollision->GetOverlappingActors(OverlappingActors);

	for (AActor* Actor : OverlappingActors)
	{
		if (Actor && Actor->ActorHasTag("Player"))
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Player Damaged %d by MineItem!"), ExplosionDamage));
		}
	}
	DestroyItem();
}
