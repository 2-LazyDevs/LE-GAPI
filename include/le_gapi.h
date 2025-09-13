/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.5                        */
/* include/le_gapi.h                     */
/* TODO: IMPROVE THIS                    */
/*****************************************/

#ifndef LE_GAPI_H
#define LE_GAPI_H

// Trim unused parts of windows.h so the program compiles faster
#define WIN32_LEAN_AND_MEAN

// System headers, required by LE-GAPI
#include <windows.h>
#include <stdint.h>

typedef struct {
    int width, height;
    uint32_t *pixels; // Main framebuffer
    BITMAPINFO bmi;   // Windows bitmap header info
    HWND hwnd;        // Window handle
    HDC hdc;          // Device context
    
    /* TODO: Replace `int closed;` with something better */
    int closed;       // Did the user close the window? For this, I use an int but I think this needs to be changed & has the potential to be replaced with something far better
   

    // Texture system
    void **tex_pixels;
    int *tex_w, *tex_h;
    int tex_cap;
} LE_C; // Instead of larger words, we use smaller words such as LE_C to make it easy for programmers
// LE_Context

// API functions
LE_C *le_cr(int width, int height, const char *title, void *platform_window); // le_create
void le_d(LE_C *ctx); // le_delete
void le_cl(LE_C *ctx, uint32_t rgba); // le_clear
uint32_t le_mc(uint8_t r,uint8_t g,uint8_t b,uint8_t a); // le_make_color
void le_p(LE_C *ctx); // le_present
int le_pe(LE_C *ctx); // le_poll_events

int le_crtext(LE_C *ctx, int w, int h, const void *rgba_bytes); // le_create_texture, used for making textures
void le_desttext(LE_C *ctx, uint32_t handle); // le_destroy_texture, used for destroying textures

typedef struct { 
    float x,y,w,h; 
    float u0,v0,u1,v1; 
    int tex; 
    uint32_t tint; 
} LE_Q;
// LE_Quad

void le_dq(LE_C *ctx, const LE_Q *quads, int count);

#endif