

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class TUTORIALPROJECT_API ABatteryPickup : public APickup
{
	GENERATED_UCLASS_BODY()

	// set the amount of power the battery gives to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
	float PowerLevel;

	// will use the same UPROPERTY as Pickup (use _Implementation because this is a BlueprintNativeEvent)
	void OnPickedUp_Implementation() OVERRIDE;
};
