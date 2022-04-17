#include "WP_Library.h"
#include "WaterPoolModule.h"

#include "FGGameState.h"

void UWPBlueprintLibrary::RegisterSwatchGroupDefaultSwatch(UObject* WorldContextObject, TSubclassOf<UFGSwatchGroup> SwatchGroup, TSubclassOf<UFGFactoryCustomizationDescriptor_Swatch> Swatch) {
	check(SwatchGroup);
	check(Swatch);
	
	AFGGameState* gameState = Cast<AFGGameState>(UGameplayStatics::GetGameState(WorldContextObject));
	if (gameState) {
		// Check if the group is already registered
		for (FSwatchGroupData data : gameState->mSwatchGroupDatum) {
			if (data.SwatchGroup == SwatchGroup)
				return;
		}

		FSwatchGroupData entry;
		entry.Swatch = Swatch;
		entry.SwatchGroup = SwatchGroup;
		gameState->mSwatchGroupDatum.Add(entry);
		gameState->mSwatchGroupFallbackDatum.Add(entry);
		gameState->SetDefaultSwatchForBuildableGroup(SwatchGroup, Swatch);
	}
}

UFGColoredInstanceMeshProxy* UWPBlueprintLibrary::AddInstancedMesh(AActor* Building, UStaticMesh* Mesh, FTransform const& Transform, EDistanceCullCategory OptimizationCategory) {
	UFGColoredInstanceMeshProxy* instanceMeshProxy = NewObject<UFGColoredInstanceMeshProxy>(
		Building,
		UFGColoredInstanceMeshProxy::StaticClass(),
		NAME_None,
		RF_NoFlags,
		nullptr,
		false,
		nullptr
	);

	instanceMeshProxy->SetStaticMesh(Mesh);
	instanceMeshProxy->SetOptimizationCategory(OptimizationCategory);
	instanceMeshProxy->mBlockInstancing = false;

	instanceMeshProxy->SetupAttachment(Building->GetRootComponent());
	instanceMeshProxy->SetMobility(EComponentMobility::Static);
	instanceMeshProxy->SetRelativeTransform(Transform);
	instanceMeshProxy->RegisterComponent();
	instanceMeshProxy->SetInstanced(true);

	return instanceMeshProxy;
}
