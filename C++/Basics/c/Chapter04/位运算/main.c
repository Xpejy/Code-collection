#include <stdio.h>

int main()
{
	int x = 1;
	int y = 2;
    unsigned z = 2;
	printf("������:%d\r\n",x&y);
	printf("������:%d\r\n",x|y);
	printf("�������:%d\r\n",x^y);
	printf("������:%d\r\n",~y);
	printf("�з�������:%d\r\n",y<<1);
	printf("�޷�������:%d\r\n",z<<1);
    
    printf("�з�������:%d\r\n",y>>1);
	printf("�޷�������:%d\r\n",z>>1);
	system("pause");
}