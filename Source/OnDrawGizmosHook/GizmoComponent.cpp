#include "GizmoComponent.h"
#include "UObject/SparseDelegate.h"

void FGizmosComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View,
                                                   FPrimitiveDrawInterface* PDI) {
	UActorComponent* ActorComponent = const_cast<UActorComponent*>(Component);
	
	UGizmoVisComponent* Comp = Cast<UGizmoVisComponent>(ActorComponent);	
	if(Comp){		
		Comp->SelectGizmo();						
	}			
}

//
// UGizmoVisComponent::UGizmoVisComponent() {	
// 	// OnGizmosSelected.AddDynamic(this, &UGizmoVisComponent::TestFunction);
// }

void UGizmoVisComponent::SelectGizmo() {	
	OnGizmosSelected.Broadcast();	

	bool bImplementsIActorVis = GetOwner()->Implements<UDrawGizmo>();	
	if (bImplementsIActorVis){	
		IDrawGizmo::Execute_OnDrawGizmo(GetOwner());		
	} else {
		GEngine->AddOnScreenDebugMessage(-1,0, FColor::Red, TEXT("The interface '' is not implemented. "));
	}
}



// void UGizmoVisComponent::SelectGizmo() const {
// 	GEngine->AddOnScreenDebugMessage(-1,0, FColor::Orange, TEXT("DRAW VIS"));
// 	bool bImplementsIActorVis = GetOwner()->Implements<UActorVisualizerInterface>();	
// 	if (bImplementsIActorVis){
// 		GEngine->AddOnScreenDebugMessage(-1,0, FColor::Orange, TEXT("DRAW VIS"));
// 		IActorVisualizerInterface::Execute_OnDrawVisualization(GetOwner());		
// 	}else {			
// 		GEngine->AddOnScreenDebugMessage(-1,0, FColor::Red, TEXT("Cannot cast the actor"));
// 	}		
// }
