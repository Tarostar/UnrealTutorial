// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/SpringArmComponent.h"
#include "TutorialProjectCharacter.generated.h"

UCLASS(config=Game)
class ATutorialProjectCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	TSubobjectPtr<class USpringArmComponent> CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	TSubobjectPtr<class UCameraComponent> FollowCamera;

	// sphere for range batteries can be collected
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Power)
	TSubobjectPtr<class USphereComponent> CollectionSphere;

	// character power level
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Power)
	float PowerLevel;

	// power multiplier for the character speed
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Power)
	float SpeedFactor;

	// baseline speed of character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Power)
	float BaseSpeed;

	// common to override tick for frame based behaviours
	virtual void Tick(float DeltaSeconds) OVERRIDE;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	// called when we press a key to collect any batteries inside the Spherecomponent
	UFUNCTION(BlueprintCallable, Category=Power)
	void CollectBatteries();

	// called by CollectBatteries to use Blueprinted PowerUp functionality
	UFUNCTION(BlueprintImplementableEvent, Category = Power)
	void PowerUp(float BatteryPower);

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface
};

