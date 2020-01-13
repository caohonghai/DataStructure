/*

#include<iostream>
using namespace std;
#define NULL 0 
#define FALSE 0 
#define TRUE 1
#define OK 1
#define OVERFLOW -1
typedef int TElemType;
typedef int Status;
//定义函数指针
typedef struct BiTNode {	//结点定义
	TElemType data;
	struct BiTNode * lchild, *rchild;
} BiTNode, *BiTree;
typedef void(*Visit)(BiTree);
//二叉树的初始化
void InitBiTree(BiTree *T) {
	*T = NULL;
}
Status CreateBiTree(BiTree &T) {
	
	char ch;
	ch = getchar();
	//当输入的是"#"时，认为该子树为空
	if (ch == '#')
		T = NULL;
	//创建树结点
	else {
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) {
			exit(OVERFLOW);
		}
		T->data = ch; //生成树结点
		//生成左子树
		CreateBiTree(T->lchild);
		//生成右子树
		CreateBiTree(T->rchild);
	}
	return OK;
}

void DestroyBiTree(BiTree &T)//销毁一棵树
{
	if(T!=NULL)
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		delete T;
	}
}
//判断是否为空树
Status BiTreeEmpty(BiTree T) {
	if (T) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

int BiTreeDepth(BiTree root) //求树的最大深度
{
	if (root == NULL)
		return 0;
	int left = BiTreeDepth(root->lchild);
	int right = BiTreeDepth(root->rchild);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}

void Root(BiTree T) {
	cout << T->data << endl;
}

int Value(BiTNode e) {
	return e.data;
}

//先序遍历二叉树
void PreOrder_BiTree(BiTree T, Visit visit) {
	if (!BiTreeEmpty(T)) {
		visit(T);
		PreOrder_BiTree(T->lchild, visit);
		PreOrder_BiTree(T->rchild, visit);
	}
}
//中序遍历二叉树
void InOrder_BiTree(BiTree T, Visit visit) {
	if (!BiTreeEmpty(T)) {
		InOrder_BiTree(T->lchild, visit);
		visit(T);
		InOrder_BiTree(T->rchild, visit);
	}
}

//后序遍历二叉树　
void PostOrder_BiTree(BiTree T, Visit visit) {
	if (!BiTreeEmpty(T)) {
		PostOrder_BiTree(T->lchild, visit);
		PostOrder_BiTree(T->rchild, visit);
		visit(T);
	}
}
// 输出结点的值
void Print_BiTreeNode(BiTree T) {
	printf("%c\t", T->data);

}
int main() {
	BiTree T;
	//将二叉树初始为一个空的二叉树
	InitBiTree(&T);
	//创建二叉树
	CreateBiTree(T);
	printf("\n先序遍历结果：");
	PreOrder_BiTree(T, Print_BiTreeNode);
	//中序遍历二叉树
	printf("\n中序遍历结果：");
	InOrder_BiTree(T, Print_BiTreeNode);
	//后序遍历二叉树　
	printf("\n后序遍历结果：");
	PostOrder_BiTree(T, Print_BiTreeNode);
	system("pause");
	return 0;
}
*/ 
