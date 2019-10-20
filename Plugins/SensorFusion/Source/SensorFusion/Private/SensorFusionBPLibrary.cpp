// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SensorFusionBPLibrary.h"
#include "SensorFusionEngine.h"

SensorFusionEngine g_sensorFusion;


USensorFusionBPLibrary::USensorFusionBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

bool USensorFusionBPLibrary::Connect()
{
	UE_LOG(LogTemp, Warning, TEXT("++++++ USensorFusionBPLibrary::Connect()"));

	g_sensorFusion.Connect();

	return true;
}

void USensorFusionBPLibrary::Disconnect()
{
	UE_LOG(LogTemp, Warning, TEXT("++++++ USensorFusionBPLibrary::Disconnect()"));

	g_sensorFusion.Disconnect();

	return;
}

bool USensorFusionBPLibrary::IsConnected()
{
	return g_sensorFusion.IsConnected();
}

void USensorFusionBPLibrary::SetRootSensorTransform(UPARAM(ref) FTransform& rootTransform)
{
	g_sensorFusion.SetRootSensorTransform(rootTransform);

	return;
}

FTransform USensorFusionBPLibrary::GetRootSensorTransform()
{
	FTransform tf;

	g_sensorFusion.GetRootSensorTransform(tf);

	return tf;
}


FTransform USensorFusionBPLibrary::GetSensorTransform(int idxSensor)
{
	FTransform tf;

	g_sensorFusion.GetSensorTransform(idxSensor, tf);

	return tf;
}

FTransform USensorFusionBPLibrary::MakeTransformWithSensor(UPARAM(ref) FTransform& curTransform, int idxSensor)
{
	FTransform tf;

	tf = curTransform;
	g_sensorFusion.GetSensorTransform(idxSensor, tf);

	return tf;
}
