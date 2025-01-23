// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaPlayerController.h"
#include "EnhancedInputSubsystems.h"

ASpartaPlayerController::ASpartaPlayerController()
	:InputMappingContext(nullptr),
	 MoveAction(nullptr),
	 LookAction(nullptr),
	 JumpAction(nullptr),
	 SprintAction(nullptr)
{

}

void ASpartaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer()) //로컬 플레이어: 사용자가 하는 플레이어의 로컬 플레이어 객체를 가져오라는 의미. 
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				SubSystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}
