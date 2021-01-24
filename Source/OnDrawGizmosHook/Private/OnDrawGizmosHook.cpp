// Copyright Epic Games, Inc. All Rights Reserved.

#include "OnDrawGizmosHook.h"

#include "UnrealEdGlobals.h"
#include "Modules/ModuleManager.h"
#include "Editor/UnrealEdEngine.h"
#include "OnDrawGizmosHook/GizmoComponent.h"

#define LOCTEXT_NAMESPACE "FOnDrawGizmosHookModule"

void FOnDrawGizmosHookModule::StartupModule()
{
	GUnrealEd->RegisterComponentVisualizer(UGizmoVisComponent::StaticClass()->GetFName(), MakeShareable(new FGizmosComponentVisualizer));
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FOnDrawGizmosHookModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FOnDrawGizmosHookModule, OnDrawGizmosHook)