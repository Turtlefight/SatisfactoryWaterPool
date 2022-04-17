#include "FoundationBuildableWithConstructionHook.h"

AWP_FoundationBuildableWithConstructionHook::AWP_FoundationBuildableWithConstructionHook() : Super(), mIsConstructing(false) {

}

void AWP_FoundationBuildableWithConstructionHook::PlayBuildEffects(AActor* inInstigator) {
	mIsConstructing = true;
	Super::PlayBuildEffects(inInstigator);
}

void AWP_FoundationBuildableWithConstructionHook::OnBuildEffectFinished() {
	mIsConstructing = false;
	Super::OnBuildEffectFinished();
}
