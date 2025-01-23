// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemInterface.h"
#include "BaseItem.generated.h"

class USphereComponent;

UCLASS()
class SPARTAPROJECT_API ABaseItem : public AActor, public IItemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USphereComponent* Collision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	UStaticMeshComponent* StaticMesh;


	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp, //오버랩이 발생한 자기 자신(sphere component)
		AActor* OtherActor, //sphere 컴포넌트에 부딪힌 상대
		UPrimitiveComponent* OtherComp, // 액터에 붙어있던, 충돌의 원인인 컴포넌트
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp, //오버랩이 발생한 자기 자신(sphere component)
		AActor* OtherActor, //sphere 컴포넌트에 부딪힌 상대
		UPrimitiveComponent* OtherComp, // 액터에 붙어있던, 충돌의 원인인 컴포넌트
		int32 OtherBodyIndex ) override;
	virtual void ActivateItem(AActor* Activator) override;
	virtual FName GetItemType() const override;


	virtual void DestroyItem();


};
