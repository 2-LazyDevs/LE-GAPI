/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.5                        */
/* src/le_context.c                      */
/* TODO: IMPROVE THIS                    */
/*****************************************/

#include "../include/le_gapi.h"

#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Forward declaration of platform-specific window proc
extern LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

LE_C *le_cr(int width, int height, const char *title, void *platform_window){
    HINSTANCE hInst = GetModuleHandle(NULL);
    WNDCLASSA wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = "LE_GAPI_WinClass";
    RegisterClassA(&wc);

    HWND hwnd = CreateWindowA(wc.lpszClassName, title ? title : "LE-GAPI",
        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, width+16, height+39,
        NULL, NULL, hInst, NULL);

    if(!hwnd) return NULL;

    LE_C *ctx = (LE_C*)malloc(sizeof(LE_C));
    memset(ctx,0,sizeof(*ctx));
    ctx->width = width; ctx->height = height;
    ctx->pixels = (uint32_t*)malloc(width*height*sizeof(uint32_t));
    ctx->hwnd = hwnd;
    ctx->hdc = GetDC(hwnd);
    ctx->closed = 0;

    // Setup BITMAPINFO (BGRA)

    ctx->bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    ctx->bmi.bmiHeader.biWidth = width;
    ctx->bmi.bmiHeader.biHeight = -height; // Top down
    ctx->bmi.bmiHeader.biPlanes = 1;
    ctx->bmi.bmiHeader.biBitCount = 32;
    ctx->bmi.bmiHeader.biCompression = BI_RGB;

    // We'll just use simple text arrays here for now

    ctx->tex_cap = 64;
    ctx->tex_pixels = (void**)calloc(ctx->tex_cap, sizeof(void*));
    ctx->tex_w = (int*)calloc(ctx->tex_cap, sizeof(int));
    ctx->tex_h = (int*)calloc(ctx->tex_cap, sizeof(int));

    SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ctx);
    return ctx;
}

void le_d(LE_C *ctx){
    if(!ctx) return;
    ReleaseDC(ctx->hwnd, ctx->hdc);
    DestroyWindow(ctx->hwnd);
    free(ctx->pixels);
    for(int i=0;i<ctx->tex_cap;i++) if(ctx->tex_pixels[i]) free(ctx->tex_pixels[i]);
    free(ctx->tex_pixels); free(ctx->tex_w); free(ctx->tex_h);
    free(ctx);
}

int le_pe(LE_C *ctx){
    MSG msg;
    while(PeekMessage(&msg, NULL, 0,0, PM_REMOVE)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return ctx->closed ? 0 : 1;
}

void le_p(LE_C *ctx){
    StretchDIBits(ctx->hdc, 0,0,ctx->width,ctx->height,
                  0,0,ctx->width,ctx->height,
                  ctx->pixels, &ctx->bmi, DIB_RGB_COLORS, SRCCOPY);
}
