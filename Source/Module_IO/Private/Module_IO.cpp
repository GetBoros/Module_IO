#include "Module_IO.h"

#include "Kismet/GameplayStatics.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_MODULE ( FDefaultModuleImpl, Module_IO);  // def immplement  makes available to c++ module

// UAModule_IO
UAModule_IO::UAModule_IO()
{
	//UMySaveGame* SaveGame = NewObject<UMySaveGame>();
	//SaveGame->Player_Experience = 100.0f;
	//SaveGame->Player_Attributes = { 1.0f, 2.0f, 3.0f };
	//SaveGame->SaveToFile("SaveSlot1");

}
//-------------------------------------------------------------------------------------------------------------
float UAModule_IO::GAS_Attributes_Load()
{
	UMySaveGame *load_game_instance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MySaveSlot"), 0) );  // if slot valid work with it
	if (!load_game_instance != 0)
		return 0.0f;

	return load_game_instance->Player_Experience;
}
//-------------------------------------------------------------------------------------------------------------
void UAModule_IO::GAS_Attributes_Save(float &array)
{
	UMySaveGame *save_game_instance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MySaveSlot"), 0) );

	if (!save_game_instance != 0)
		save_game_instance = NewObject<UMySaveGame>();

	save_game_instance->Player_Experience = array;

	UGameplayStatics::SaveGameToSlot(save_game_instance, TEXT("MySaveSlot"), 0);  // Save to slot class and set slot name for load
}
//-------------------------------------------------------------------------------------------------------------
FTransform UAModule_IO::Pawn_Transform_Load()
{
	UMySaveGame *load_game_instance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MySaveSlot"), 0) );  // if slot valid work with it
	if (!load_game_instance != 0)
		return FTransform {};

	return load_game_instance->Player_Transform;
}
//-------------------------------------------------------------------------------------------------------------
void UAModule_IO::Pawn_Transform_Save(const FTransform &transform)
{
	UMySaveGame *save_game_instance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MySaveSlot"), 0) );
	
	if (!save_game_instance != 0)
		save_game_instance = NewObject<UMySaveGame>();

	save_game_instance->Player_Transform = transform;

	UGameplayStatics::SaveGameToSlot(save_game_instance, TEXT("MySaveSlot"), 0);  // Save to slot class and set slot name for load
}
//-------------------------------------------------------------------------------------------------------------
UAModule_IO *UAModule_IO::Module_IO_Create()
{
	return NewObject<UAModule_IO>();
}
//-------------------------------------------------------------------------------------------------------------
