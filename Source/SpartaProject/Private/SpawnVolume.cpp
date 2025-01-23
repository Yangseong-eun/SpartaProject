
#include "SpawnVolume.h"
#include "Components/BoxComponent.h"



ASpawnVolume::ASpawnVolume()
{
 
	PrimaryActorTick.bCanEverTick = false;
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	SpawningBox->SetupAttachment(Scene);
}

FVector ASpawnVolume::GetRandomPointInVolume() const //랜덤위치아는것
{
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent(); //박스 컴포넌트 크기 가져옴
	FVector BoxOrigin = SpawningBox->GetComponentLocation(); //중심좌표 계산

	return BoxOrigin + FVector( //랜덤한 좌표 값 구하기 완료
		FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z)
	);

}

void ASpawnVolume::SpawnItem(TSubclassOf<AActor> ItemClass)
{
	if (!ItemClass) return;
	GetWorld()->SpawnActor<AActor>(
		ItemClass,
		GetRandomPointInVolume(),
		FRotator::ZeroRotator
	);
}




