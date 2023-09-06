// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterBlueprintFunctionLibrary.h"
#include "Misc/Paths.h"

bool UBlasterBlueprintFunctionLibrary::FileSaveString(FString SaveTextB, FString FileNameB)
{
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameSourceDir() + FileNameB));
}

bool UBlasterBlueprintFunctionLibrary::FileLoadString(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameSourceDir() + FileNameA));
}

