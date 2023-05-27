#include <windows.h>
#include <iostream>

int main(void)
{

STARTUPINFOW si = { 0 };
PROCESS_INFORMATION pi = { 0 };

	if(!CreateProcess(
		L"C:\\Windows\\System32\\notepad.exe",
		NULL,
		NULL,
		NULL,
		FALSE,
		BELOW_NORMAL_PRIORITY_CLASS,
		NULL,
		NULL,
		&si,
		&pi
		)){
		std::cout << "(-) Failed to create process, error: ", GetLastError();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
