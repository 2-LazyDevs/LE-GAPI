/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.4                        */
/* tests/main_win.c                      */
/* TODO: IMPROVE THIS                    */
/*****************************************/

// LE-GAPI headers
#include "../include/le_gapi.h"
#include "../include/lg_draw.h"

// Trim unused parts of windows.h so the program compiles faster
#define WIN32_LEAN_AND_MEAN

// System header
#include <windows.h>
#include <stdint.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nShowCmd) {
    // Create LE-GAPI context, the 4th argument is NULL for platform_window
    LG_Context* ctx = lg_create(640, 480, "LE-GAPI 2D Test", NULL);
    if (!ctx) return -1;

    // Main GUI loop
    while (lg_poll_events(ctx)) {
        lg_clear(ctx, lg_make_color(0,0,0,255)); // black background

        // Draw some 2D primitives
        // Including lines, rectangles & circles
        lg_draw_line(ctx, 50, 50, 300, 200, lg_make_color(255,255,255,255));   // white line
        lg_fill_rect(ctx, 400, 100, 120, 80, lg_make_color(255,0,0,255));      // red rectangle (moved right)
        lg_draw_pixel(ctx, 320, 240, lg_make_color(0,255,0,255));              // green pixel in center
        lg_draw_circle(ctx, 150, 350, 50, lg_make_color(255,255,0,255));       // Yellow unfilled circle (moved down)
        lg_fill_circle(ctx, 500, 300, 75, lg_make_color(0,0,255,255));         // Blue filled circle (moved right)

        lg_draw_text(ctx, 50, 20, "Hello, LE-GAPI!", lg_make_color(255, 255, 255, 255));
       lg_draw_text(ctx, 50, 40, "This is bitmap font rendering in LE-GAPI", lg_make_color(0, 200, 255, 255));

        lg_present(ctx);
        Sleep(16); // ~60fps
    }

    lg_destroy(ctx);
    return 0;
}


