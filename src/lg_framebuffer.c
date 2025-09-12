/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.4                        */
/* src/lg_framebuffer.c                  */
/* TODO: IMPROVE THIS                    */
/*****************************************/

#include "../include/le_gapi.h"
#include <stdint.h>

static inline uint32_t rgb_to_bgra(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
    return ((uint32_t)a<<24) | ((uint32_t)r<<16) | ((uint32_t)g<<8) | b;
}

uint32_t lg_make_color(uint8_t r,uint8_t g,uint8_t b,uint8_t a){ return rgb_to_bgra(r,g,b,a); }

void lg_clear(LG_Context *ctx, uint32_t rgba){
    int n = ctx->width * ctx->height;
    for(int i=0;i<n;i++) ctx->pixels[i] = rgba;
}
