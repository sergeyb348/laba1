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

	std::cout << "Ожидание...." << std::endl;
	int n;
	std::cin >> n;
	char out2[8] = "msg";
	DWORD dwBytesWrite;

	WriteFile(hslot, out2, sizeof(out2), &dwBytesWrite, NULL);
	WriteFile(hslot, &n, sizeof(n), &dwBytesWrite, NULL);

	std::cout << "Данные, записанные в ящик: " << out2 << std::endl << n << std::endl;
	system("pause");
	CloseHandle(hslot);
	return 0;
}