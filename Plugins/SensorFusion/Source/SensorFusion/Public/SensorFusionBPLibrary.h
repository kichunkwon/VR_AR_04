// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
//#include "SensorFusionEngine.h"
#include "SensorFusionBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class USensorFusionBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ConnectToSensor", Keywords = ""), Category = "SensorFusion")
		static bool Connect();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "DisconnectFromSensor", Keywords = ""), Category = "SensorFusion")
		static void Disconnect();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsSensorConnected", Keywords = ""), Category = "SensorFusion")
		static bool IsConnected();

	// Root
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetRootSensorTransform", Keywords = ""), Category = "SensorFusion")
		static void SetRootSensorTransform(UPARAM(ref) FTransform& rootTransform);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetRootSensorTransform", Keywords = ""), Category = "SensorFusion")
		static FTransform GetRootSensorTransform();

	// Others
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetSensorTransform", Keywords = ""), Category = "SensorFusion")
		static FTransform GetSensorTransform(int idxSensor);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MakeTransformFromSensor", Keywords = ""), Category = "SensorFusion")
		static FTransform MakeTransformWithSensor(UPARAM(ref) FTransform& curTransform, int idxSensor=0);

};
