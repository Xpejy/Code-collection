#include <stdio.h>

struct Student{
	int x;
	int y;

};

int main()
{

	struct Student St[10];			//������80
	struct Student St1;				//8�ֽ�
	struct Student *St2[10];		//40�ֽڣ�4�ֽ�*10����Ա
	struct Student *St3;			//4�ֽڣ�ÿ��ָ��ռ��4�ֽ�
	int x = sizeof(St);				
	int y = sizeof(St1);
	int z = sizeof(St2);
	int t = sizeof(St3);

	return 0;
}