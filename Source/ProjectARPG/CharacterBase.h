// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "CharacterBase.generated.h"

class UAttributeSetBase;//�ƭ��ݩ�class
class UGameplayAbilityBase;
UCLASS()
class PROJECTARPG_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		UAbilitySystemComponent* AbilitySystemComp;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")//�n���ޯ�
		void AquireAbility(TSubclassOf<UGameplayAbility> AbilityToAquire);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")//�n���ޯ��
		void AquireAbilities(TArray<TSubclassOf<UGameplayAbility>> AbilityToAquire);

	/*�ƭȨt��*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		UAttributeSetBase* AttributeSetBaseComp;
	UFUNCTION()
		void OnHealthChanged(float Health, float MaxHealth);
	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "OnHealthChanged"))
		void BP_OnHealthChanged(float Health, float MaxHealth);
	UFUNCTION()//Mana
		void OnManaChanged(float Mana, float MaxMana);
	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "OnManaChanged"))
		void BP_OnManaChanged(float Mana, float MaxMana);

	/*UFUNCTION()//Strength
		void OnStrengthChanged(float Strength, float MaxStrength);
	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "OnStrengthChanged"))
		void BP_OnStrengthChanged(float Strength, float MaxStrength);*/


	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "Die"))
		void BP_Die();
	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "GetHit"))
		void BP_GetHit();
	/*����ID*/
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		bool IsOtherHostile(ACharacterBase* Other);

	uint8 GetTeamID() const;

	//����"���媬�A"��
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void AddGameplayTag(FGameplayTag TagToAdd);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void RemoveGameplayTag(FGameplayTag TagToRemove);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		FGameplayTag FullHealthTag;

	//Dash Stun
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void HitStun(float StunDuration);

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void ApplyGESpecHandleToTargetDataSpecHandle(const FGameplayEffectSpecHandle& GESpecHandle, const FGameplayAbilityTargetDataHandle& TargetDataHandle);

protected:
	bool bIsDead;
	uint8 TeamID;

	void AutoDeterminTeamIDbyControllerType();
	void Dead();

	void DisableinputControl();
	void EnableInputControl();
	FTimerHandle StunTimeHandle;
	void AddAbilityToUI(TSubclassOf<UGameplayAbilityBase> AbilityToAdd);//�N�ޯ�[�iUI

};
