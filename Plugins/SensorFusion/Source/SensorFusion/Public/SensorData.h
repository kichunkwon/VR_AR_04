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
	//오일러
	float euler_x;
	float euler_y;
	float euler_z;
	// 자이로
	float gyro_x;
	float gyro_y;
	float gyro_z;
	// 가속도
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
	// 상대 각도 계산
	// --------------

	// Bind Angle 설정 (1000개의 데이터 평균 - 처음 Thread 실행시 Set)
	// 아직 사용X
#if 0
	void SetBindAvgAngle(const glm::vec3 &i_v3AvgEulerAngle);
	void SetBindPosition(const glm::vec3& i_v3BindPostion);
#endif

	// 2018. 8. 2 아래 세 함수만 사용
	void Update(const glm::vec3 &i_v3ParentRotaion);
	// 자식센서에서 나온 값을 vec3화 해서 return 
	glm::vec3 GetMyOriginalRotaion();
	// 부모센서의 값을 뺀 vec3 return
	glm::vec3 GetDiffAngle();

#if 0
	// 4. 이동+변환 행렬을 곱해 최종 Parent->Child 변환행렬 완성
	glm::mat4 GetTransformMatrix();
	// 5. 부모의 좌표를 받아 최종 자식좌표 구함(이때 부모의 좌표는 동차좌표계 ㅠ )
	glm::vec3 GetMyPosition(const glm::vec4 &i_v3ParentPos);



	// --------------
	// 실제 위치 계산
	// --------------
	void UpdateTranslateMatrix(const glm::vec3 &i_v3MyPos);
	void UpdateRotationMatrix();
#endif
};
