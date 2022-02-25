#include <stdio.h>

#pragma warning(push, 3)
#include <windows.h>
#pragma warning(pop)

LRESULT CALLBACK MainWndowProc(HWND WindowHandle, UINT Message, WPARAM WParam, LPARAM LParam);

int WinMain(HINSTANCE Instance, HINSTANCE PreviousInstance, PSTR CommandLine, int CmdShow)
{

	UNREFERENCED_PARAMETER(PreviousInstance);

	UNREFERENCED_PARAMETER(CommandLine);

	UNREFERENCED_PARAMETER(CmdShow);

    WNDCLASSEXA WindowClass = { 0 };
    HWND WindowHandle = 0;
    WindowClass.cbSize = sizeof(WNDCLASSEXA);
    WindowClass.style = 0;
    WindowClass.lpfnWndProc = MainWndowProc;
    WindowClass.cbClsExtra = 0;
    WindowClass.cbWndExtra = 0;
    WindowClass.hInstance = Instance;
    WindowClass.hIcon = LoadIconA(NULL, IDI_APPLICATION);
    WindowClass.hIconSm = LoadIconA(NULL, IDI_APPLICATION);
    WindowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
    WindowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    WindowClass.lpszMenuName = NULL;
    WindowClass.lpszClassName = "GAME_B_WINDOWCLASS";
   
    if (RegisterClassExA(&WindowClass) == 0)
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);

        return (0);
    }

    WindowHandle = CreateWindowExA(WS_EX_CLIENTEDGE, WindowClass.lpszClassName, "Window Title", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 240, 120, NULL, NULL, Instance, NULL);

    if (WindowHandle == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);

        return (0);
    }


    MSG Message = { 0 };

    while (GetMessageA(&Message, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Message);
        DispatchMessageA(&Message);
    }

	return(0);
}

LRESULT CALLBACK MainWndowProc(HWND WindowHandle, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT Result = 0;

    switch (Message)
    {
        default:
        {
            Result = DefWindowProcA(WindowHandle, Message, WParam, LParam);
        }
    }

    return(Result);
}