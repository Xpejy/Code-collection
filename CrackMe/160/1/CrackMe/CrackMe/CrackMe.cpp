// CrackMe.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "�������û���" << std::endl;
	int cName = getchar();
	if (cName > 0x21)
	{
		cName *= 0x29;
		cName *= 2;
		printf("Serial: CW-%4d-CRACKED\r\n", cName);
	}
	else
	{
		printf("Error");
	}
	system("pause");
	return 0;
}

