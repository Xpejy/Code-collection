#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int fun(int a,int b)
{
	return  a+b;
}

int main()
{
	//���庯��ָ�����
	int (__cdecl *pFun)(int,int);
	//Ϊ����ָ�������ֵ
	pFun = (int (__cdecl *)(int,int))fun;

	int r = pFun(1,2);
	printf("%d\r\n",r);
	return 0;
}

