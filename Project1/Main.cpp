#include "Functions.h"
#include "Definitions.h"
#include "Metamethods.h"
#include "RFunctions.h"

DWORD WINAPI Initialize() {



	DWORD NullFC;
	VirtualProtect((PVOID)&FreeConsole, 1, PAGE_EXECUTE_READWRITE, &NullFC);
	*(BYTE*)(&FreeConsole) = 0xC3;
	AllocConsole();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTitleA("Zoof - Open Source Parser Project");

	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
	std::cout << "Scanning... ";
	if (Scan())
		std::cout << "done!\n";
	else
		std::cout << "ERROR: Something went wrong while scanning.\n";
	std::cout << "Creating environment... ";
	luaL_openlibs(L);
	createmetas();
	rlua_register_rf(L);
	std::cout << "done!\n";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "This open source project was made by Niftyhearts, Enjoy!\n";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Welcome to Zoof, " << GetLocalPlayerName() << "! Please enter your script!\r\n\n";
	
	for (;;) {
		std::cout << "[SCRIPT]: ";
		std::string input;
		std::getline(std::cin, input);
		Execute(input);
	}
}


bool WINAPI DllMain(HMODULE InjectedExploitModule, DWORD ReasonForCall, LPVOID Reserved) {
	UNREFERENCED_PARAMETER(InjectedExploitModule);
	UNREFERENCED_PARAMETER(Reserved);
	if (ReasonForCall == DLL_PROCESS_ATTACH) {
		CreateThread(0, NULL, (LPTHREAD_START_ROUTINE)&Initialize, NULL, NULL, NULL);
	};
	return true;
};
