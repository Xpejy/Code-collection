#include <stdio.h>
#include <Windows.h>
int main()
{
	//���庯��ָ�����ͱ���
	//int (__stdcall *pFun)(int,int,int,int,int);
	int (__stdcall *pFun)(int,int,int,int);
	//pFun = (int (__stdcall *)(int,int,int,int,int)) 0x75CBFD1E;
	
	
	MessageBox(NULL,"123","321",0);

	pFun = (int (__stdcall *)(int,int,int,int)) &MessageBox;
	pFun(0,0,0,0);
	return 0;

}