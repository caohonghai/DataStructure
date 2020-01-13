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
//���庯��ָ��
typedef struct BiTNode {	//��㶨��
	TElemType data;
	struct BiTNode * lchild, *rchild;
} BiTNode, *BiTree;
typedef void(*Visit)(BiTree);
//�������ĳ�ʼ��
void InitBiTree(BiTree *T) {
	*T = NULL;
}
Status CreateBiTree(BiTree &T) {
	
	char ch;
	ch = getchar();
	//���������"#"ʱ����Ϊ������Ϊ��
	if (ch == '#')
		T = NULL;
	//���������
	else {
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) {
			exit(OVERFLOW);
		}
		T->data = ch; //���������
		//����������
		CreateBiTree(T->lchild);
		//����������
		CreateBiTree(T->rchild);
	}
	return OK;
}

void DestroyBiTree(BiTree &T)//����һ����
{
	if(T!=NULL)
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		delete T;
	}
}
//�ж��Ƿ�Ϊ����
Status BiTreeEmpty(BiTree T) {
	if (T) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

int BiTreeDepth(BiTree root) //������������
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

//�������������
void PreOrder_BiTree(BiTree T, Visit visit) {
	if (!BiTreeEmpty(T)) {
		visit(T);
		PreOrder_BiTree(T->lchild, visit);
		PreOrder_BiTree(T->rchild, visit);
	}
}
//�������������
void InOrder_BiTree(BiTree T, Visit visit) {
	if (!BiTreeEmpty(T)) {
		InOrder_BiTree(T->lchild, visit);
		visit(T);
		InOrder_BiTree(T->rchild, visit);
	}
}

//���������������
void PostOrder_BiTree(BiTree T, Visit visit) {
	if (!BiTreeEmpty(T)) {
		PostOrder_BiTree(T->lchild, visit);
		PostOrder_BiTree(T->rchild, visit);
		visit(T);
	}
}
// �������ֵ
void Print_BiTreeNode(BiTree T) {
	printf("%c\t", T->data);

}
int main() {
	BiTree T;
	//����������ʼΪһ���յĶ�����
	InitBiTree(&T);
	//����������
	CreateBiTree(T);
	printf("\n������������");
	PreOrder_BiTree(T, Print_BiTreeNode);
	//�������������
	printf("\n������������");
	InOrder_BiTree(T, Print_BiTreeNode);
	//���������������
	printf("\n������������");
	PostOrder_BiTree(T, Print_BiTreeNode);
	system("pause");
	return 0;
}
*/ 
