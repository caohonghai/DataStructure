#include <iostream>
#include <stdlib.h>
using namespace std;

#define TRUE     1
#define FALSE    0
#define OK       1
#define ERROR    0
#define INFEASIBLE   -1
#define OVERFLOW     -2

typedef int Status;
typedef int ElemType;//������int���ַ�����ʱ����char �޸ĵļ���� 

#define LIST_INIT_SIZE   100  //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT  10  //���Ա�洢�ռ�ķ�������

typedef struct LNode {
	ElemType   data;
	struct LNode  *next;
}LNode, *LinkList;
/*��ʼ��������*/
Status InitList(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) exit(OVERFLOW);
	L->next = NULL;
	return OK;
}
/*��յ�����*/
void ClearList(LinkList L) {
	L->next = NULL;
}
/*��鵥�����Ƿ�Ϊ��*/
Status ListEmpty(LinkList L) {
	if (L->next == NULL)
		return TRUE;
	else
		return FALSE;
}
/*�����������������*/
void ListTraverse(LinkList L) {
	//�½���һ��p���
	LinkList p = (LinkList)malloc(sizeof(LNode));
	//p�������Ա�L��next
	p = L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
/*�������Ա���*/
int ListLength(LinkList L) {
	LinkList p;
	int len = 0;
	p = L->next;
	while (p != NULL) {
		len++;
		p = p->next;
	}
	return len;
}
/*��ȡ���Ա��ָ��ֵ*/
Status GetElem(LinkList L, int i, ElemType &e) {
	LinkList p;
	int j = 1;
	p = L->next;
	while (p != NULL && j < i) {
		j++;
		p = p->next;
	}
	if (j == i) {
		e = p->data;
		return OK;
	}
	else {
		return FALSE;
	}
}
/*���� L �е�1���� eԪ����ȵ�Ԫ��λ��*/
int LocateElem(LinkList L, ElemType e) {
	LinkList p;
	int i = 0;
	p = L->next;
	while (p) {
		i++;
		if (p->data == e) {
			return i;
		}
		p = p->next;
	}
	return 0;
}
/* ����Ԫ��*/
Status ListInsert(LinkList &L, int i, ElemType e) {
	//��ͷ�ڵ�����Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
	LinkList p, s;
	int j = 0;
	p = L;
	while (p&&j < i - 1) {//Ѱ�ҵ�i-1�����
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
/*ɾ����i��Ԫ�� ������e������ֵ*/
Status ListDelet(LinkList &L, int i, ElemType &e) {
	LinkList p, q;
	p = L;
	int j = 0;
	while (p->next&&j < i - 1)//Ѱ�ҵ�i�����,����pָ����ǰ��
	{
		j++;
		p = p->next;
	}
	if (!p->next || j > i - 1)
		return ERROR;
	q = p->next;
	e = p->data;
	p->next = q->next;
	free(q);
	return OK;
}
int main() {

}