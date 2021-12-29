#include "render.h"
#include "drawing.h"
#include "events.h"
#include <stdio.h>

extern bool bMaximizeMenu;
extern bool bCheatsEnabled;

extern LPD3DXFONT m_font;
extern LPD3DXFONT m_font_small;

Coordinates menuPosition = { 30, 25 };

void render_initialize_renderer(LPDIRECT3DDEVICE9 pDevice)
{
    (void)pDevice; // Delete when needed
    // Initialize Menu Items
}

void render_display_menu(LPDIRECT3DDEVICE9 d3dDevice)
{
    D3DDISPLAYMODE  d3dDisplayMode;
    char            buffer[32];

    // Get Resolution
    IDirect3DDevice9_GetDisplayMode(d3dDevice, 0, &d3dDisplayMode);

    // Draw Height
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "Height: %u", d3dDisplayMode.Height);
    drawing_draw_text(buffer, menuPosition.x, menuPosition.y - 25, 140, 20, colorLightGrey, m_font);

    // Draw Width
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "Width: %u", d3dDisplayMode.Width);
    drawing_draw_text(buffer, menuPosition.x + 140, menuPosition.y - 25, 140, 20, colorLightGrey, m_font);

    float factor = 1.0;
    if (bMaximizeMenu) {
        // Title Template
        drawing_draw_filled_rect(menuPosition.x, menuPosition.y, 140, 100, colorDarkGrey, d3dDevice);
        drawing_draw_border_box(menuPosition.x, menuPosition.y, 140, 100, 4, colorBlack, d3dDevice);

        // Draw status
        if (bCheatsEnabled)
        {
            drawing_draw_text("[ Enabled ]", menuPosition.x + 7, menuPosition.y + 10, 140, 20, colorGreen, m_font);
        }
        else
        {
            drawing_draw_text("[ Disabled ]", menuPosition.x + 7, menuPosition.y + 10, 140, 20, colorLightGrey, m_font);
        }

        drawing_draw_text("End to Eject", menuPosition.x + 12, menuPosition.y + 35, 140, 20, colorLightGrey, m_font);
    }
    else
    {
        factor = 0.25;

        // Title Template
        drawing_draw_filled_rect(30, 20, (int)(factor*140), (int)(factor*100), colorDarkGrey, d3dDevice);
        drawing_draw_border_box(30, 20, (int)(factor*140), (int)(factor*100), 2, colorBlack, d3dDevice);
    }

}

void render_create_font(LPDIRECT3DDEVICE9 pDevice, int size)
{ 
    // Draw font
    D3DXCreateFont(
        pDevice,            // LPDIRECT3DDEVICE9 pDevice
        size,               // Height
        0,                  // Width
        FW_BOLD,            // Weight
        0,                  // MIP Levels
        FALSE,              // Italic
        DEFAULT_CHARSET,    // Charset
        OUT_DEFAULT_PRECIS, // Precision
        DEFAULT_QUALITY,    // Quality
        DEFAULT_PITCH | FF_DONTCARE, // Pitch and Family
        "Arial",            // Font name
        &m_font             // LPD3DXFONT
    );
            
}
