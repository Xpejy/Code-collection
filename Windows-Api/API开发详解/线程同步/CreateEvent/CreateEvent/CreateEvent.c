#include <stdio.h>
#include <windows.h>


#define BUFFER_SIZE 16	//���鳤��	
#define FOR_TIMES 5		//��ʱʱ��

//�¼�������붨����ȫ����
HANDLE hEvent;				//ͬ��
BYTE lpSharedBuffer[16];	//�����ڴ�

//��������
void UseEvents(void);
DWORD WINAPI EventFunction(LPVOID lpParam);

int main()
{
	UseEvents();
}

void UseEvents(void)
{
	HANDLE hThread;	//���
	hEvent = CreateEvent(
		NULL,	//Ĭ�ϰ�ȫ����
		TRUE,	//�ֹ�����
		FALSE,	//��ʼ��Ϊδ����
		NULL	//δ����
		);
	if (hEvent == NULL)
	{
		printf("CreateEvent Error (%d)\n", GetLastError());
		return;
	}
	hThread = CreateThread(
		NULL,
		0,
		EventFunction,
		NULL,
		0,
		NULL
		);
	if (hThread == NULL)
	{
		printf("CreateThread Error (%d)\n", GetLastError());
		return;
	}
	Sleep(2000);			//����2000����
	CopyMemory(lpSharedBuffer, "Event", lstrlen("event"));
	SetEvent(hEvent);
}


DWORD WINAPI EventFunction(LPVOID lpParam)
{
	DWORD dwWaitResult;
	dwWaitResult = WaitForSingleObject(
		hEvent,			//Event���
		INFINITE		//���޵ȴ�
		);

	if (dwWaitResult != WAIT_OBJECT_0)
	{
		printf("Wait Error: %d\n", GetLastError());
		return 0;
	}

	printf(lpSharedBuffer);

	if (!ResetEvent(hEvent))
	{
		printf("SetEvent Error: %d\n", GetLastError());
		return 0;
	}

	return 1;
}