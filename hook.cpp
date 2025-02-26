#include <windows.h>
#include <iostream>

extern "C" __declspec(dllexport) void ModifyMemory() {
    uintptr_t targetAddress = 0x004FFDAC;

    int* targetValue = reinterpret_cast<int*>(targetAddress);

    DWORD oldProtect;
    
    if (VirtualProtect(targetValue, sizeof(int), PAGE_EXECUTE_READWRITE, &oldProtect)) {
        *targetValue = 100;
        VirtualProtect(targetValue, sizeof(int), oldProtect, &oldProtect);
    }

    std::cout << "Memory at address 0x" << std::hex << targetAddress 
              << " has been modified to: " << *targetValue << std::endl;
    
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        ModifyMemory();
    }
    return TRUE;
}
