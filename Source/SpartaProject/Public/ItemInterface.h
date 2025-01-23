#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemInterface.generated.h"

UINTERFACE(MinimalAPI)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPARTAPROJECT_API IItemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp, //오버랩이 발생한 자기 자신(sphere component)
		AActor* OtherActor, //sphere 컴포넌트에 부딪힌 상대
		UPrimitiveComponent* OtherComp, // 액터에 붙어있던, 충돌의 원인인 컴포넌트
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) = 0; //0이 없으면 그냥 가상함수 형태
	UFUNCTION()
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) = 0; //0을 붙이면 반드시 오버라이딩 해줘야됨
	virtual void ActivateItem(AActor* Activator) = 0;
	virtual FName GetItemType() const = 0;


	//지뢰 힐링 코인
	//힐링, 코인-> 즉시 발동형 오버랩
	//지뢰- 범위 내에 오버랩- 발동이 5초뒤 폭발- 오버랩- 데미지
};
