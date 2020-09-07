#include <windows.h>
#include <iostream>
#include <tchar.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hslot;

	TCHAR slotname[] = TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateFile(slotname, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

	if (hslot == INVALID_HANDLE_VALUE)
	{

		std::cout << "SLOT WRITING FAILED" << std::endl;
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;

	}

	char out1[8] = "test ";
	DWORD dwBytesWrite;

	WriteFile(hslot, out1, sizeof(out1), &dwBytesWrite, NULL);

	std::cout << "Данные, записанные в ящик: " << out1 << std::endl;
	system("pause");
	CloseHandle(hslot);
	return 0;
}