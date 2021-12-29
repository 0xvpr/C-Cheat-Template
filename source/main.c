/**
 * Creator:   VPR
 * Created:   December 24th, 2021
 * Updated:   December 29th, 2021
 * 
 * Description:
 *     Template for Video Game hacking using pure C
**/

#include "d3d9hook.h"
#include "render.h"
#include "events.h"
#include "mem.h"

uintptr_t module_base_addr = 0;
HWND dll_handle = NULL;

LPVOID d3d9Device[119];
tEndScene oEndScene = NULL;
BYTE oEndScene_bytes[7] = { 0 };

BOOL bMaximizeMenu = TRUE;
BOOL bShutdown = FALSE;
BOOL bInit = FALSE;

HRESULT APIENTRY hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{ 
    if (!bInit)
    {
        bInit = TRUE;

        render_initialize_renderer(pDevice);
        render_create_font(pDevice, 20);
    }
    render_display_menu(pDevice);

    return oEndScene(pDevice);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{ 
    module_base_addr = (uintptr_t)GetModuleHandle(NULL);
    
    if (GetD3D9Device(d3d9Device, sizeof(d3d9Device)))
    {
        memcpy(oEndScene_bytes, d3d9Device[42], 7);
        oEndScene = (tEndScene)memory_tramp_hook((char *)d3d9Device[42], (char *)hkEndScene, 7);
    }

    while (!(bShutdown = events_handle_keyboard()))
    {
        // Main Loop
    }

    memory_patch(d3d9Device[42], oEndScene_bytes, 7);
    FreeLibraryAndExitThread((HMODULE)lpReserved, 0);

    return TRUE;
}

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {

    (void)lpReserved;
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            dll_handle = (HWND)hInstance;
            DisableThreadLibraryCalls(hInstance);
            CreateThread(0, 0, MainThread, hInstance, 0, 0);
            break;
        }
        case DLL_PROCESS_DETACH:
        { 
            break;
        }
        default:
        {
            break;
        }
    }

    return TRUE;
}
