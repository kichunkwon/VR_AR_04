// Fill out your copyright notice in the Description page of ProjectSen Settings.

#include "SensorData.h"

SensorData::SensorData()
{
}

SensorData::~SensorData()
{
}

#if 0
float ToRadian(const float& i_fDegreeAngle) {
	return i_fDegreeAngle * TO_RADS;
}

void SensorData::SetBindAvgAngle(const glm::vec3 &i_v3AvgEulerAngle) {
	m_v3MyAvgEulerAngle = i_v3AvgEulerAngle;
}

void SensorData::UpdateTranslateMatrix(const glm::vec3 &i_v3MyPos) {
	m_m4MyTranslate[0][3] = i_v3MyPos.x;
	m_m4MyTranslate[1][3] = i_v3MyPos.y;
	m_m4MyTranslate[2][3] = i_v3MyPos.z;
}

void SensorData::SetBindPosition(const glm::vec3& i_v3BindPostion) {

}
#endif


void SensorData::Update(const glm::vec3 &i_v3ParentRotaion) {
	// Set Parent Rotaion vec3
	m_v3ParentRotationEuler = i_v3ParentRotaion;

	// Set my rotation(Original) vec3
	m_v3MyRotationEuler.x = euler_x;
	m_v3MyRotationEuler.y = euler_y;
	m_v3MyRotationEuler.z = euler_z;

	// Set my rotation (between parent) vec3
	m_v3MyRotationDiffParent = m_v3ParentRotationEuler - m_v3MyRotationEuler;

	//

}

glm::vec3 SensorData::GetDiffAngle() {
	return m_v3MyRotationDiffParent;
}

glm::vec3 SensorData::GetMyOriginalRotaion() {
	return m_v3MyRotationEuler;
}

#if 0
glm::mat4 SensorData::GetTransformMatrix() {
	m_m4Transform *= m_m4MyTranslate;
	m_m4Transform *= m_m4MyRotaion;
	return m_m4Transform;
}

glm::vec3 SensorData::GetMyPosition(const glm::vec4 &i_v3ParentPos) {
	glm::vec3 v3ReturnValue = m_m4Transform * i_v3ParentPos;
	return v3ReturnValue;
}

void SensorData::UpdateRotationMatrix() {
	// 우선 센서에서 나온 값을 기반으로 Rotaion행렬을 만들어 줘야한다. 

	glm::mat4 m4RotationX{ 1.f };
	glm::mat4 m4RotationY{ 1.f };
	glm::mat4 m4RotationZ{ 1.f };

	// --------------------------
	// X Rotation
	// 0행
	m4RotationX[0][0] = 1.f;
	m4RotationX[1][0] = 0.f;
	m4RotationX[2][0] = 0.f;
	// 1행
	m4RotationX[0][1] = 0.f;
	m4RotationX[1][1] = cos(euler_x);
	m4RotationX[2][1] = -sin(euler_x);
	// 2행
	m4RotationX[0][2] = 0.f;
	m4RotationX[1][2] = sin(euler_x);
	m4RotationX[2][2] = cos(euler_x);

	// --------------------------
	// Y Rotation
	// 0행
	m4RotationY[0][0] = cos(euler_y);
	m4RotationY[1][0] = 0.f;
	m4RotationY[2][0] = sin(euler_y);
	// 1행
	m4RotationY[0][1] = 0.f;
	m4RotationY[1][1] = 1.f;
	m4RotationY[2][1] = 0.f;
	// 2행
	m4RotationY[0][2] = -sin(euler_y);
	m4RotationY[1][2] = 0.f;
	m4RotationY[2][2] = cos(euler_y);

	// --------------------------
	// Z Rotation
	// 0행
	m4RotationZ[0][0] = cos(euler_z);
	m4RotationZ[1][0] = -sin(euler_z);
	m4RotationZ[2][0] = 0.f;
	// 1행
	m4RotationZ[0][1] = sin(euler_z);
	m4RotationZ[1][1] = cos(euler_z);
	m4RotationZ[2][1] = 0.f;
	// 2행
	m4RotationZ[0][2] = 0.f;
	m4RotationZ[1][2] = 0.f;
	m4RotationZ[2][2] = 1.f;

	m_m4CurrentSensorRotaion = m4RotationX * m4RotationY * m4RotationZ;

	// 이후 부모의 역행렬을 곱해줘야한다. 
	m_m4MyRotaion = m_m4CurrentSensorRotaion * glm::inverse(m_m4ParentRotaion);
}
#endif