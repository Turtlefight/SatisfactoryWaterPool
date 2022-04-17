#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FGSwatchGroup.h"
#include "FGColoredInstanceMeshProxy.h"

#include "WP_Library.generated.h"

UCLASS()
class WATERPOOL_API UWPBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="WP", meta=(WorldContext="WorldContextObject"))
	static void RegisterSwatchGroupDefaultSwatch(UObject* WorldContextObject, TSubclassOf<UFGSwatchGroup> SwatchGroup, TSubclassOf<UFGFactoryCustomizationDescriptor_Swatch> Swatch);

	UFUNCTION(BlueprintCallable, Category="WP")
	static UFGColoredInstanceMeshProxy* AddInstancedMesh(AActor* Building, UStaticMesh* Mesh, FTransform const& Transform, EDistanceCullCategory OptimizationCategory);
};
