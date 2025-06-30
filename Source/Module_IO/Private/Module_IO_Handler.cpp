#include "Module_IO_Handler.h"
#include "Module_IO.h"

// UAModule_IO_Handler
UAModule_IO_Handler::UAModule_IO_Handler()
{

}
//-------------------------------------------------------------------------------------------------------------
void UAModule_IO_Handler::GAS_Attributes_Load(TArray<float> &player_attributes)
{
	UMySaveGame *load_game_instance;

	player_attributes.SetNumZeroed(4);

	load_game_instance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MySaveSlot"), 0) );  // if slot valid work with it
	if (!load_game_instance != 0)
		return;

	player_attributes = load_game_instance->Player_Attributes;
}
//-------------------------------------------------------------------------------------------------------------
void UAModule_IO_Handler::GAS_Attributes_Save(TArray<float> &player_attributes)
{
	UMySaveGame *save_game_instance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MySaveSlot"), 0) );

	if (!save_game_instance != 0)
		save_game_instance = NewObject<UMySaveGame>();

	save_game_instance->Player_Attributes = player_attributes;

	UGameplayStatics::SaveGameToSlot(save_game_instance, TEXT("MySaveSlot"), 0);  // Save to slot class and set slot name for load
}
//-------------------------------------------------------------------------------------------------------------
FTransform UAModule_IO_Handler::Pawn_Transform_Load()
{
	UMySaveGame *load_game_instance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MySaveSlot"), 0) );  // if slot valid work with it
	if (!load_game_instance != 0)
		return FTransform {};

	return load_game_instance->Player_Transform;
}
//-------------------------------------------------------------------------------------------------------------
void UAModule_IO_Handler::Pawn_Transform_Save(const FTransform &transform)
{
	UMySaveGame *save_game_instance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MySaveSlot"), 0) );
	
	if (!save_game_instance != 0)
		save_game_instance = NewObject<UMySaveGame>();

	save_game_instance->Player_Transform = transform;

	UGameplayStatics::SaveGameToSlot(save_game_instance, TEXT("MySaveSlot"), 0);  // Save to slot class and set slot name for load
}
//-------------------------------------------------------------------------------------------------------------
UAModule_IO_Handler *UAModule_IO_Handler::Module_IO_Create()
{
	return NewObject<UAModule_IO_Handler>();
}
//-------------------------------------------------------------------------------------------------------------
