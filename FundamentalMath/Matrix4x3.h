#ifndef _MATRIX4X3_H_
#define _MATRIX4X3_H_

class Vector3;
class EulerAngles;
class RotationMatrix;
class Quaternion;


class Matrix4x3
{
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;
	float tx, ty, tz;

	void identity();

	//ֱ�ӷ���ƽ�Ʋ���
	void zeroTranslation();

	//ƽ�Ʋ��ָ�ֵ
	void setTranslation(const Vector3& d);

	//���Ա任������Ϊ��λ����ƽ�Ʋ��ָ�ֵ
	void setupTranslation(const Vector3& d);
	
	/*����һ�������ܽ���Ӿֲ�����ռ�任�����ռ����ꡣ
	 *���ȴ�����ռ�任�����Կռ䣬���ű任������ռ�*/
	void setupLocalToParent(const Vector3& pos, const EulerAngles& orient);
	void setupLocalToParent(const Vector3& pos, const RotationMatrix& orient);

	/*����Ӹ��ռ䵽�ֲ��ռ�ľ������ȴ�����ռ�ת�������Կռ䣬����ת��������ռ�*/
	void setupParentToLocal(const Vector3& pos, const EulerAngles& orient);
	void setupParentToLocal(const Vector3& pos, const RotationMatrix& orient);

	//��������������ת�ľ���

	void setupRotate(int axis, float theta);
	void setupRotate(const Vector3& axis, float theta);
	
	//������ת���󣬽�λ������Ԫ����ʽ����
	void fromQuaternion(const Quaternion& q); 

	//���������������ŵľ���
	void setupScale(const Vector3& s);

	// ���������������ŵľ���
	void setupScaleAlongAxis(const Vector3& axis, float k);

	//�����б����
	void setupShear(int axis, float s, float t);

	//����ͶӰ����ͶӰƽ���ԭ��
	void setupProject(const Vector3& n);

	//���췴�����
	void setupReflect(int axis, float k = 0.0f);

	//����������ƽ�淴��ľ���

	void setupReflect(const Vector3& n);

};

Vector3 operator*(const Vector3& p, const Matrix4x3& m);
Matrix4x3 operator*(const Matrix4x3& a, const Matrix4x3& b);

Vector3&   operator*=(Vector3& p, const Matrix4x3& m);
Matrix4x3& operator*=(const Matrix4x3& a, const Matrix4x3& m);

//����3x3���ֵ�����ʽ
float determinant(const Matrix4x3& m);

//����������
Matrix4x3 inverse(const Matrix4x3& m);

//��ȡ�����ƽ�Ʋ���

Vector3 getTranslation(const Matrix4x3& m);

//�Ӿֲ�����->������ �� ������->�ֲ����� ȡλ��/��λ
Vector3 getPositionFromLocalToParentMatrix(const Matrix4x3& m);
Vector3 getPositionFromParentToLocalMatrix(const Matrix4x3& m);



#endif