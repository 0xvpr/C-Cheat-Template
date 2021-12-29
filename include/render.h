#ifndef _RENDER_H
#define _RENDER_H

#include "d3d9hook.h"

void render_initialize_renderer(LPDIRECT3DDEVICE9 pDevice);
void render_create_font(LPDIRECT3DDEVICE9 pDevice, int size);
void render_display_menu(LPDIRECT3DDEVICE9 d3dDevice);

typedef struct _HackMenu
{
    BOOL bEnabled:1;
    char name[63];
} HackMenu;

typedef struct _Resolution
{
    int x:16;
    int y:16;
} Resolution;

typedef struct _Coordinates
{
    int x:16;
    int y:16;
} Coordinates;

#endif /* _RENDER_H */
