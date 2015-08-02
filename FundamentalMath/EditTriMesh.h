#ifndef _EDITTRIMESH_H_
#define _EDITTRIMESH_H_

#include "vector3.h"
class Matrix4x3;

class EditTriMesh
{
public:
	//Vertex�����ڱ��涥����Ϣ
	class Vertex
	{
	public:
		Vertex() 
		{
			setDefaults();
		}
		void setDefaults();
		//3D����
		Vector3 p;

		//���㼶����ӳ������,����ʧЧ��
		float u, v;
		//���㼶���淨������ͬ������ʧЧ
		Vector3 normal;
		//���߱���
		int mark;
	};

	//��Tri���ڱ�����������Ϣ
	class Tri
	{
	public:
		
		Tri() { setDefaults(); }
		void setDefaults();

		//�涥��
		struct Vert
		{
			int index;   //�����б������
			float u, v;  //��������
		};

		Vert v[3];
		//���淨����
		Vector3 normal;
		//����������Ĳ���
		int part;
		//�����б�����
		int material;
		//���߱���
		int mark;
		//�ж��Ƿ�Ϊ�˻�������---ͬһ������һ����������ʹ�ö��
		bool isDegenerate() const;

		//���ض���������Ϊʹ�øö����򷵻�-1
		int findVertex(int vertexIndex) const;
	};

	//�����࣬���������Ϣ

	class Material
	{
	public:

		Material() { setDefaults(); }
		void setDefaults();
		char diffuseTextureName[256];

		//���߱���
		int mark;
	};

	//�����Ż���ѡ��
	class OptimationParameters
	{
	public:
		OptimationParameters(){ setDefaults(); }
		void setDefaults();

		//�ж����������Ƿ��غϵ��ݲ�
		float coincidentVertexTolerance;

		float cosOfEdgeAngleTolerance;
		void setEdgeAngleToleranceInDegrees(float degrees);
	};

	EditTriMesh();
	EditTriMesh(const EditTriMesh& x);

	~EditTriMesh();

	EditTriMesh& operator=(const EditTriMesh& rhs);

	//��ȡ��������

	int vertexCount() const { return vCount; }
	int triCount() const { return tCount; }
	int materialCount() const { return mCount; }

	Vertex& vertex(int vertexIndex);
	const Vertex& vertex(int vertexIndex) const;
	
	Tri& tri(int triIndex);
	const Tri& tri(int triIndex) const;
	
	Material& material(int materialIndex);
	const Material& material(int materialIndex) const;

	//��������Ϊ��
	void empty();

	//�����б��С
	void setVertexCount(int vc);
	void setTriCount(int tc);
	void setMaterialCount(int mc);

	//���������\����\���ʣ������¼���Ԫ�ص�����

	int addTri();
	int addTri(const Tri& t);

	int addVertex();
	int addVertex(const Vertex& v);
	int dupVertex(int srcVertexIndex);

	int addMaterial(const Material& m);

	//ͬʱ��������mark����
	void markAllVertices(int mark);
	void markAllTris(int mark);
	void markAllMaterials(int mark);

	//ɾ������

	void deleteVertex(int vertexIndex);
	void deleteTri(int triIndex);
	void deleteMaterial(int materialIndex);
	void deleteUnusedMaterials();
	void deleteMarkedTris(int mark);
	void deleteDegenerateTris();

	//������������棬����һ���µĶ����б�ÿ������ֻ����һ�������Σ�ͬʱɾ��δ�õĵ�
	void detachAllFaces();

	//�任���ж���
	void transformVertices(const Matrix4x3& m);


	//���������εı��淨����
	void computeOneTriNormal(int triIndex);
	void computeOneTriNormal(Tri& t);
	void computeOneTriNormals();
	
	//���㶥�㷨�������Զ����������η�����
	void computeVertexNormals();

	//����ʹ������������ж����б���ǿCache�����ܣ�ɾ��δʹ�õĶ���
	void optimizeVertexOrder(bool removeUnusedVertices);

	//���ݲ���Ϊ����������
	void sortTrisByMaterial();

	//���Ӷ���
	void weldVertices(const OptimationParameters* opt);

	//ȷ��UVֵ��ȷ�������Ҫ���ܻḴ�ƶ���
	void copyUvsIntoVertices();
	void optimizeForRedering();

	//���뵽��S3Dģ��
	bool importS3d(const char* filename, char* returnErrMsg);
	bool exportS3d(const char* filename, char* returnErrMsg);
	
	//������
	void validityCheck();
	bool validityCheck(char* returnErrMsg);




private:
	int vAlloc;
	int vCount;
	Vertex* vList;
	int tAlloc;
	int tCount;
	Tri* tList;
	int mCount;
	Material * mList;

	void construct();

};


#endif // !_EDITTRIMESH_H_
