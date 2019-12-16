#include <stdio.h>
#include <Windows.h>
#include <Psapi.h>
//����
#pragma comment (lib,"Psapi.lib")

//ʹ��__declspec(dllexport)������������
__declspec(dllexport) DWORD ExportExample(LPSTR szMsg, DWORD dwCode);


BOOL WINAPI DllMain(HINSTANCE hinstDLL,		//DLLģ��ľ��
	DWORD fdwReason,		//�������
	LPVOID lpvReserved)		//reserved
{
	switch (fdwReason)					//�ڲ�ͬ������µ���DllMain�������ֱ���
	{
	case DLL_PROCESS_ATTACH:			//����DLL
	{
		char lpMainModuleName[MAX_PATH];
		char lpMessage[MAX_PATH + 64];
		//��ȡPID����ģ����
		DWORD dwPID = GetCurrentProcessId();

		GetModuleBaseName(GetCurrentProcessId(), NULL, lpMainModuleName, MAX_PATH);
		wsprintf(lpMessage, "Process Name :%s PID: %u", lpMainModuleName, dwPID);
		MessageBox(NULL, lpMessage, "msg.dll", MB_OK);
	}
	case DLL_THREAD_ATTACH:		//�������߳�
	{
		break;
	}
	case DLL_THREAD_DETACH:		//�߳��˳�
	{
		break;
	}
	case DLL_PROCESS_DETACH:	//�ͷ�DLL
	{
		break;
	}
	return TRUE;
	}
}

/*************************************
* DWORD ExportExample(LPSTR szMsg, DWORD dwCode)
* ����	������������ʾ��Ϣ
*
* ����	LPSTR szMsg	�ַ����� DWORD dwCode ����
**************************************/

DWORD ExportExample(LPSTR szMsg, DWORD dwCode)
{
	LPVOID lpShowOut = HeapAlloc(GetProcessHeap(), 0, lstrlen(szMsg) + 100);
	wsprintf(lpShowOut, "%s,%d", szMsg, dwCode);
	MessageBox(NULL, lpShowOut, "�ɵ���������������Ϣ��", MB_OK);
	HeapFree(GetProcessHeap(), 0, lpShowOut);
	return 0;
}