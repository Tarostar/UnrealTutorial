

#include "TutorialProject.h"
#include "BatteryPickup.h"


ABatteryPickup::ABatteryPickup(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// base battery power level
	PowerLevel = 150.0;
}


void ABatteryPickup::OnPickedUp_Implementation()
{
	// first calls parent implementation of OnPickedUp
	Super::OnPickedUp_Implementation();
	// destroy the battery
	Destroy();



}