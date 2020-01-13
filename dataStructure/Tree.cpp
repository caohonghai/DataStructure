/*
#include<iostream>
using namespace std;
#define NULL 0
#define FALSE 0
#define TRUE 1
#define ERROR 0
#define OK 1
#define OVERFLOW -1
#define INITQUEUE 20
typedef char TElemType;
typedef int Status;
typedef struct BiTNode {	//结点定义
	TElemType data;
	struct BiTNode * lchild, *rchild;
} BiTNode, *BiTree;
//定义函数指针
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

//判断是否为空树
Status BiTreeEmpty(BiTree T) {
	if (T) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

//求树的最大深度
int BiTreeDepth(BiTree root)
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
	printf("\t%c", T->data);
}

void Insert(BiTree &T, char c) {
	if (T == NULL) {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = c;
		T->lchild = T->rchild = NULL;
		return;
	}
	else if (c == T->data)
		return;
	else if (c < T->data)
		return Insert(T->lchild, c);
	else
		return Insert(T->rchild, c);
}

//销毁一棵树
void DestroyBiTree(BiTree *T)
{
	if (*T)
	{
		if ((*T)->lchild)
			DestroyBiTree(&(*T)->lchild);
		if ((*T)->rchild)
			DestroyBiTree(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
}

//返回根节点
char Root(BiTree T) {
	if (T == NULL) {
		cout << "无根节点" << endl;
	}
	else {
		return  T->data;
	}
}

//清空数
void ClearBiTree(BiTree *T) {
	*T = NULL;
}

//返回总共结点个数
int  Num_Of_Node(BiTree t)
{
	if (t == NULL)
		return 0;
	else
		return Num_Of_Node(t->lchild) + Num_Of_Node(t->rchild) + 1;
}

//返回叶子结点个数
int LeavesNum(BiTree T)
{
	if (T)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			return 1;
		}
		return LeavesNum(T->lchild) + LeavesNum(T->rchild);
	}
	return 0;
}

//判断某个值是不是树的结点
bool find(BiTree Root, TElemType e) {
	if (Root == NULL) {
		return FALSE;
	}
	if (Root->data == e) {
		return TRUE;
	}
	return find(Root->lchild, e) || find(Root->rchild, e);
}


BiTree Parent(BiTree T, BiTNode* e)
//初始条件:二叉树T存,e是T中某个结点
//操作结果:若e是T的非根结点,则返回它的双亲,否则返回"空"
{
	if (T){
		if (T->data == e->data)//根节点等于传入的值 返回空
			return NULL;
		if (T->lchild != NULL && T->lchild->data == e->data || T->rchild != NULL && T->rchild->data == e->data) {
			return T;//找到该点
		}
		else {//递归查找
			BiTNode* tempP = NULL;
			if (tempP = Parent(T->lchild, e))
				return tempP;
			if (tempP = Parent(T->rchild, e))
				return tempP;
		}
	}
	else {//为空
		return NULL;
	}
}

BiTree Search(BiTree T, BiTNode* e)
//e是T中的某个节点, 返回e节点
{
	if (T) {
		if (T->data == e->data) {
			return T;//找到该点
		}
		else {//递归查找
			BiTNode* tempP = NULL;
			if (tempP = Search(T->lchild, e))
				return tempP;
			if (tempP = Search(T->rchild, e))
				return tempP;
		}
	}
	else {//为空
		return NULL;
	}
}

BiTree LeftChild(BiTree T, BiTNode* e)
//初始条件：二叉树 T 存在,e 是T中某个结点
//操作结果：返回 e 的左孩子,若e无左孩子,则返回"空"
{
	if (Search(T, e)) {
		if (Search(T, e)->lchild != NULL) {
			BiTNode* tempP = NULL;
			if(tempP= Search(T, e)->lchild)
			return tempP;
		}
		else {
			return NULL;
		}
	}
	else {
		return NULL;
	}
}


BiTree RightChild(BiTree T, BiTNode* e)
//初始条件：二叉树 T 存在，e 是 T 中某个结点
//操作结果：返回e的右孩子,若 e无右孩子,则返回"空"
{

	if (Search(T, e)) {
		if (Search(T, e)->rchild != NULL)
		{
			BiTNode* tempP = NULL;
			if (tempP = Search(T, e)->rchild)
				return tempP;
		}
		else {
			return NULL;
		}
	}
	else {
		return NULL;
	}
}


BiTree LeftSibling(BiTree T, BiTNode* e)
//初始条件:二叉树 T 存在，e 是 T 中某个结点
//操作结果:返回 e的左兄弟,若 e 是其双亲的左孩子或无左兄弟,则返回"空"
{
	if (T != NULL) {
		if (Parent(T, e)->lchild->data == e->data || Parent(T, e)->lchild == NULL)
			return NULL;
		else {
			return Parent(T, e)->lchild;
		}
	}
	else {
		return ERROR;
	}
}


BiTree RightSibling(BiTree T, BiTNode* e)
//初始条件:二叉树 T 存在,e是T的结点。
//操作结果:返回 e 的右兄弟,若 e是其双亲的右孩子或无右兄弟,则返回"空"
{
	if (T != NULL) {
		if (Parent(T, e)->rchild->data == e->data || Parent(T, e)->rchild == NULL) {
			return ERROR;
		}else {
			return Parent(T, e)->rchild;
		}
	}
	else {
		return ERROR;
	}
}
Status Assign(BiTree &T, BiTNode* &e, TElemType value)
//初始条件：二叉树T存在,e 是T 中某个结点
//操作结果：结点e赋值为value
{
	if (T) {
		Search(T, e)->data = value;
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int main() {
	//测试用例：123###4#56###
	BiTree T;
	BiTree node = NULL;
	node = (BiTNode*)malloc(sizeof(BiTNode));
	TElemType temp;
	//将二叉树初始为一个空的二叉树
	InitBiTree(&T);
	//创建二叉树
	CreateBiTree(T);
	cout << "根为：";
	cout << Root(T);
	printf("\n先序遍历结果：");
	PreOrder_BiTree(T, Print_BiTreeNode);
	//中序遍历二叉树
	printf("\n中序遍历结果：");
	InOrder_BiTree(T, Print_BiTreeNode);
	//后序遍历二叉树　
	printf("\n后序遍历结果：");
	PostOrder_BiTree(T, Print_BiTreeNode);
	//printf("\n层次遍历结果：");
	//levelTraverse(T);
	cout << endl << "最深长度为：" << BiTreeDepth(T) << endl;
	cout << "节点个数:" << Num_Of_Node(T) << endl;
	//判断是否在当前树中
	cout << "输入数据判断当前数据是否在树中，若在树中输出其双亲：";
	cin >> temp;
	if (find(T, temp)) {
		cout << temp << "在树中" << endl;
		node->data = temp;
		if (Parent(T, node) != NULL) {
			cout << temp << "的双亲为：" << Parent(T, node)->data << endl;
		}
		else {
			cout << "NO Parent!" << endl;
		}
	}
	else {
		cout << temp << "不在树中" << endl;
	}
	//左孩子
	cout << "输入数据判断该数据的左孩子是否为空,非空输出其左孩子:";
	cin >> temp;
	node->data = temp;
	if (LeftChild(T, node)!=NULL) {
		cout << temp << "的左孩子为：" << LeftChild(T, node)->data << endl;
	}
	else {
		cout <<"ERROR!\t"<< temp << "的左孩子不存在!" << endl;
	}
	//右孩子
	cout << "输入数据判断该数据的右孩子是否为空,非空输出其右孩子:";
	cin >> temp;
	node->data = temp;
	if (RightChild(T, node)) {
		cout << temp << "的右孩子为：" << RightChild(T, node)->data << endl;
	}
	else {
		cout << "ERROR!\t" << temp << "的右孩子不存在!" << endl;

	}
	//左兄弟
	cout << "输入数据判断该数据是否存在左兄弟,若存在输出其左兄弟:";
	cin >> temp;
	node->data = temp;
	if (LeftSibling(T, node) != ERROR) {
		cout << temp << "的左兄弟为：" << LeftSibling(T, node)->data << endl;
	}
	else {
		cout << "ERROR!\t" << temp << "的右兄弟不存在!" << endl;

	}
	//右兄弟
	cout << "输入数据判断该数据是否存在右兄弟,若存在输出其右兄弟:";
	cin >> temp;
	node->data = temp;
	if (RightSibling(T, node) != ERROR) {
		cout << temp << "的右兄弟为：" << RightSibling(T, node)->data << endl;
	}
	else {
		cout << "ERROR!\t" << temp << "的右兄弟不存在!" << endl;

	}

	//结点e赋值为value
	cout << "给二叉树的某个结点重新赋值:";
	cin >> node->data;
	cout << "给其赋值为：";
	TElemType temp2;
	cin >> temp2;
	if (Assign(T, node, temp2)) {
		cout << "新的前序遍历为：";
		PreOrder_BiTree(T, Print_BiTreeNode);
		cout << endl;
	}
	else {
		cout << "ERROR!" << endl;
	}


	//叶子结点个数
	cout << "叶子节点个数:" << LeavesNum(T) << endl;
	ClearBiTree(&T);
	if (T == NULL) {
		cout << "该树已被清空" << endl;
	}
	DestroyBiTree(&T);
	cout << "该树已被销毁" << endl;

	system("pause");
	return 0;
}

*/