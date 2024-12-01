#pragma once

#include "GameFramework/SaveGame.h"
#include "Module_IO.generated.h"     

UENUM(BlueprintType) enum class EGame_Language : uint8
{
	English UMETA(DisplayName = "English"),
	Russian UMETA(DisplayName = "Russian")
};

// UMySaveGame
UCLASS() class UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "SaveGameData") EGame_Language Game_Language;  // Change to enum
};
//-------------------------------------------------------------------------------------------------------------



// UAModule_IO
UCLASS(Blueprintable) class MODULE_IO_API UAModule_IO : public UObject
{
	GENERATED_BODY()

public:
	UAModule_IO();

	UFUNCTION(BlueprintCallable, Category = "Init") void Game_Save();
	UFUNCTION(BlueprintCallable, Category = "Init") void Game_Load();
	UFUNCTION(BlueprintCallable, Category = "Factory") static UAModule_IO *Module_IO_Create();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Init") EGame_Language Game_Language;  // Change to enum
};
//-------------------------------------------------------------------------------------------------------------

