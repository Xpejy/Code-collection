
#include <Windows.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024

int main()
{
	CHAR szLogicalDriveStrings[BUFSIZE];
	ZeroMemory(szLogicalDriveStrings, BUFSIZE);//��Ҳ��һ��API������ �������ַ���
	GetLogicalDriveStrings(BUFSIZE - 1, szLogicalDriveStrings);

	//printf("%s\n", szLogicalDriveStrings);

	PCHAR psz;

	psz = (PCHAR)szLogicalDriveStrings;
	do{
		printf("%s\n", psz);
		psz += (strlen(psz) + 1);
	} while ((*psz) != '\0');

	system("pause");
}
