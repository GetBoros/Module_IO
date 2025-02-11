#include "Module_IO.h"

#include "Kismet/GameplayStatics.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_MODULE ( FDefaultModuleImpl, Module_IO);  // def immplement  makes available to c++ module

// UAModule_IO
UAModule_IO::UAModule_IO()
{

}
//-------------------------------------------------------------------------------------------------------------
void UAModule_IO::Game_Save(const FTransform transform)
{
	UMySaveGame *save_game_instance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass() ) );
	if (!save_game_instance != 0)
		return;

	save_game_instance->Player_Transform = transform;

	UGameplayStatics::SaveGameToSlot(save_game_instance, TEXT("MySaveSlot"), 0);  // Save to slot class and set slot name for load
}
//-------------------------------------------------------------------------------------------------------------
void UAModule_IO::Game_Load(FTransform &transform)
{
	UMySaveGame *load_game_instance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MySaveSlot"), 0) );  // if slot valid work with it
	if (!load_game_instance != 0)
		return;

	transform = load_game_instance->Player_Transform;
}
//-------------------------------------------------------------------------------------------------------------
UAModule_IO *UAModule_IO::Module_IO_Create()
{
	return NewObject<UAModule_IO>();
}
//-------------------------------------------------------------------------------------------------------------
