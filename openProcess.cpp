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

HANDLE hProcess = ::OpenProcess(
		PROCESS_ALL_ACCESS, TRUE, pi.dwProcessID
		);

	if(!hProcess){
		std::cout << "(-) Failed to open process, error: ", GetLastError();
		return EXIT_FAILURE;
	}

	if(hProcess) ::CloseHandle(hProcess);
	std::cout << "(+) Process Handle: ", hProcess;
	return EXIT_SUCCESS;
}
