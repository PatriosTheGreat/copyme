#include <Windows.h>
#include <iostream>

enum class Operations {
    Copy = 1,
    Paste = 2,
    CleanClipboard = 3
};

enum class KeyCodes {
    A = 0x41,
    B = 0x42,
    C = 0x43,
    X = 0x58
};

int main() {
    if (RegisterHotKey(
        nullptr,
        static_cast<int>(Operations::Copy),
        MOD_ALT | MOD_NOREPEAT,
        static_cast<int>(KeyCodes::B)))
    {
        std::cout << "Copy hotkey 'ALT+b' registered, using MOD_NOREPEAT flag" << std::endl;
    }

    if (RegisterHotKey(
        nullptr,
        static_cast<int>(Operations::Paste),
        MOD_ALT | MOD_NOREPEAT,
        static_cast<int>(KeyCodes::C)))
    {
        std::cout << "Patse hotkey 'ALT+c' registered, using MOD_NOREPEAT flag" << std::endl;
    }

    if (RegisterHotKey(
        nullptr,
        static_cast<int>(Operations::CleanClipboard),
        MOD_ALT | MOD_NOREPEAT,
        static_cast<int>(KeyCodes::A)))
    {
        std::cout << "Clean clipboard hotkey 'ALT+a' registered, using MOD_NOREPEAT flag" << std::endl;
    }

    MSG msg = { 0 };
    while (GetMessage(&msg, nullptr, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {
            std::cout << "WM_HOTKEY received. id: " << msg.wParam << std::endl;
            Operations operation = static_cast<Operations>(msg.wParam);

            switch (operation) {
            case Operations::Copy:
                
                break;

            case Operations::Paste:

                break;
            case Operations::CleanClipboard:
                
                if (OpenClipboard(nullptr))
                {
                    EmptyClipboard();
                    CloseClipboard();
                }

                break;
            }
        }
    }
}