DWORD WINAPI Initialize() {



	DWORD NullFC;
	VirtualProtect((PVOID)&FreeConsole, 1, PAGE_EXECUTE_READWRITE, &NullFC);
	*(BYTE*)(&FreeConsole) = 0xC3;
	AllocConsole();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTitle("Zoof - Open Source Parser Project");

	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
  
SetConsoleTextAttribute(hConsole, 14);
std::cout << "This open source project was made by Environment, Pudding Mug and Niftyhearts, Enjoy!";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Welcome to Zoof, Please enter your script!\r\n";
  std::cout << "[SCRIPT]: ";


bool WINAPI DllMain(HMODULE InjectedExploitModule, DWORD ReasonForCall, LPVOID Reserved) {
	UNREFERENCED_PARAMETER(InjectedExploitModule);
	UNREFERENCED_PARAMETER(Reserved);
	if (ReasonForCall == DLL_PROCESS_ATTACH) {
		CreateThread(0, NULL, (LPTHREAD_START_ROUTINE)&Initialize, NULL, NULL, NULL);
	

	};
	return true;
};
