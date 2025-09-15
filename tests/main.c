/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.5                        */
/* tests/main.c                          */
/* TODO: IMPROVE THIS                    */
/*****************************************/

// LE-GAPI headers
#include "../include/le_gapi.h"
#include "../include/le_draw.h"

// Trim unused parts of windows.h so the program compiles faster
#define WIN32_LEAN_AND_MEAN

// System header
#include <windows.h>
#include <stdint.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nShowCmd) {
    // Create LE-GAPI context
    /* INFO: 4th argument is NULL for platform_window */
    LE_C* ctx = le_cr(640, 480, "LE-GAPI 2D Test", NULL);
    if (!ctx) return -1;

    // Main GUI loop
    while (le_pe(ctx)) {
        le_cl(ctx, le_mc(0,0,0,255)); // black background

        // Draw some 2D primitives
        // Including lines, rectangles & circles
        le_drl(ctx, 50, 50, 300, 200, le_mc(255,255,255,255));                 // white line
        le_frect(ctx, 400, 100, 120, 80, le_mc(255,0,0,255));                  // red rectangle (moved right)
        le_dp(ctx, 320, 240, le_mc(0,255,0,255));                              // green pixel in center
        le_drcircle(ctx, 150, 350, 50, le_mc(255,255,0,255));                  // Yellow unfilled circle (moved down)
        lg_fcircle(ctx, 500, 300, 75, lg_make_color(0,0,255,255));         // Blue filled circle (moved right)

        le_wrtext(ctx, 50, 20, "Hello, LE-GAPI!", le_mc(255, 255, 255, 255));
        le_wrtext(ctx, 50, 40, "This is bitmap font rendering in LE-GAPI", le_mc(0, 200, 255, 255));
        le_wrtext(ctx, 50, 60, "I (AR) also want to add 24 pixel version as well", le_mc(250, 200, 255, 255));

        le_p(ctx);
        Sleep(16); // ~60fps
    }

    le_d(ctx);
    return 0;
}


