// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/euler_angles.hpp"

/**
 * 
 */
using namespace std;

const float TO_RADS = 3.141592f / 180.f;

class SENSORFUSION_API SensorData
{
public:
	SensorData();
	~SensorData();

	string sensor_id;
	//���Ϸ�
	float euler_x;
	float euler_y;
	float euler_z;
	// ���̷�
	float gyro_x;
	float gyro_y;
	float gyro_z;
	// ���ӵ�
	float acc_x;
	float acc_y;
	float acc_z;

	int battery;

private:
#if 0
	glm::mat4 m_m4ParentRotaion{ 1.f };
	glm::mat4 m_m4MyTranslate{ 1.f };
	glm::mat4 m_m4CurrentSensorRotaion{ 1.f };
	glm::mat4 m_m4MyRotaion{ 1.f };
	glm::mat4 m_m4Transform{ 1.f };
#endif
	glm::vec3 m_v3ParentRotationEuler{ 1.f };

	// 2018 8 2 Update
#if 0
	glm::vec3 m_v3MyAvgEulerAngle{ 0.f };
#endif
	glm::vec3 m_v3MyRotationEuler{ 0.f };
	glm::vec3 m_v3MyRotationDiffParent{ 0.f };

public:
	// --------------
	// ��� ���� ���
	// --------------

	// Bind Angle ���� (1000���� ������ ��� - ó�� Thread ����� Set)
	// ���� ���X
#if 0
	void SetBindAvgAngle(const glm::vec3 &i_v3AvgEulerAngle);
	void SetBindPosition(const glm::vec3& i_v3BindPostion);
#endif

	// 2018. 8. 2 �Ʒ� �� �Լ��� ���
	void Update(const glm::vec3 &i_v3ParentRotaion);
	// �ڽļ������� ���� ���� vec3ȭ �ؼ� return 
	glm::vec3 GetMyOriginalRotaion();
	// �θ𼾼��� ���� �� vec3 return
	glm::vec3 GetDiffAngle();

#if 0
	// 4. �̵�+��ȯ ����� ���� ���� Parent->Child ��ȯ��� �ϼ�
	glm::mat4 GetTransformMatrix();
	// 5. �θ��� ��ǥ�� �޾� ���� �ڽ���ǥ ����(�̶� �θ��� ��ǥ�� ������ǥ�� �� )
	glm::vec3 GetMyPosition(const glm::vec4 &i_v3ParentPos);



	// --------------
	// ���� ��ġ ���
	// --------------
	void UpdateTranslateMatrix(const glm::vec3 &i_v3MyPos);
	void UpdateRotationMatrix();
#endif
};
