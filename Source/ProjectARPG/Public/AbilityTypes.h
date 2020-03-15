// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityTypes.generated.h"

class UGameplayAbilityBase;

UENUM(BlueprintType)
enum class EAbilityCostType : uint8
{
	Health,
	Mana,
	Strength
};

USTRUCT(BlueprintType)
struct FGameplayAbilityInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AbilityInfo")
		float CooldownDuration;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AbilityInfo")
		float Cost;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AbilityInfo")
		EAbilityCostType CostType;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AbilityInfo")
		UMaterialInstance* UIMat;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AbilityInfo")
		TSubclassOf<UGameplayAbilityBase> AbilityClass;

	FGameplayAbilityInfo();
	FGameplayAbilityInfo(float InCooldownDuration, float InCost, EAbilityCostType InCostType, UMaterialInstance* InUIMat, TSubclassOf<UGameplayAbilityBase> InGameplayAbilityBase);

};