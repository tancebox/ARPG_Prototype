// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeSetBase.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChange, float, Health, float, MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnManaChange, float, Mana, float, MaxMana);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStrengthChange, float, Strength, float, MaxStrength);

UCLASS()
class PROJECTARPG_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

		

public:
	UAttributeSetBase();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData Mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData MaxMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData MaxStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		float MaxHealthValue=150.0f;


	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	FOnHealthChange OnHealthChange;
	FOnManaChange OnManaChange;
	//FOnStrengthChange OnStrengthChange;

	//由外部設定角色進場能力
	UFUNCTION(BlueprintCallable, Category = "AttributeSetBase")
		void SetActorHealth(float newHealth);

	//由外部設定角色進場能力
	UFUNCTION(BlueprintCallable, Category = "AttributeSetBase")
		void UpdateActorAttr();

};
