// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <string>
#include <Windows.h>

#define	SENSOR_FILE	1

using namespace std;

typedef struct ParseNode {		//�������� �޴� ������
	string str_id;
	float euler_x;
	float euler_y;
	float euler_z;
	float gyro_x;
	float gyro_y;
	float gyro_z;
	float acc_x;
	float acc_y;
	float acc_z;
	int battery;
} ParseNode;

/**
 * 
 */
class SENSORFUSION_API SerialPort
{
public:
	SerialPort();
	~SerialPort();

private:
	HANDLE  m_hComm;
	DCB     m_dcb;
	COMMTIMEOUTS m_CommTimeouts;
	bool    m_bPortReady;
	bool    m_bWriteRC;
	bool    m_bReadRC;
	DWORD   m_iBytesWritten;
	DWORD   m_iBytesRead;
	DWORD   m_dwBytesRead;

#ifdef SENSOR_FILE
	bool	m_bSensorFile;
#endif
public:
	ParseNode parsedata;

	bool OpenPort(LPCTSTR portname);
	void ClosePort();
	bool IsPortOpened();

	bool WriteByte(BYTE bybyte);
	bool ReadByteStr(string& buffer);

	bool SetCommunicationTimeouts(DWORD ReadIntervalTimeout,
		DWORD ReadTotalTimeoutMultiplier, DWORD ReadTotalTimeoutConstant,
		DWORD WriteTotalTimeoutMultiplier, DWORD WriteTotalTimeoutConstant);
	bool ConfigurePort(DWORD BaudRate, BYTE ByteSize, DWORD fParity,
		BYTE  Parity, BYTE StopBits);

	void Parsing(string& buffer);
};