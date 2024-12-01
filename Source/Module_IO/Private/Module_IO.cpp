#include "Module_IO.h"

#include "Kismet/GameplayStatics.h"
#include "Modules/ModuleManager.h"

// def immplement  makes available to c++ module
IMPLEMENT_MODULE ( FDefaultModuleImpl, Module_IO);


// UAModule_IO
UAModule_IO::UAModule_IO()
 : Game_Language(EGame_Language::Russian)
{

}
//-------------------------------------------------------------------------------------------------------------
void UAModule_IO::Game_Save()
{
	UMySaveGame *save_game_instance;

	save_game_instance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass() ) );
	if (!save_game_instance != 0)
		return;

	save_game_instance->Game_Language = Game_Language;

	UGameplayStatics::SaveGameToSlot(save_game_instance, TEXT("MySaveSlot"), 0);      
}
//-------------------------------------------------------------------------------------------------------------
void UAModule_IO::Game_Load()
{
	UMySaveGame *load_game_instance;

	load_game_instance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MySaveSlot"), 0) );
	if (!load_game_instance != 0)
		return;

	Game_Language = load_game_instance->Game_Language;
}
//-------------------------------------------------------------------------------------------------------------
UAModule_IO *UAModule_IO::Module_IO_Create()
{
	return NewObject<UAModule_IO>();;
}
//-------------------------------------------------------------------------------------------------------------
