#include "events.h"
#include "hacks.h"

bool bCheatsEnabled;

bool events_handle_keyboard(void)
{
    // Toggle cheats
    if (GetAsyncKeyState(VK_TAB) & 1)
    {
        bCheatsEnabled = !bCheatsEnabled;
    }
    
    // Cleanup
    if (GetAsyncKeyState(VK_END))
    {
        return TRUE;
    }

    return FALSE;
}
