// Key.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <windows.h>
void Keygen(const char* user, char* code)
{
	//�����к��õ��ܳ�
	const char szBuffer[] = { "ZWATRQLCGHPSXYENVBJDFKMU" };

	unsigned char a = 0;
	for (int i = 0; i<strlen(user); ++i) a += user[i];
	a %= 0x18;
	//���кŵ�2λ��ΪE
	code[1] = 'E';
	//���кŵ�1λ
	code[0] = szBuffer[a];
	int b = a;
	if (b > 0x18) b -= 0x18;
	b += a;
	if (b > 0x18) b -= 0x18;
	//���кŵ�3λ
	code[2] = szBuffer[b];
	//���кŵ�4-9λ
	for (int i = 3; i<9; ++i)
	{
		b = b + code[i - 1] - 'A';
		if (b > 0x18) b -= 0x18;
		code[i] = szBuffer[b];
	}
	//���кŵ�10λ
	int c = 0;
	for (int i = 0; i<9; ++i) c += code[i];
	c /= 9;
	code[9] = c;
	code[10] = '\0';
}
int _tmain(int argc, _TCHAR* argv[])
{
	char szUser[50];
	char szCode[50];
	printf("�������û�����");
	scanf("%s", szUser);

	Keygen(szUser, szCode);
	printf("���к��ǣ� %s\n", szCode);
	system("pause");
	GlobalMemoryStatus
	return 0;
}

