#ifndef _AABB3_H_
#define _AABB3_H_

#include "vector3.h"

class Matrix4x3;

class AABB3
{
public:
	Vector3 min;
	Vector3 max;

public:

	Vector3 size()
	{
		return max - min;
	}
	float xSize()
	{
		return max.x - min.x;
	}
	float ySize()
	{
		return max.y - min.y;
	}
	float zSize()
	{
		return max.z - min.z;
	}
	Vector3 center() const
	{
		return (min + max)*0.5f;
	}
	
	//��ȡ8�������е�һ��
	Vector3 corner(int i) const;

	//empty the AABB
	void empty();

	//Add the point into AABB3
	void add(const Vector3& p);
	
	//����α߽�������AABB
	void add(const AABB3& box);
	
	//�任���α߽�򣬼����µ�AABB
	void setToTransformedBox(const AABB3& box, const Matrix4x3& m);

	//�������ཻ�Բ���
	bool isEmpty() const;
	
	//�жϾ��α߽���Ƿ�����˵�
	bool contains(const Vector3& p) const;

	//���ؾ��α߽���ϵ������
	Vector3 closestPointTo(const Vector3& p) const;

	//�ж��Ƿ�����ཻ
	bool intersectsSphere(const Vector3& center, float radius) const;

	//�Ͳ������ߵ��ཻ�Բ��ԣ�������ཻ�򷵻�ֵ����1
	float rayIntersect(const Vector3& rayOrg, const Vector3& rayDelta, Vector3* returnNormal = 0) const;

	//�жϾ��α߽����ƽ�����һ��
	int classfyPlane(const Vector3& n, float d) const;

	//��ƽ��Ķ�̬�ཻ�Բ���
	float intersectPlane(const Vector3& n, float planeD, const Vector3& dir) const;
};

//�������AABB���ཻ�ԣ������ཻ���ֵ�AABB
bool intersectAABBs(const AABB3& box1, const AABB3& box2, AABB3* boxIntersect = 0);

//�����˶�AABB�;�ֹAABB�ཻʱ�Ĳ����㣬������ཻ�򷵻�ֵ����1
float intersectMovingAABB(
	const AABB3& stationaryBox,
	const AABB3& movingBox,
	const Vector3& d);

#endif