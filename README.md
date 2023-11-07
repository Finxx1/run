# run
Allows for running programs that normally can't run without administrator
Why not just use a batch file?
Because some systems have CMD.EXE blocked. This tool allows you to run executables without CMD.EXE

It does the same thing as the usual batch script does, though.
Source:
```c
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
```
Very quick and dirty.
