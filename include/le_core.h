/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.6                        */
/* include/le_core.h                     */
/* TODO: IMPROVE THIS                    */
/*****************************************/


#ifndef LE_CORE_H
#define LE_CORE_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>

typedef struct {
    int width, height;
    uint32_t *pixels;  // Main framebuffer
    BITMAPINFO bmi;    // Windows bitmap header info
    HWND hwnd;         // Window handle
    HDC hdc;           // Device context
    int closed;        // TODO: Replace with proper event state system later
} LE_C; // LE_Context

// Core lifecycle
LE_C *le_cr(int width, int height, const char *title, void *platform_window); //le_create
void le_d(LE_C *ctx); // le_delete/destroy
void le_cl(LE_C *ctx, uint32_t rgba); // le_clear
uint32_t le_mc(uint8_t r, uint8_t g, uint8_t b, uint8_t a); // le_make_color
void le_p(LE_C *ctx); // le_present
int le_pe(LE_C *ctx); // le_poll_events

#endif
