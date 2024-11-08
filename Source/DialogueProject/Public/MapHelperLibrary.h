// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MapHelperLibrary.generated.h"
//#include "Struct_Quest.generated.h"
//#include "Journal/Struct_Quest.h"
//#include "Game/Journal/Struct_Quest.h"
#include "Engine/UserDefinedStruct.h"
/**
 * 
 */
UCLASS()
class DIALOGUEPROJECT_API UMapHelperLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
    // Template function to get a reference to the map's value by key
    template <typename KeyType, typename ValueType>
    static ValueType* GetMapValueRef(const TMap<KeyType, ValueType>& TargetMap, const KeyType& Key)
    {
        // Use Unreal's Find function to get a pointer to the value
        if (ValueType* FoundValue = TargetMap.Find(Key))
        {
            return FoundValue; // Return the pointer if the key exists
        }
        return nullptr; // Return nullptr if the key is not found
    }

    // Blueprint-accessible wrapper function for reading from TMap<FString, bool>
    UFUNCTION(BlueprintCallable, Category = "Map Helper")
    static bool GetBoolMapValue(const TMap<FString, bool>& TargetMap, const FString& Key, bool& bFound);

    // Blueprint-accessible wrapper function for modifying TMap<FString, bool>
    UFUNCTION(BlueprintCallable, Category = "Map Helper")
    static void SetBoolMapValue(UPARAM(ref) TMap<FString, bool>& TargetMap, const FString& Key, bool NewValue);

    //Test struct Func
    UFUNCTION(BlueprintCallable, Category = "Map Helper")
    static bool GetStructQuestMapValue(const TMap<FName, FStruct_Quest>& TargetMap, const FName& Key, bool& Found);
};