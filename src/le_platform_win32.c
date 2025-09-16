/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.6                        */
/* src/le_platform_win32.c               */
/* TODO: IMPROVE THIS                    */
/*****************************************/

#include "../include/le_core.h"
#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    LE_C *ctx = (LE_C*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    switch(msg){
        case WM_CLOSE: if(ctx) ctx->closed = 1; PostQuitMessage(0); return 0;
        case WM_DESTROY: if(ctx) ctx->closed = 1; return 0;
        case WM_PAINT: {
            if(ctx){
                PAINTSTRUCT ps;
                HDC dc = BeginPaint(hwnd, &ps);
                StretchDIBits(dc, 0,0,ctx->width,ctx->height,
                              0,0,ctx->width,ctx->height,
                              ctx->pixels, &ctx->bmi, DIB_RGB_COLORS, SRCCOPY);
                EndPaint(hwnd, &ps);
            }
            return 0;
        }
    }
    return DefWindowProc(hwnd,msg,wParam,lParam);
}
