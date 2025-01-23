// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class SPARTAPROJECT_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	

	ASpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UBoxComponent* SpawningBox;


	UFUNCTION(BlueprintCallable, Category="Spawning")
	FVector GetRandomPointInVolume() const; 
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnItem(TSubclassOf<AActor> ItemClass); //엑터의 하위까지 

};
