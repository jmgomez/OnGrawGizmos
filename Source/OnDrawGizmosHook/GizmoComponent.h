// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ComponentVisualizer.h"
#include "Components/ActorComponent.h"
#include "GizmoComponent.generated.h"





class FGizmosComponentVisualizer : public FComponentVisualizer {
public:
	virtual void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;
};
class UGizmoVisComponent;

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FOnGizmosSelectedDelegate, UGizmoVisComponent, OnGizmosSelected);


UCLASS(BlueprintType, Blueprintable)
class ONDRAWGIZMOSHOOK_API UGizmoVisComponent : public UActorComponent {
	GENERATED_BODY()

public:	
	UFUNCTION()
    virtual void SelectGizmo();
	
	UPROPERTY(EditAnywhere, CallInEditor, BlueprintAssignable, BlueprintReadWrite, Category = Visualizer)
	FOnGizmosSelectedDelegate OnGizmosSelected;
};




UINTERFACE()
class UDrawGizmo : public UInterface {
	GENERATED_BODY()
};
class ONDRAWGIZMOSHOOK_API IDrawGizmo {
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
	UFUNCTION(BlueprintNativeEvent, CallInEditor, Category = Visualizer)	
    void OnDrawGizmo();

};

