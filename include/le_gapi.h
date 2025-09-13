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
} LE_C; // Instead of larger words, we use smaller words such as LE_C to make it easy
// LE_C stands for LE_Context

// API functions
LE_C *le_cr(int width, int height, const char *title, void *platform_window); // le_cr stands for le_create
void le_d(LE_Context *ctx); // le_d stands for
void le_clear(LE_Context *ctx, uint32_t rgba);
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