// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sensor.h"
#include "SensorData.h"
#include <string>
#include <vector>
#include <map>

// SensorFusion General Log
DECLARE_LOG_CATEGORY_EXTERN(LogSensorFusion, Log, All);

/**
 * @class SensorFusionEngine
 *
 */
class SENSORFUSION_API SensorFusionEngine
{
public:
	SensorFusionEngine();
	~SensorFusionEngine();

	bool Connect();
	void Disconnect();
	bool IsConnected();
	void SetRootSensorTransform(FTransform &rootTransform);
	bool GetRootSensorTransform(FTransform &targetTransform);
	bool GetSensorTransform(int sensorIdx, FTransform& targetTransform);

	static DWORD ReadThread(LPVOID lpParameter);
private:
	bool LoadSettings();
	int ReadData();
	void Update();
	bool SensorData2FTransform(SensorData *pData, FTransform& targetTransform, bool bRoot=false);

	std::string TCHAR2String(const TCHAR *src);
	HANDLE m_hThread;

	int	m_sensorCnt;
	FString m_comPort;
	SensorData m_rootData;
	vector<SensorData *> m_sensorData;
public:
	Sensor m_serialPort;//
};
