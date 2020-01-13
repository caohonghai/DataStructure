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
typedef struct BiTNode {	//��㶨��
	TElemType data;
	struct BiTNode * lchild, *rchild;
} BiTNode, *BiTree;
//���庯��ָ��
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

//�ж��Ƿ�Ϊ����
Status BiTreeEmpty(BiTree T) {
	if (T) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

//������������
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

//����һ����
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

//���ظ��ڵ�
char Root(BiTree T) {
	if (T == NULL) {
		cout << "�޸��ڵ�" << endl;
	}
	else {
		return  T->data;
	}
}

//�����
void ClearBiTree(BiTree *T) {
	*T = NULL;
}

//�����ܹ�������
int  Num_Of_Node(BiTree t)
{
	if (t == NULL)
		return 0;
	else
		return Num_Of_Node(t->lchild) + Num_Of_Node(t->rchild) + 1;
}

//����Ҷ�ӽ�����
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

//�ж�ĳ��ֵ�ǲ������Ľ��
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
//��ʼ����:������T��,e��T��ĳ�����
//�������:��e��T�ķǸ����,�򷵻�����˫��,���򷵻�"��"
{
	if (T){
		if (T->data == e->data)//���ڵ���ڴ����ֵ ���ؿ�
			return NULL;
		if (T->lchild != NULL && T->lchild->data == e->data || T->rchild != NULL && T->rchild->data == e->data) {
			return T;//�ҵ��õ�
		}
		else {//�ݹ����
			BiTNode* tempP = NULL;
			if (tempP = Parent(T->lchild, e))
				return tempP;
			if (tempP = Parent(T->rchild, e))
				return tempP;
		}
	}
	else {//Ϊ��
		return NULL;
	}
}

BiTree Search(BiTree T, BiTNode* e)
//e��T�е�ĳ���ڵ�, ����e�ڵ�
{
	if (T) {
		if (T->data == e->data) {
			return T;//�ҵ��õ�
		}
		else {//�ݹ����
			BiTNode* tempP = NULL;
			if (tempP = Search(T->lchild, e))
				return tempP;
			if (tempP = Search(T->rchild, e))
				return tempP;
		}
	}
	else {//Ϊ��
		return NULL;
	}
}

BiTree LeftChild(BiTree T, BiTNode* e)
//��ʼ������������ T ����,e ��T��ĳ�����
//������������� e ������,��e������,�򷵻�"��"
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
//��ʼ������������ T ���ڣ�e �� T ��ĳ�����
//�������������e���Һ���,�� e���Һ���,�򷵻�"��"
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
//��ʼ����:������ T ���ڣ�e �� T ��ĳ�����
//�������:���� e�����ֵ�,�� e ����˫�׵����ӻ������ֵ�,�򷵻�"��"
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
//��ʼ����:������ T ����,e��T�Ľ�㡣
//�������:���� e �����ֵ�,�� e����˫�׵��Һ��ӻ������ֵ�,�򷵻�"��"
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
//��ʼ������������T����,e ��T ��ĳ�����
//������������e��ֵΪvalue
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
	//����������123###4#56###
	BiTree T;
	BiTree node = NULL;
	node = (BiTNode*)malloc(sizeof(BiTNode));
	TElemType temp;
	//����������ʼΪһ���յĶ�����
	InitBiTree(&T);
	//����������
	CreateBiTree(T);
	cout << "��Ϊ��";
	cout << Root(T);
	printf("\n������������");
	PreOrder_BiTree(T, Print_BiTreeNode);
	//�������������
	printf("\n������������");
	InOrder_BiTree(T, Print_BiTreeNode);
	//���������������
	printf("\n������������");
	PostOrder_BiTree(T, Print_BiTreeNode);
	//printf("\n��α��������");
	//levelTraverse(T);
	cout << endl << "�����Ϊ��" << BiTreeDepth(T) << endl;
	cout << "�ڵ����:" << Num_Of_Node(T) << endl;
	//�ж��Ƿ��ڵ�ǰ����
	cout << "���������жϵ�ǰ�����Ƿ������У��������������˫�ף�";
	cin >> temp;
	if (find(T, temp)) {
		cout << temp << "������" << endl;
		node->data = temp;
		if (Parent(T, node) != NULL) {
			cout << temp << "��˫��Ϊ��" << Parent(T, node)->data << endl;
		}
		else {
			cout << "NO Parent!" << endl;
		}
	}
	else {
		cout << temp << "��������" << endl;
	}
	//����
	cout << "���������жϸ����ݵ������Ƿ�Ϊ��,�ǿ����������:";
	cin >> temp;
	node->data = temp;
	if (LeftChild(T, node)!=NULL) {
		cout << temp << "������Ϊ��" << LeftChild(T, node)->data << endl;
	}
	else {
		cout <<"ERROR!\t"<< temp << "�����Ӳ�����!" << endl;
	}
	//�Һ���
	cout << "���������жϸ����ݵ��Һ����Ƿ�Ϊ��,�ǿ�������Һ���:";
	cin >> temp;
	node->data = temp;
	if (RightChild(T, node)) {
		cout << temp << "���Һ���Ϊ��" << RightChild(T, node)->data << endl;
	}
	else {
		cout << "ERROR!\t" << temp << "���Һ��Ӳ�����!" << endl;

	}
	//���ֵ�
	cout << "���������жϸ������Ƿ�������ֵ�,��������������ֵ�:";
	cin >> temp;
	node->data = temp;
	if (LeftSibling(T, node) != ERROR) {
		cout << temp << "�����ֵ�Ϊ��" << LeftSibling(T, node)->data << endl;
	}
	else {
		cout << "ERROR!\t" << temp << "�����ֵܲ�����!" << endl;

	}
	//���ֵ�
	cout << "���������жϸ������Ƿ�������ֵ�,��������������ֵ�:";
	cin >> temp;
	node->data = temp;
	if (RightSibling(T, node) != ERROR) {
		cout << temp << "�����ֵ�Ϊ��" << RightSibling(T, node)->data << endl;
	}
	else {
		cout << "ERROR!\t" << temp << "�����ֵܲ�����!" << endl;

	}

	//���e��ֵΪvalue
	cout << "����������ĳ��������¸�ֵ:";
	cin >> node->data;
	cout << "���丳ֵΪ��";
	TElemType temp2;
	cin >> temp2;
	if (Assign(T, node, temp2)) {
		cout << "�µ�ǰ�����Ϊ��";
		PreOrder_BiTree(T, Print_BiTreeNode);
		cout << endl;
	}
	else {
		cout << "ERROR!" << endl;
	}


	//Ҷ�ӽ�����
	cout << "Ҷ�ӽڵ����:" << LeavesNum(T) << endl;
	ClearBiTree(&T);
	if (T == NULL) {
		cout << "�����ѱ����" << endl;
	}
	DestroyBiTree(&T);
	cout << "�����ѱ�����" << endl;

	system("pause");
	return 0;
}

*/