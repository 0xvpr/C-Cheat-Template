#ifndef _EVENTS_H
#define _EVENTS_H

#ifndef WIN32_LEAN_AND_MEAN
#   define WIN32_LEAN_AND_MEAN
#endif // WIN32_LEAN_AND_MEAN
#include <windows.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif // __cplusplus

bool events_handle_keyboard(void);

#endif /* _EVENTS_H */
