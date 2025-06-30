#pragma once

#include "GameFramework/SaveGame.h"
#include "Module_IO_Handler.generated.h"     

//-------------------------------------------------------------------------------------------------------------
UCLASS() class UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "Save_Game_Data") float Player_Experience;  // Change to enum
	UPROPERTY(VisibleAnywhere, Category = "Save_Game_Data") FTransform Player_Transform;  // Change to enum
	UPROPERTY(VisibleAnywhere, Category = "Save_Game_Data") TArray<float> Player_Attributes;
};
//-------------------------------------------------------------------------------------------------------------
UCLASS(Blueprintable) class MODULE_IO_API UAModule_IO_Handler : public UObject
{
	GENERATED_BODY()

public:
	UAModule_IO_Handler();

	UFUNCTION(BlueprintCallable, Category = "Init") void GAS_Attributes_Load(TArray<float> &player_attributes);
	UFUNCTION(BlueprintCallable, Category = "Init") void GAS_Attributes_Save(TArray<float> &player_attributes);

	UFUNCTION(BlueprintCallable, Category = "Init") FTransform Pawn_Transform_Load();
	UFUNCTION(BlueprintCallable, Category = "Init") void Pawn_Transform_Save(const FTransform &transform);

	UFUNCTION(BlueprintCallable, Category = "Init") static UAModule_IO_Handler *Module_IO_Create();  // Need to create object in BP for call func
};
//-------------------------------------------------------------------------------------------------------------

