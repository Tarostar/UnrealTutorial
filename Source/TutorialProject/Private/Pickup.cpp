

#include "TutorialProject.h"
#include "Pickup.h"


APickup::APickup(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	// pickup valid when created
	bIsActive = true;

	// create root SphereComponent to handle pickup's collision
	BaseCollisionComponent = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("BaseSphereComponent"));

	// set the SphereComponent as root
	RootComponent = BaseCollisionComponent;

	// create static mesh component
	PickupMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMesh"));

	// turn physics on for the static mesh
	PickupMesh->SetSimulatePhysics(true);

	// attach static mesh component to root component
	PickupMesh->AttachTo(RootComponent);
}

void APickup::OnPickedUp_Implementation()
{
	// there is no default behaviour...
	// use _IMPLEMENTATION because of UFUNCTION(BlueprintNativeEvent)

}