// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../GameInfo.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "CTestPlayerCharacter.generated.h"

UCLASS()
class SAC6_API ACTestPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	struct SkillFlag
	{
		bool EnableShield : 1 = true;
	};
public:
	// Sets default values for this character's properties
	ACTestPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere) USpringArmComponent* mArm = nullptr;
	UPROPERTY(VisibleAnywhere) UCameraComponent* mCamera = nullptr;

	// UClass정보를 저장하는 객체
	TSubclassOf<AActor> mAttackClass = nullptr;

	TSubclassOf<AActor> mShieldClass = nullptr;
	UPROPERTY(VisibleAnywhere) USceneComponent* mRotation= nullptr;
	UPROPERTY(VisibleAnywhere) URotatingMovementComponent* mRotMovement = nullptr;

	SkillFlag	mSkillFlag;
	float		mShieldTime = 0.f;
	float		mShieldCoolDown = 6.f;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void MoveAction(const FInputActionValue& Value);
	void RotationAction(const FInputActionValue& Value);
	void AttackAction(const FInputActionValue& Value);
	void ShieldAction(const FInputActionValue& Value);
	void TripleShotAction(const FInputActionValue& Value);
};
