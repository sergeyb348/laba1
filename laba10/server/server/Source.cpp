#include <windows.h>
#include <iostream>
#include <tchar.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hslot;
	TCHAR slotname[] = TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateMailslot(slotname, 0, MAILSLOT_WAIT_FOREVER, NULL);

	
	if (hslot == INVALID_HANDLE_VALUE) {
		std::cout << "SLOT FAILED" << std::endl;
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;
	}

	std::cout << "Сервер ожидает..." << std::endl;
	char out1[20], out2[20];
	int nData;
	DWORD dwBytesRead;


	ReadFile(hslot, out1, sizeof(out1), &dwBytesRead, (LPOVERLAPPED)NULL);
	ReadFile(hslot, out2, sizeof(out2), &dwBytesRead, (LPOVERLAPPED)NULL);
	ReadFile(hslot, &nData, sizeof(nData), &dwBytesRead, (LPOVERLAPPED)NULL);


	std::cout << "Прочитанные данные :" << std::endl << out1 << out2 << std::endl << nData << std::endl;
	system("pause");
	CloseHandle(hslot);
	return 0;
}