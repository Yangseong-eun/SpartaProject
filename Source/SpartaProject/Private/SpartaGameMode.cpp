#include "SpartaGameMode.h"
#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"

ASpartaGameMode::ASpartaGameMode()
{
	DefaultPawnClass = ASpartaCharacter::StaticClass(); //객체 생성하지 않고 클래스 반환 
	PlayerControllerClass = ASpartaPlayerController::StaticClass();
}
