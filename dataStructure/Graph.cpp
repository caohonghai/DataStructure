
#include<iostream>
#include<stdio.h>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define  INFINITY  INT_MAX　		// 最大值∞
#define  MAX_VERTEX_NUM  20			// 最大顶点个数
typedef enum { DG, DN, AG, AN } GraphKind;
									// 类型标志{有向图,有向网,无向图,无向网}
typedef int VRType;
typedef int Status;
typedef int InfoType;
typedef char VertexType;
typedef struct ArcCell {			// 弧的定义
	VRType adj;						// VRType是顶点关系类型。对无权图，用1或0
									//表示相邻否；对带权图，则为权值类型。
	InfoType *info;                 // 该弧相关信息的指针
} AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {					// 图的定义
	VertexType vexs[MAX_VERTEX_NUM];// 顶点信息
	AdjMatrix arcs;					// 表示顶点之间关系的二维数组
	int vexnum, arcnum;				// 图的当前顶点数和弧(边)数
	GraphKind kind;					// 图的种类标志
}MGraph;
MGraph G;//建立一个图的全局变量
int judge = 0; // 0-正常输入 1-非法输出

typedef int Boole;  //布尔类型 存储TRUE FALSE
Boole visited[MAX_VERTEX_NUM];    //访问标志数组

// 根据顶点数据，判断出顶点在二维数组中的位置
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

// 输出图
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

// 构造有向图
void CreateDG(MGraph *G) {
	// 输入图中的顶点数和弧的个数
	cout << "输入图中的顶点数和弧的个数:";
	cin >> G->vexnum >> G->arcnum;
	// 依次输入顶点的数据
	cout << "依次输入顶点的数据:";
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
	// 添加弧
	for (int i = 0; i < G->arcnum; i++) {
		VertexType v1, v2;
		// 弧头 弧尾
		cout << "输出第" << i + 1 << "个弧头和弧尾：";
		cin >> v1 >> v2;
		//
		if ((LocateVex(G, v1) == -1) || (LocateVex(G, v2) == -1)) {
			cout << "没找到对应的点" << endl;
			// 直接结束创建
			judge = 1;
			return;
		}
		G->arcs[LocateVex(G, v1)][LocateVex(G, v2)].adj = 1;
	}
}

// 构造无向图
void CreateDN(MGraph *G) {
	// 输入图中的顶点数和弧的个数
	cout << "输入图中的顶点数和弧的个数:";
	cin >> G->vexnum >> G->arcnum;
	// 依次输入顶点的数据
	cout << "依次输入顶点的数据:";
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
	// 添加弧
	for (int i = 0; i < G->arcnum; i++) {
		VertexType v1, v2;
		// 弧头 弧尾
		cout << "输出第" << i + 1 << "个弧头和弧尾：";
		cin >> v1 >> v2;
		//
		if (LocateVex(G, v1) == -1 || LocateVex(G, v2) == -1) {
			cout << "没找到对应的点" << endl;
			// 直接结束创建
			judge = 1;
			return;
		}
		G->arcs[LocateVex(G, v1)][LocateVex(G, v2)].adj = 1;
		G->arcs[LocateVex(G, v2)][LocateVex(G, v1)].adj = 1;
	}
}

// 构造有向网
void CreateAG(MGraph *G) {
	cout << "输入图中的顶点数和弧的个数:";
	cin >> G->vexnum >> G->arcnum;
	cout << "依次输入顶点的数据:";
	for (int i = 0; i < G->vexnum; i++) {
		cin >> G->vexs[i];
	}
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	// 添加弧
	for (int i = 0; i < G->arcnum; i++) {
		VertexType v1, v2;
		int w;
		// 弧头 弧尾
		cout << "输出第" << i + 1 << "个弧头,弧尾和权值：";
		cin >> v1 >> v2 >> w;
		//
		if (LocateVex(G, v1) == -1 || LocateVex(G, v2) == -1) {
			cout << "没找到对应的点" << endl;
			// 直接结束创建
			judge = 1;
			return;
		}
		G->arcs[LocateVex(G, v1)][LocateVex(G, v2)].adj = w;
	}

}

// 构造无向网
void CreateAN(MGraph *G) {
	cout << "输入图中的顶点数和弧的个数:";
	cin >> G->vexnum >> G->arcnum;
	cout << "依次输入顶点的数据:";
	for (int i = 0; i < G->vexnum; i++) {
		cin >> G->vexs[i];
	}
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	// 添加弧
	for (int i = 0; i < G->arcnum; i++) {
		VertexType v1, v2;
		int w;
		// 弧头 弧尾
		cout << "输出第" << i + 1 << "个弧头,弧尾和权值：";
		cin >> v1 >> v2 >> w;
		//
		if (LocateVex(G, v1) == -1 || LocateVex(G, v2) == -1) {
			cout << "没找到对应的点" << endl;
			// 直接结束创建
			judge = 1;
			return;
		}
		G->arcs[LocateVex(G, v1)][LocateVex(G, v2)].adj = w;
		G->arcs[LocateVex(G, v2)][LocateVex(G, v1)].adj = w;
	}

}

// 创建图
void  CreateGraph(MGraph *G) {
	cout << "选择图的类型:0-有向图，1-无向图，2-有向网，3-无向网" << endl;
	//选择图的类型
	scanf_s("%d", &(G->kind));
	//根据所选类型，调用不同的函数实现构造图的功能
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

// 在图 G 中增添新顶点 v。
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
	cout << "插入后新的矩阵为：" << endl;
	showGraph(G);//输出图的二阶矩阵
}

// 删除 G 中顶点 v 及其相关的弧。
Status DeleteVex(MGraph *G, VertexType v) {
	if (G->vexnum == 0) {
		return ERROR;
	}
	// 总点数-1
	G->vexnum--;
	if (LocateVex(G, v) != -1) {
		//G->vexs[G->vexnum - 1] = v;
		// 删除该点
		int pos = LocateVex(G, v);
		for (int i = pos; i < G->vexnum; i++) {
			G->vexs[i] = G->vexs[i + 1];
		}
		// 删除该点对应的弧
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

// 在 G 中增添弧<v,w>，若 G 是无向的，则还增添对称弧<w,v>。    附加一个value为权值 若为网就带权值 若为图 value=1：
Status InsertArc(MGraph *G, VertexType v, VertexType w, int value) {
	if (LocateVex(G, v) == -1 || LocateVex(G, w) == -1) {
		return ERROR;
	}
	int point1 = LocateVex(G, v), point2 = LocateVex(G, w);

	// 已经有数据
	if (G->arcs[point1][point2].adj != 0) {
		return ERROR;
	}
	// 有向
	if (G->kind == 0 || G->kind == 2) {
		G->arcs[point1][point2].adj = value;
		return OK;
	}
	// 无向
	if (G->kind == 1 || G->kind == 3) {
		G->arcs[point1][point2].adj = value;
		G->arcs[point2][point1].adj = value;
		return OK;
	}
	return ERROR;
}

// 在 G 中删除弧<v,w>，若 G 是无向的，则还删除对称弧<w,v>。
Status DeleteArc(MGraph *G, VertexType v, VertexType w) {
	if (LocateVex(G, v) == -1 || LocateVex(G, w) == -1) {
		return ERROR;
	}
	int point1 = LocateVex(G, v), point2 = LocateVex(G, w);
	// 没有弧
	if (G->arcs[point1][point2].adj == 0) {
		return ERROR;
	}
	// 有向
	if (G->kind == 0 || G->kind == 2) {
		G->arcs[point1][point2].adj = 0;
		return OK;
	}
	// 无向
	if (G->kind == 1 || G->kind == 3) {
		G->arcs[point1][point2].adj = 0;
		G->arcs[point2][point1].adj = 0;
		return OK;
	}
	return ERROR;
}


//深度优先递归算法
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;   //被访问的标记
	cout << G.vexs[i] << "->";
	for (j = 0; j < G.vexnum; j++)
	{
		if (G.arcs[i][j].adj == 1 && !visited[j])   //边(i,j)存在且j顶点未被访问，递归
			DFS(G, j);
	}
}

int main() {
	CreateGraph(&G);//调用创建函数，传入地址参数
	if (judge != 1) {
		showGraph(&G);//输出图的二阶矩阵
		// DFS不能用网

		// DFS
		cout << "输入开始顶点:";
		VertexType tmp2;
		cout << "DFS:";
		cin >> tmp2;
		DFS(G, LocateVex(&G,tmp2));
		cout << endl;
		// 插入点
		VertexType tmp;
		cout << "插入新的顶点：";
		cin >> tmp;
		InsertVex(&G, tmp);
		cout << "当前的顶点为：";
		for (int i = 0; i < G.vexnum; i++) {
			cout << G.vexs[i] << " ";
		}
		cout << endl;
		// 删除
		cout << "需要删除的顶点：";
		cin >> tmp;
		if (DeleteVex(&G, tmp) == ERROR)
			cout << "删除失败" << endl;
		else
			cout << "删除成功" << endl;
		cout << "当前的顶点为：";
		for (int i = 0; i < G.vexnum; i++) {
			cout << G.vexs[i] << " ";
		}
		cout << endl;
		// 插入新的弧
		VertexType point1,point2; // 对应的顶点
		int value;				  // 对应的权值
		// 表示图
		if (G.kind == 0 || G.kind == 1) {
			cout << "请输入需要插入的弧所对应的弧头和弧尾";
			cin >> point1 >> point2;
			if (InsertArc(&G, point1, point2, 1)) {
				cout << "插入新的弧完成，最新的图为：" << endl;
				showGraph(&G);
			}
			else {
				cout << "插入错误！" << endl;
			}
		}
		else {//表示网
			cout << "请输入需要插入的弧所对应的弧头,弧尾和权值";
			cin >> point1 >> point2 >> value;
			if (InsertArc(&G, point1, point2, value)) {
				cout << "插入新的弧完成，最新的图为：" << endl;
				showGraph(&G);
			}
			else {
				cout << "插入错误！" << endl;
			}
		}

		// 删除
		// 表示图
		if (G.kind == 0 || G.kind == 1) {
			cout << "请输入需要删除的弧所对应的弧头和弧尾";
			cin >> point1 >> point2;
			if (DeleteArc(&G, point1, point2)) {
				cout << "删除弧完成，最新的图为：" << endl;
				showGraph(&G);
			}
			else {
				cout << "删除错误！" << endl;
			}
		}
		else {//表示网
			cout << "请输入需要删除的弧所对应的弧头,弧尾";
			cin >> point1 >> point2;
			if (DeleteArc(&G, point1, point2)) {
				cout << "删除弧完成，最新的图为：" << endl;
				showGraph(&G);
			}
			else {
				cout << "删除错误！" << endl;
			}
		}

	}
	else {
		cout << "请先创建图" << endl;
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
 