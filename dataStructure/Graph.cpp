
#include<iostream>
#include<stdio.h>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define  INFINITY  INT_MAX��		// ���ֵ��
#define  MAX_VERTEX_NUM  20			// ��󶥵����
typedef enum { DG, DN, AG, AN } GraphKind;
									// ���ͱ�־{����ͼ,������,����ͼ,������}
typedef int VRType;
typedef int Status;
typedef int InfoType;
typedef char VertexType;
typedef struct ArcCell {			// ���Ķ���
	VRType adj;						// VRType�Ƕ����ϵ���͡�����Ȩͼ����1��0
									//��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ���͡�
	InfoType *info;                 // �û������Ϣ��ָ��
} AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {					// ͼ�Ķ���
	VertexType vexs[MAX_VERTEX_NUM];// ������Ϣ
	AdjMatrix arcs;					// ��ʾ����֮���ϵ�Ķ�ά����
	int vexnum, arcnum;				// ͼ�ĵ�ǰ�������ͻ�(��)��
	GraphKind kind;					// ͼ�������־
}MGraph;
MGraph G;//����һ��ͼ��ȫ�ֱ���
int judge = 0; // 0-�������� 1-�Ƿ����

typedef int Boole;  //�������� �洢TRUE FALSE
Boole visited[MAX_VERTEX_NUM];    //���ʱ�־����

// ���ݶ������ݣ��жϳ������ڶ�ά�����е�λ��
int LocateVex(MGraph *G, VertexType v) {
	int i = 0;
	for (; i < G->vexnum; i++) {
		if (G->vexs[i] == v) {
			break;
		}
	}
	if (i >= G->vexnum) {
		return -1;
	}
	return i;
}

// ���ͼ
void showGraph(MGraph *G) {
	cout << "\t";
	for (int k = 0; k < G->vexnum; k++) {
		cout << G->vexs[k] << "\t";
	}
	cout << endl;
	for (int i = 0; i < G->vexnum; i++) {
		cout << G->vexs[i] << "\t";
		for (int j = 0; j < G->vexnum; j++)
		{
			cout << G->arcs[i][j].adj << "\t";
		}
		cout << endl;
	}
}

// ��������ͼ
void CreateDG(MGraph *G) {
	// ����ͼ�еĶ������ͻ��ĸ���
	cout << "����ͼ�еĶ������ͻ��ĸ���:";
	cin >> G->vexnum >> G->arcnum;
	// �������붥�������
	cout << "�������붥�������:";
	for (int i = 0; i < G->vexnum; i++) {
		cin >> G->vexs[i];
	}
	// init
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	// ��ӻ�
	for (int i = 0; i < G->arcnum; i++) {
		VertexType v1, v2;
		// ��ͷ ��β
		cout << "�����" << i + 1 << "����ͷ�ͻ�β��";
		cin >> v1 >> v2;
		//
		if ((LocateVex(G, v1) == -1) || (LocateVex(G, v2) == -1)) {
			cout << "û�ҵ���Ӧ�ĵ�" << endl;
			// ֱ�ӽ�������
			judge = 1;
			return;
		}
		G->arcs[LocateVex(G, v1)][LocateVex(G, v2)].adj = 1;
	}
}

// ��������ͼ
void CreateDN(MGraph *G) {
	// ����ͼ�еĶ������ͻ��ĸ���
	cout << "����ͼ�еĶ������ͻ��ĸ���:";
	cin >> G->vexnum >> G->arcnum;
	// �������붥�������
	cout << "�������붥�������:";
	for (int i = 0; i < G->vexnum; i++) {
		cin >> G->vexs[i];
	}
	// init
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	// ��ӻ�
	for (int i = 0; i < G->arcnum; i++) {
		VertexType v1, v2;
		// ��ͷ ��β
		cout << "�����" << i + 1 << "����ͷ�ͻ�β��";
		cin >> v1 >> v2;
		//
		if (LocateVex(G, v1) == -1 || LocateVex(G, v2) == -1) {
			cout << "û�ҵ���Ӧ�ĵ�" << endl;
			// ֱ�ӽ�������
			judge = 1;
			return;
		}
		G->arcs[LocateVex(G, v1)][LocateVex(G, v2)].adj = 1;
		G->arcs[LocateVex(G, v2)][LocateVex(G, v1)].adj = 1;
	}
}

// ����������
void CreateAG(MGraph *G) {
	cout << "����ͼ�еĶ������ͻ��ĸ���:";
	cin >> G->vexnum >> G->arcnum;
	cout << "�������붥�������:";
	for (int i = 0; i < G->vexnum; i++) {
		cin >> G->vexs[i];
	}
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	// ��ӻ�
	for (int i = 0; i < G->arcnum; i++) {
		VertexType v1, v2;
		int w;
		// ��ͷ ��β
		cout << "�����" << i + 1 << "����ͷ,��β��Ȩֵ��";
		cin >> v1 >> v2 >> w;
		//
		if (LocateVex(G, v1) == -1 || LocateVex(G, v2) == -1) {
			cout << "û�ҵ���Ӧ�ĵ�" << endl;
			// ֱ�ӽ�������
			judge = 1;
			return;
		}
		G->arcs[LocateVex(G, v1)][LocateVex(G, v2)].adj = w;
	}

}

// ����������
void CreateAN(MGraph *G) {
	cout << "����ͼ�еĶ������ͻ��ĸ���:";
	cin >> G->vexnum >> G->arcnum;
	cout << "�������붥�������:";
	for (int i = 0; i < G->vexnum; i++) {
		cin >> G->vexs[i];
	}
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	// ��ӻ�
	for (int i = 0; i < G->arcnum; i++) {
		VertexType v1, v2;
		int w;
		// ��ͷ ��β
		cout << "�����" << i + 1 << "����ͷ,��β��Ȩֵ��";
		cin >> v1 >> v2 >> w;
		//
		if (LocateVex(G, v1) == -1 || LocateVex(G, v2) == -1) {
			cout << "û�ҵ���Ӧ�ĵ�" << endl;
			// ֱ�ӽ�������
			judge = 1;
			return;
		}
		G->arcs[LocateVex(G, v1)][LocateVex(G, v2)].adj = w;
		G->arcs[LocateVex(G, v2)][LocateVex(G, v1)].adj = w;
	}

}

// ����ͼ
void  CreateGraph(MGraph *G) {
	cout << "ѡ��ͼ������:0-����ͼ��1-����ͼ��2-��������3-������" << endl;
	//ѡ��ͼ������
	scanf_s("%d", &(G->kind));
	//������ѡ���ͣ����ò�ͬ�ĺ���ʵ�ֹ���ͼ�Ĺ���
	switch (G->kind) {
	case DG:
		CreateDG(G);
		break;
	case DN:
		CreateDN(G);
		break;
	case AG:
		CreateAG(G);
		break;
	case AN:
		CreateAN(G);
		break;
	default:
		break;
	}
}

// ��ͼ G �������¶��� v��
void InsertVex(MGraph *G, VertexType v) {
	if (G->vexnum < MAX_VERTEX_NUM) {
		G->vexnum++;
	}
	for (int i = 0; i < G->vexnum; i++) {
		G->arcs[i][G->vexnum - 1].adj = 0;
	}
	for (int i = 0; i < G->vexnum; i++) {
		G->arcs[G->vexnum - 1][i].adj = 0;
	}
	G->vexs[G->vexnum - 1] = v;
	cout << "������µľ���Ϊ��" << endl;
	showGraph(G);//���ͼ�Ķ��׾���
}

// ɾ�� G �ж��� v ������صĻ���
Status DeleteVex(MGraph *G, VertexType v) {
	if (G->vexnum == 0) {
		return ERROR;
	}
	// �ܵ���-1
	G->vexnum--;
	if (LocateVex(G, v) != -1) {
		//G->vexs[G->vexnum - 1] = v;
		// ɾ���õ�
		int pos = LocateVex(G, v);
		for (int i = pos; i < G->vexnum; i++) {
			G->vexs[i] = G->vexs[i + 1];
		}
		// ɾ���õ��Ӧ�Ļ�
		int a = 0, b = 0;
		int tmp[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
		for (int i = 0; i < MAX_VERTEX_NUM; i++) {
			for (int j = 0; j < MAX_VERTEX_NUM; j++) {
				tmp[i][j] = 0;
			}
		}
		for (int i = 0; i < G->vexnum + 1; i++) {
			if (i == pos) {
				continue;
			}
			for (int j = 0; j < G->vexnum + 1; j++) {
				if (j == pos) {
					continue;
				}
				else {
					tmp[a][b] = G->arcs[i][j].adj;
					b++;
				}
			}
			a++;
			b = 0;
		}
		for (int i = 0; i < G->vexnum; i++) {
			for (int j = 0; j < G->vexnum; j++) {
				G->arcs[i][j].adj = tmp[i][j];
			}
		}
		showGraph(G);
		return OK;
	}
	else {
		return ERROR;
	}
}

// �� G ������<v,w>���� G ������ģ�������Գƻ�<w,v>��    ����һ��valueΪȨֵ ��Ϊ���ʹ�Ȩֵ ��Ϊͼ value=1��
Status InsertArc(MGraph *G, VertexType v, VertexType w, int value) {
	if (LocateVex(G, v) == -1 || LocateVex(G, w) == -1) {
		return ERROR;
	}
	int point1 = LocateVex(G, v), point2 = LocateVex(G, w);

	// �Ѿ�������
	if (G->arcs[point1][point2].adj != 0) {
		return ERROR;
	}
	// ����
	if (G->kind == 0 || G->kind == 2) {
		G->arcs[point1][point2].adj = value;
		return OK;
	}
	// ����
	if (G->kind == 1 || G->kind == 3) {
		G->arcs[point1][point2].adj = value;
		G->arcs[point2][point1].adj = value;
		return OK;
	}
	return ERROR;
}

// �� G ��ɾ����<v,w>���� G ������ģ���ɾ���Գƻ�<w,v>��
Status DeleteArc(MGraph *G, VertexType v, VertexType w) {
	if (LocateVex(G, v) == -1 || LocateVex(G, w) == -1) {
		return ERROR;
	}
	int point1 = LocateVex(G, v), point2 = LocateVex(G, w);
	// û�л�
	if (G->arcs[point1][point2].adj == 0) {
		return ERROR;
	}
	// ����
	if (G->kind == 0 || G->kind == 2) {
		G->arcs[point1][point2].adj = 0;
		return OK;
	}
	// ����
	if (G->kind == 1 || G->kind == 3) {
		G->arcs[point1][point2].adj = 0;
		G->arcs[point2][point1].adj = 0;
		return OK;
	}
	return ERROR;
}


//������ȵݹ��㷨
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;   //�����ʵı��
	cout << G.vexs[i] << "->";
	for (j = 0; j < G.vexnum; j++)
	{
		if (G.arcs[i][j].adj == 1 && !visited[j])   //��(i,j)������j����δ�����ʣ��ݹ�
			DFS(G, j);
	}
}

int main() {
	CreateGraph(&G);//���ô��������������ַ����
	if (judge != 1) {
		showGraph(&G);//���ͼ�Ķ��׾���
		// DFS��������

		// DFS
		cout << "���뿪ʼ����:";
		VertexType tmp2;
		cout << "DFS:";
		cin >> tmp2;
		DFS(G, LocateVex(&G,tmp2));
		cout << endl;
		// �����
		VertexType tmp;
		cout << "�����µĶ��㣺";
		cin >> tmp;
		InsertVex(&G, tmp);
		cout << "��ǰ�Ķ���Ϊ��";
		for (int i = 0; i < G.vexnum; i++) {
			cout << G.vexs[i] << " ";
		}
		cout << endl;
		// ɾ��
		cout << "��Ҫɾ���Ķ��㣺";
		cin >> tmp;
		if (DeleteVex(&G, tmp) == ERROR)
			cout << "ɾ��ʧ��" << endl;
		else
			cout << "ɾ���ɹ�" << endl;
		cout << "��ǰ�Ķ���Ϊ��";
		for (int i = 0; i < G.vexnum; i++) {
			cout << G.vexs[i] << " ";
		}
		cout << endl;
		// �����µĻ�
		VertexType point1,point2; // ��Ӧ�Ķ���
		int value;				  // ��Ӧ��Ȩֵ
		// ��ʾͼ
		if (G.kind == 0 || G.kind == 1) {
			cout << "��������Ҫ����Ļ�����Ӧ�Ļ�ͷ�ͻ�β";
			cin >> point1 >> point2;
			if (InsertArc(&G, point1, point2, 1)) {
				cout << "�����µĻ���ɣ����µ�ͼΪ��" << endl;
				showGraph(&G);
			}
			else {
				cout << "�������" << endl;
			}
		}
		else {//��ʾ��
			cout << "��������Ҫ����Ļ�����Ӧ�Ļ�ͷ,��β��Ȩֵ";
			cin >> point1 >> point2 >> value;
			if (InsertArc(&G, point1, point2, value)) {
				cout << "�����µĻ���ɣ����µ�ͼΪ��" << endl;
				showGraph(&G);
			}
			else {
				cout << "�������" << endl;
			}
		}

		// ɾ��
		// ��ʾͼ
		if (G.kind == 0 || G.kind == 1) {
			cout << "��������Ҫɾ���Ļ�����Ӧ�Ļ�ͷ�ͻ�β";
			cin >> point1 >> point2;
			if (DeleteArc(&G, point1, point2)) {
				cout << "ɾ������ɣ����µ�ͼΪ��" << endl;
				showGraph(&G);
			}
			else {
				cout << "ɾ������" << endl;
			}
		}
		else {//��ʾ��
			cout << "��������Ҫɾ���Ļ�����Ӧ�Ļ�ͷ,��β";
			cin >> point1 >> point2;
			if (DeleteArc(&G, point1, point2)) {
				cout << "ɾ������ɣ����µ�ͼΪ��" << endl;
				showGraph(&G);
			}
			else {
				cout << "ɾ������" << endl;
			}
		}

	}
	else {
		cout << "���ȴ���ͼ" << endl;
	}
	system("pause");
	return 0;
}
/*
1
9 10
A B C D E F G H I
A B
A C
A D
B E
B C
C F
D F
E G
F H
H I

*/
 