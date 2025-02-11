#pragma once

#include "GameFramework/SaveGame.h"
#include "Module_IO.generated.h"     

//-------------------------------------------------------------------------------------------------------------
UCLASS() class UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "Save_Game_Data") FTransform Player_Transform;  // Change to enum
};
//-------------------------------------------------------------------------------------------------------------
UCLASS(Blueprintable) class MODULE_IO_API UAModule_IO : public UObject
{
	GENERATED_BODY()

public:
	UAModule_IO();

	UFUNCTION(BlueprintCallable, Category = "Init") void Game_Save(const FTransform transform);
	UFUNCTION(BlueprintCallable, Category = "Init") void Game_Load(FTransform &transform);

	UFUNCTION(BlueprintCallable, Category = "Init") static UAModule_IO *Module_IO_Create();  // Need to create object in BP for call func
};
//-------------------------------------------------------------------------------------------------------------

