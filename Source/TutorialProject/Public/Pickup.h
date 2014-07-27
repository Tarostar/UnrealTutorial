

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class TUTORIALPROJECT_API APickup : public AActor
{
	GENERATED_UCLASS_BODY()

	// true when pickup can be picked up, false if pickup is deactivated
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	bool bIsActive;

	// simple collision primitie to use as root component
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pickup)
	TSubobjectPtr<USphereComponent> BaseCollisionComponent;
	
	// static mesh component to represent the pickup in the level
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pickup)
	TSubobjectPtr<UStaticMeshComponent> PickupMesh;

	// set behaviour for when picked up
	UFUNCTION(BlueprintNativeEvent)
	void OnPickedUp();
};
