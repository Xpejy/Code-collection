// CrackMe.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	
	char buff[64] = { "systemk1t" };
	int len = strlen(buff);
	if (len > 0)
	{
		int nRet = len * 0x17CFB;
		nRet += buff[0];
		printf("AKA-%d", nRet);
	}
	else
	{
		;
	}
	system("pause");
	return 0;
}

