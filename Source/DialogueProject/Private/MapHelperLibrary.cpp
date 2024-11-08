// Fill out your copyright notice in the Description page of Project Settings.


#include "MapHelperLibrary.h"

bool UMapHelperLibrary::GetBoolMapValue(const TMap<FString, bool>& TargetMap, const FString& Key, bool& bFound)
{
    // Check if the key exists in the map
    if (const bool* FoundValue = TargetMap.Find(Key))
    {
        bFound = true;
        return *FoundValue; // Return the value found
    }

    // If key is not found
    bFound = false;
    return false; // Default return value
}

void UMapHelperLibrary::SetBoolMapValue(TMap<FString, bool>& TargetMap, const FString& Key, bool NewValue)
{
    // Attempt to get the value by reference
    if (bool* FoundValue = TargetMap.Find(Key))
    {
        *FoundValue = NewValue; // Modify the value directly if key exists
    }
}
