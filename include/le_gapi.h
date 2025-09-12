/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.4                        */
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
    int closed;       // Did the user close the window?

    // Texture system
    void **tex_pixels;
    int *tex_w, *tex_h;
    int tex_cap;
} LG_Context;

// API functions
LG_Context *lg_create(int width, int height, const char *title, void *platform_window);
void lg_destroy(LG_Context *ctx);
void lg_clear(LG_Context *ctx, uint32_t rgba);
uint32_t lg_make_color(uint8_t r,uint8_t g,uint8_t b,uint8_t a);
void lg_present(LG_Context *ctx);
int lg_poll_events(LG_Context *ctx);

int lg_create_texture_internal(LG_Context *ctx, int w, int h, const void *rgba_bytes);
void lg_destroy_texture(LG_Context *ctx, uint32_t handle);

typedef struct { 
    float x,y,w,h; 
    float u0,v0,u1,v1; 
    int tex; 
    uint32_t tint; 
} LG_Quad;
void lg_draw_quads(LG_Context *ctx, const LG_Quad *quads, int count);

#endif