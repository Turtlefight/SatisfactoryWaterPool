#pragma once

#include "FGSwatchGroup.h"

#include "WaterPoolSwatchGroup.generated.h"

#define LOCTEXT_NAMESPACE "WP Swatch Group"

UCLASS()
class WATERPOOL_API UWP_PoolSwatchGroup : public UFGSwatchGroup
{
	GENERATED_BODY()
public:
	UWP_PoolSwatchGroup() {
		mGroupName = LOCTEXT("UWP_PoolSwatchGroup", "Water Pools");
	}
};

#undef LOCTEXT_NAMESPACE
