#include <windows.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 500

HKEY hkey = NULL;
char src[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
char tar[MAX];

/*
�������32λϵͳ��д��32λĿ¼���������64λϵͳ�ǻ�д��64λĿ¼��
32λĿ¼:"HKEY_LOCAL_MACHINE\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
64λĿ¼:"HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run"
�����Ƽ�������RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WRITE | KEY_WOW64_64KEY, &hKey);
*/


int autostart() {
	::GetModuleFileName(NULL, LPWSTR(tar), MAX);	//��ȡ����·��

	LONG ret1 = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, LPCWSTR(src), 0, KEY_ALL_ACCESS, &hkey);	//��ע���
	if (ret1 != ERROR_SUCCESS)
		return 1;

	LONG ret2 = ::RegSetValueEx(hkey, LPCWSTR("test"), 0, REG_SZ, (const unsigned char*)tar, MAX);	//�޸�ע���
	if (ret2 != ERROR_SUCCESS)
		return 2;

	return 0;
}

int main() {
	autostart();
	return 0;
};
