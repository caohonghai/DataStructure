/*
Status ListInsert_Sq(Sqlist &L, int i, ElemType e) {
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length >= L.listsize) {
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) {
			exit(OVERFLOW);
		}
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i - 1]);// q为插入位置
	for (p = &(L.elem[L.length - 1]); p >= q; p--) {
		*(p + 1) = *p;//向后移
	}
	*q = e;
	L.length++;
	return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
	if (i<1 || i>L.length + 1)
		return ERROR;
	q = &(L.elem[i - 1]);// q为删除的位置
	q++;
	p = L.elem + L.length - 1;
	for (; q <= p; q++) {
		*(q - 1) = *q;
	}
	L.length--;
	return OK;
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
	// 将线性表La,Lb的元素按值递增排序
	// 归并La和Lb得到新的线性表Lc
	pa = La.elem;// 首地址
	pb = Lb.elem;// 首地址
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)
		exit(OVERFLOW);// 分配空间失败
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb) { //*pa元素小于*pb 将较小的*pa赋值给*pc;
			*pc++ = *pa++;
		}
		else {
			*pc++ = *pb++;
		}
	}
	while (pa <= pa_last) // 如果La.length>Lb.length把剩余的La添加到Lc中
		*pc++ = *pa++;
	while (pb <= pb_last)// 如果La.length<Lb.length把剩余的Lb添加到Lc中
		*pc++ = *pb++;
}


*/