// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlasterBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API UBlasterBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Save")
	static bool FileSaveString(FString SaveTextB, FString FileNameB);

	UFUNCTION(BlueprintPure, Category = "Save")
	static bool FileLoadString(FString FileNameA, FString& SaveTextA);
	
};
