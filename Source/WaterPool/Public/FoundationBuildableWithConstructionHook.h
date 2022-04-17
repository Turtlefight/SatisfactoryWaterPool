#pragma once

#include "Buildables/FGBuildableFoundation.h"
#include "FoundationBuildableWithConstructionHook.generated.h"

UCLASS(Abstract)
class WATERPOOL_API AWP_FoundationBuildableWithConstructionHook : public AFGBuildableFoundation {
	GENERATED_BODY()

protected:
	AWP_FoundationBuildableWithConstructionHook();

public:
	void PlayBuildEffects(AActor* inInstigator) override;
	void OnBuildEffectFinished() override;

public:
	/** true if buildable is currently playing construction effects, false otherwise */
	UPROPERTY(BlueprintReadOnly, Category="WP")
	bool mIsConstructing;
};
