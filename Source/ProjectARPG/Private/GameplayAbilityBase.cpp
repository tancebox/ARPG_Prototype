// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilityBase.h"


FGameplayAbilityInfo UGameplayAbilityBase::GetAbilityInfo()
{
	UGameplayEffect* CoolDownEffect = GetCooldownGameplayEffect();
	UGameplayEffect* CostEffect = GetCostGameplayEffect();
	if (CoolDownEffect && CostEffect)
	{
		float CoolDownDuration = 0;
		CoolDownEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(1, CoolDownDuration);
		float Cost = 0;
		EAbilityCostType CostType;
		if (CostEffect->Modifiers.Num() > 0)
		{
			FGameplayModifierInfo EffectInfo = CostEffect->Modifiers[0];
			EffectInfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(1, Cost);
			FGameplayAttribute CostAttr = EffectInfo.Attribute;
			FString AttrributeName = CostAttr.AttributeName;
			if (AttrributeName == "Health")
			{
				CostType = EAbilityCostType::Health;
			}else if(AttrributeName == "Nama")
			{
				CostType = EAbilityCostType::Mana;
			}
			else if (AttrributeName == "Strength")
			{
				CostType = EAbilityCostType::Strength;
			}
			return FGameplayAbilityInfo(CoolDownDuration, Cost, CostType, UIMaterial, GetClass());
		}
	}
	return FGameplayAbilityInfo();
}