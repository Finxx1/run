#include <Windows.h>

int main(int argc, char** argv) {
    SetEnvironmentVariable("__COMPAT_LAYER", "RunAsInvoker");

    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    PROCESS_INFORMATION pi;

    CreateProcessA(argv[1], NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);

    return 0;
}