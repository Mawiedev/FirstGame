// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"

class FAdvancedPreviewScene;
class FVoxelGraphCompiler;

class IVoxelGraphEditorToolkit : public FAssetEditorToolkit
{
public:
	/** Returns the Voxel asset inspected by the editor */
	virtual UVoxelGraphGenerator* GetWorldGenerator() const = 0;

	/** Assigns the currently selected nodes to the property control */
	virtual void SetSelection(TArray<UObject*> SelectedObjects) = 0;

	/** Checks whether nodes can currently be pasted */
	virtual bool CanPasteNodes() const = 0;

	/** Paste nodes at a specific location */
	virtual void PasteNodesHere(const FVector2D& Location) = 0;

	/** Get the bounding area for the currently selected nodes
	*
	* @param Rect Final output bounding area, including padding
	* @param Padding An amount of padding to add to all sides of the bounds
	*
	* @return false if nothing is selected*/
	virtual bool GetBoundsForSelectedNodes(class FSlateRect& Rect, float Padding) = 0;

	/** Gets the number of nodes that are currently selected */
	virtual int32 GetNumberOfSelectedNodes() const = 0;

	/** Get the currently selected set of nodes */
	virtual TSet<UObject*> GetSelectedNodes() const = 0;

	virtual void SelectNodesAndZoomToFit(TArray<UEdGraphNode*>& Nodes) = 0;

	virtual void TriggerUpdatePreview(bool bForce, bool bUpdateTextures) = 0;

	virtual FAdvancedPreviewScene* GetPreviewScene() const = 0;

	virtual void SetDebugGraph(FVoxelGraphCompiler* Compiler) = 0;
};
