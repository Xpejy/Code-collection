

/* ͷ�ļ���*/
#include <windows.h>
#include <stdio.h>

/* ************************************
* int main(void)
* ����	��ʾʹ��CreateDirectory����Ŀ¼
**************************************/
int main(void)
{
	//�ڳ���ĵ�ǰĿ¼�´�����sub_dir����Ŀ¼
	LPSTR szDirPath = "sub_dir";
	if (!CreateDirectory(szDirPath, NULL))
	{
		printf("����Ŀ¼ %s ����\n", szDirPath);
		return 1;
	}

	//��F���´���Ŀ¼��example_dir��
	szDirPath = "F:\\example_dir";
	if (!CreateDirectory(szDirPath, NULL))
	{
		printf("����Ŀ¼ %s ����\n", szDirPath);
		return 1;
	}
	printf("�ɹ�\n");

	return 0;
}