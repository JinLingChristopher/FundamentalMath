#ifndef _QUATERNION_H_
#define _QUATERNION_H_

class Vector3;
class EulerAngles;

class Quaternion
{
public:
	float w, x, y, z;

	void identity()
	{
		w = 1.0f;
		x = y = z = 0.0f;
	}

	void setToRotateAboutX(float theta);
	void setToRotateAboutY(float theta);
	void setToRotateAboutZ(float theta);
	void setToRotateAboutAxis(const Vector3& axis, float theta);

	void setToRotateObjectToInertial(const EulerAngles& orientation);
	void setToRotateInertialToObject(const EulerAngles& orientation);

	//���
	Quaternion operator*(const Quaternion& rhs) const;
	Quaternion& operator*=(const Quaternion& rhs);

	//����
	void normalize();

	//��ȡ��ת�Ǻ���ת��
	float getRotationAngle() const;
	Vector3 getRotationAxis() const;
	
};


//ȫ�ֵ�λ��Ԫ��
extern const Quaternion kQuaternionIdentity;

//��Ԫ�����
extern float dotProduct(const Quaternion& lhs, const Quaternion& rhs);

//�������Բ�ֵ
extern Quaternion slerp(const Quaternion& f, const Quaternion& l, float t); 

//��Ԫ������
extern Quaternion conjugate(const Quaternion& q);

//��Ԫ����
extern Quaternion pow(const Quaternion& q, float exponent);

#endif