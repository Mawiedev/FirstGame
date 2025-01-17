// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IntBox.h"
#include "VoxelInvokerComponent.generated.h"

class AVoxelWorld;

/**
 * Component to set the voxels LOD and collisions
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class VOXEL_API UVoxelInvokerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// In world space. Chunks under this distance will have the highest resolution
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel")
	float DistanceOffset = 1000;

	bool IsLocalInvoker();

	FVector GetPosition() const;
	FIntBox GetCameraBounds(const AVoxelWorld* World) const;

	virtual void OnRegister() override;

	static inline int GetChangeVersion() { return ComponentChangeVersion; }
	static const TArray<TWeakObjectPtr<UVoxelInvokerComponent>>& GetInvokers(UWorld* World) { return Components.FindOrAdd(World); }

private:
	static TMap<UWorld*, TArray<TWeakObjectPtr<UVoxelInvokerComponent>>> Components;
	static int ComponentChangeVersion;

	TSet<AVoxelWorld*> AlreadyProcessedWorlds;
};