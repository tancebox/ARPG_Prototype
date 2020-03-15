// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AbilityTypes.h"
#include "GameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTARPG_API UGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AbilityBase")
		UMaterialInstance* UIMaterial;
	
	UFUNCTION(BlueprintCallable, Category = "AbilityBase")
		FGameplayAbilityInfo GetAbilityInfo();



	
};
