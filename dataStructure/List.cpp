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
	q = &(L.elem[i - 1]);// qΪ����λ��
	for (p = &(L.elem[L.length - 1]); p >= q; p--) {
		*(p + 1) = *p;//�����
	}
	*q = e;
	L.length++;
	return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
	if (i<1 || i>L.length + 1)
		return ERROR;
	q = &(L.elem[i - 1]);// qΪɾ����λ��
	q++;
	p = L.elem + L.length - 1;
	for (; q <= p; q++) {
		*(q - 1) = *q;
	}
	L.length--;
	return OK;
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
	// �����Ա�La,Lb��Ԫ�ذ�ֵ��������
	// �鲢La��Lb�õ��µ����Ա�Lc
	pa = La.elem;// �׵�ַ
	pb = Lb.elem;// �׵�ַ
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)
		exit(OVERFLOW);// ����ռ�ʧ��
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb) { //*paԪ��С��*pb ����С��*pa��ֵ��*pc;
			*pc++ = *pa++;
		}
		else {
			*pc++ = *pb++;
		}
	}
	while (pa <= pa_last) // ���La.length>Lb.length��ʣ���La��ӵ�Lc��
		*pc++ = *pa++;
	while (pb <= pb_last)// ���La.length<Lb.length��ʣ���Lb��ӵ�Lc��
		*pc++ = *pb++;
}


*/