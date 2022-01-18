#pragma once

#ifndef IsLinux
    #ifdef __linux__
        #define IsLinux() true
    #else
        #define IsLinux() false
    #endif
#endif

#ifndef IsApple
    #ifdef __APPLE__
        #define IsApple() true
    #else
        #define IsApple() false
    #endif
#endif

#ifdef _WIN32
    #ifndef _INC_WINDOWS
        #include <windows.h>
    #endif
#endif

#if !defined(__cplusplus) && !defined(__bool_true_false_are_defined)
    #if __STDC_VERSION__ == 201112L
        #include <stdbool.h>
    #else
        typedef unsigned char bool;
        #define true ((bool)1)
        #define false ((bool)0)
        #define __bool_true_false_are_defined
    #endif
#endif

#ifndef IsWindows9xOrMe
    #ifdef _WIN32
        #define IsWindows9xOrMe() (GetVersion() >= 0x80000000)
    #else
        #define IsWindows9xOrMe() false
    #endif
#endif

#ifndef IsWindowsNT
    #ifdef _WIN32
        #define IsWindowsNT() (GetVersion() < 0x80000000)
    #else
        #define IsWindowsNT() false
    #endif
#endif

#ifndef IsWindowsNT4OrLater
    #ifdef _WIN32
        static __inline bool IsWindowsNT4OrLater(void)
        {
            OSVERSIONINFOA osver = { sizeof(osver) };
            return (GetVersionExA(&osver) && osver.dwMajorVersion >= 4);
        }
        #define IsWindowsNT4OrLater IsWindowsNT4OrLater
    #else
        #define IsWindowsNT4OrLater() false
    #endif
#endif

#ifndef IsWindows2000OrLater
    #ifdef _WIN32
        static __inline bool IsWindows2000OrLater(void)
        {
            OSVERSIONINFOA osver = { sizeof(osver) };
            return (GetVersionExA(&osver) && osver.dwMajorVersion >= 5);
        }
        #define IsWindows2000OrLater IsWindows2000OrLater
    #else
        #define IsWindows2000OrLater() false
    #endif
#endif /* ndef IsWindows2000OrLater */

#ifndef IsWindowsXPOrLater
    #ifdef _WIN32
        static __inline bool IsWindowsXPOrLater(void)
        {
            OSVERSIONINFOA osver = { sizeof(osver) };
            if (!GetVersionExA(&osver) || osver.dwMajorVersion < 5)
                return false;
            return (osver.dwMajorVersion > 5 || osver.dwMinorVersion > 1);
        }
        #define IsWindowsXPOrLater IsWindowsXPOrLater
    #else
        #define IsWindowsXPOrLater() false
    #endif
#endif

#ifndef IsWindowsVistaOrLater
    #ifdef _WIN32
        static __inline bool IsWindowsVistaOrLater(void)
        {
            OSVERSIONINFOA osver = { sizeof(osver) };
            return (GetVersionExA(&osver) && osver.dwMajorVersion >= 6);
        }
        #define IsWindowsVistaOrLater IsWindowsVistaOrLater
    #else
        #define IsWindowsVistaOrLater() false
    #endif
#endif

#ifndef IsReactOS
    #ifdef _WIN32
        #include <string.h>
        static __inline bool IsReactOS(void)
        {
            char szWinDir[MAX_PATH];
            GetWindowsDirectoryA(szWinDir, sizeof(szWinDir));
            return (strstr(szWinDir, "ReactOS") != NULL);
        }
        #define IsReactOS IsReactOS
    #else
        #define IsReactOS() false
    #endif
#endif
