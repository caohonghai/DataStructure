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
typedef int ElemType;//现在是int用字符串的时候用char 修改的简便性 

#define LIST_INIT_SIZE   100  //线性表存储空间的初始分配量
#define LISTINCREMENT  10  //线性表存储空间的分配增量

typedef struct LNode {
	ElemType   data;
	struct LNode  *next;
}LNode, *LinkList;
/*初始化单链表*/
Status InitList(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) exit(OVERFLOW);
	L->next = NULL;
	return OK;
}
/*清空单链表*/
void ClearList(LinkList L) {
	L->next = NULL;
}
/*检查单链表是否为空*/
Status ListEmpty(LinkList L) {
	if (L->next == NULL)
		return TRUE;
	else
		return FALSE;
}
/*遍历输出单链表数据*/
void ListTraverse(LinkList L) {
	//新建立一个p结点
	LinkList p = (LinkList)malloc(sizeof(LNode));
	//p挂在线性表L的next
	p = L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
/*返回线性表长度*/
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
/*获取线性表的指定值*/
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
/*返回 L 中第1个与 e元素相等的元素位序*/
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
/* 插入元素*/
Status ListInsert(LinkList &L, int i, ElemType e) {
	//带头节点的线性表L的第i个元素之前插入元素e
	LinkList p, s;
	int j = 0;
	p = L;
	while (p&&j < i - 1) {//寻找第i-1个结点
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
/*删除第i个元素 并且用e返回其值*/
Status ListDelet(LinkList &L, int i, ElemType &e) {
	LinkList p, q;
	p = L;
	int j = 0;
	while (p->next&&j < i - 1)//寻找第i个结点,并令p指向其前驱
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