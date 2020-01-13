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
//赋于串T的值为chars
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
//串S存在 由串S复制到串T
void StrCopy(SString &T, SString S) {
	int i = 0;
	for (; i <= S[0]; i++) {
		*(T + i) = S[i];
	}
}
//若串S为空 返回TRUE 否则返回FALSE
Status StrEmpy(SString S) {
	if (S[0] == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
//操作结果：若S > T，则返回值 = 0；若S = T，则返回值 < 0；若S < T，则返回值 < 0
int StrCompare(SString S, SString T) {
	int i;
	for (i = 1; i <= S[0] && i <= T[0]; i++) {
		if (S[i] != T[i])
			return S[i] - T[i];
	}
	return S[0] - T[0];
}
//返回长度
int StrLength(SString S) {
	return S[0];
}
//将S清空
void ClearString(SString &S) {
	*S = 0;
}
//初始条件：串 S1 和 S2 存在。
//操作结果：用 T 返回由 S1 和 S2 联接而成的新串。
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
//初始条件：串S存在，1≤pos≤StrLength(S)且0≤len≤StrLength(S) - pos + 1。
//操作结果：用 Sub 返回串S的第 pos 个字符起长度为 len 的子串。
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
//初始条件：串S和T存在，T 是非空串，1≤pos≤StrLength(S)。
//操作结果：若主串S中存在和串T值相同的子串，
//则返回它在主串S中第pos个字符之后第一次出现的位置；否则函数值为0。
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
//初始条件：串 S 和 T 存在，1≤pos≤StrLength(S)＋1。
//操作结果：在串 S 的第 pos 个字符之前插入串 T。
Status StrInsert(SString &S, int pos, SString T) {
	if (pos<1 || pos>StrLength(S) + 1) {
		return ERROR;
	}
	if (*S + T[0] <= MAXSTRLEN) {//长度够长
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

//初始条件：串 S 存在，1≤pos≤StrLength(S) - len + 1。
//操作结果：从串 S 中删除第 pos 个字符起长度为 len 的子串。
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

//初始条件：串 S，T 和 V 存在，T 是非空串。
//操作结果：用V替换主串S中出现的所有与T相等的不重叠的子串。
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
	cout << "输入S1:";
	gets_s(str);
	StrAssign(S1, str);
	cout << "输出S1:";
	for (int i = 1; i<=S1[0]; i++) {
		cout<<S1[i];
	}
	cout << endl;
	cout << "查找字符串的位序:";
	gets_s(str);
	StrAssign(T, str);
	cout << str << "对的位序为:" << Index(S1, T, 1) << endl;
	cout << "输出需要改的字符串:";
	gets_s(str);
	StrAssign(T, str);
	cout << "输出改为的字符串:";
	gets_s(str);
	StrAssign(V, str);
	Replace(S1, T, V);
	cout << "输出更改后新的S1字符串:";
	for (int i = 1; i <= S1[0]; i++) {
		cout << S1[i];
	}
	cout << endl;
	cout << "输入S2:";
	gets_s(str);
	StrAssign(S2, str);
	cout << "输出S2:";
	for (int i = 1; i <= S2[0]; i++) {
		cout << S2[i];
	}
	cout << endl;
	cout << "S1和S2连接成新的字符串S:";
	Concat(S, S1, S2);
	cout << "输出拼接好的S:";
	for (int i = 1; i <= S[0]; i++) {
		cout << S[i];
	}
	cout << endl;
	cout << "串S的长度为:" << StrLength(S) << endl;
	cout << "请删除S1" << endl;
	StrDelete(S, 1, StrLength(S1));
	cout << "此时串S为：" << endl;
	for (int i = 1; i <= S[0]; i++) {
		cout << S[i];
	}
	cout<<"请删除S2" << endl;
	StrDelete(S, 1, StrLength(S2));
	cout << "此时串S为：" << endl;
	for (int i = 1; i <= S[0]; i++) {
		cout << S[i];
	}
	cout << endl;
	system("pause");

}
*/