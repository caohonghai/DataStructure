/*
#include<iostream>
#include<string.h>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSTRLEN 255
typedef int Status;
typedef unsigned char SString[MAXSTRLEN+1];
//���ڴ�T��ֵΪchars
Status StrAssign(SString &T, char* chars) {
	if (strlen(chars) > MAXSTRLEN)
		return ERROR;
	else {
		*T = strlen(chars);
		int i=1;
		for (i = 1; i <= *T; i++) {
			*(T + i) = chars[i - 1];
		}
		return OK;
	}
}
//��S���� �ɴ�S���Ƶ���T
void StrCopy(SString &T, SString S) {
	int i = 0;
	for (; i <= S[0]; i++) {
		*(T + i) = S[i];
	}
}
//����SΪ�� ����TRUE ���򷵻�FALSE
Status StrEmpy(SString S) {
	if (S[0] == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
//�����������S > T���򷵻�ֵ = 0����S = T���򷵻�ֵ < 0����S < T���򷵻�ֵ < 0
int StrCompare(SString S, SString T) {
	int i;
	for (i = 1; i <= S[0] && i <= T[0]; i++) {
		if (S[i] != T[i])
			return S[i] - T[i];
	}
	return S[0] - T[0];
}
//���س���
int StrLength(SString S) {
	return S[0];
}
//��S���
void ClearString(SString &S) {
	*S = 0;
}
//��ʼ�������� S1 �� S2 ���ڡ�
//����������� T ������ S1 �� S2 ���Ӷ��ɵ��´���
Status Concat(SString &T, SString S1, SString S2) {
	if (S1[0] + S2[0] > MAXSTRLEN) {
		for (int i = 1; i <= S1[0]; i++) {
			*(T + i) = S1[i];
		}
		for (int i = 1; i <= MAXSTRLEN - S1[0]; i++) {
			*(T + S1[0] + 1) = S2[i];
		}
		*T = MAXSTRLEN;
		return ERROR;
	}
	else {
		for (int i = 1; i <= S1[0]; i++) {
			*(T + i) = S1[i];
		}
		for (int i = 1; i <= S2[0]; i++) {
			*(T + S1[0] + i) = S2[i];
		}
		*T = S1[0] + S2[0];
		return TRUE;
	}
}
//��ʼ��������S���ڣ�1��pos��StrLength(S)��0��len��StrLength(S) - pos + 1��
//����������� Sub ���ش�S�ĵ� pos ���ַ��𳤶�Ϊ len ���Ӵ���
Status SubString(SString &Sub, SString S, int pos, int len) {
	if (pos<1 || pos>StrLength(S) || len<0 || len>StrLength(S) - pos + 1) {
		return ERROR;
	}
	else {
		for (int i = 1; i <= len; i++) {
			*(Sub + i) = S[pos + i - 1];
		}
		*Sub = len;
		return OK;
	}
}
//��ʼ��������S��T���ڣ�T �Ƿǿմ���1��pos��StrLength(S)��
//���������������S�д��ںʹ�Tֵ��ͬ���Ӵ���
//�򷵻���������S�е�pos���ַ�֮���һ�γ��ֵ�λ�ã�������ֵΪ0��
Status Index(SString S, SString T, int pos) {
	int i = pos, j = 1;
	if (pos<1 || pos>StrLength(S))
		return ERROR;
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j]) {
			++i; ++j;
		}
		else {
			i = i - j + 2;//i=i-(j-1)+1;
			j = 1;
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;

}
//��ʼ�������� S �� T ���ڣ�1��pos��StrLength(S)��1��
//����������ڴ� S �ĵ� pos ���ַ�֮ǰ���봮 T��
Status StrInsert(SString &S, int pos, SString T) {
	if (pos<1 || pos>StrLength(S) + 1) {
		return ERROR;
	}
	if (*S + T[0] <= MAXSTRLEN) {//���ȹ���
		for (int i = *S; i >= pos; i--) {
			*(S + i + T[0]) = *(S + i);
		}
		for (int i = pos; i < pos + T[0]; i++) {
			*(S + i) = T[i - pos + 1];
		}
		*S += T[0];
		return OK;
	}
	else {//
		for (int i = MAXSTRLEN; i >= pos; i--) {
			*(S + i) = *(S + i - T[0]);
		}
		for (int i = pos; i < pos + T[0]; i++) {
			*(S + i) = T[i - pos + 1];
		}
		*S = MAXSTRLEN;
		return FALSE;
	}
}

//��ʼ�������� S ���ڣ�1��pos��StrLength(S) - len + 1��
//����������Ӵ� S ��ɾ���� pos ���ַ��𳤶�Ϊ len ���Ӵ���
Status StrDelete(SString &S, int pos, int len) {
	if (pos<1 || pos>StrLength(S) - len + 1) {
		return ERROR;
	}
	for (int i = pos; i <= pos + len; i++) {
		*(S + i) = *(S + i + len);
	}
	*S -= len;
	return OK;
}

//��ʼ�������� S��T �� V ���ڣ�T �Ƿǿմ���
//�����������V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ���
Status Replace(SString &S, SString  T, SString V) {
	int i = 1;
	if (StrEmpy(S))
		return ERROR;
	do {
		i = Index(S, T, i);
		if (i) {
			StrDelete(S, i, StrLength(T));
			StrInsert(S, i, V);
			i += StrLength(V);
		}
	} while (i);
	return OK;

}

int main() {
	SString S1, T, V, S2, S;
	char str[MAXSTRLEN + 1];
	cout << "����S1:";
	gets_s(str);
	StrAssign(S1, str);
	cout << "���S1:";
	for (int i = 1; i<=S1[0]; i++) {
		cout<<S1[i];
	}
	cout << endl;
	cout << "�����ַ�����λ��:";
	gets_s(str);
	StrAssign(T, str);
	cout << str << "�Ե�λ��Ϊ:" << Index(S1, T, 1) << endl;
	cout << "�����Ҫ�ĵ��ַ���:";
	gets_s(str);
	StrAssign(T, str);
	cout << "�����Ϊ���ַ���:";
	gets_s(str);
	StrAssign(V, str);
	Replace(S1, T, V);
	cout << "������ĺ��µ�S1�ַ���:";
	for (int i = 1; i <= S1[0]; i++) {
		cout << S1[i];
	}
	cout << endl;
	cout << "����S2:";
	gets_s(str);
	StrAssign(S2, str);
	cout << "���S2:";
	for (int i = 1; i <= S2[0]; i++) {
		cout << S2[i];
	}
	cout << endl;
	cout << "S1��S2���ӳ��µ��ַ���S:";
	Concat(S, S1, S2);
	cout << "���ƴ�Ӻõ�S:";
	for (int i = 1; i <= S[0]; i++) {
		cout << S[i];
	}
	cout << endl;
	cout << "��S�ĳ���Ϊ:" << StrLength(S) << endl;
	cout << "��ɾ��S1" << endl;
	StrDelete(S, 1, StrLength(S1));
	cout << "��ʱ��SΪ��" << endl;
	for (int i = 1; i <= S[0]; i++) {
		cout << S[i];
	}
	cout<<"��ɾ��S2" << endl;
	StrDelete(S, 1, StrLength(S2));
	cout << "��ʱ��SΪ��" << endl;
	for (int i = 1; i <= S[0]; i++) {
		cout << S[i];
	}
	cout << endl;
	system("pause");

}
*/