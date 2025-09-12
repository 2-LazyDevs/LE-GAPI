/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.4                        */
/* src/lg_texture.c                      */
/* TODO: IMPROVE THIS                    */
/*****************************************/

#include "../include/le_gapi.h"
#include <stdlib.h>
#include <string.h>

int lg_create_texture(LG_Context *ctx, int w, int h, const void *rgba_bytes){
    for(int i=0;i<ctx->tex_cap;i++){
        if(ctx->tex_pixels[i]==NULL){
            ctx->tex_pixels[i] = malloc(w*h*4);
            memcpy(ctx->tex_pixels[i], rgba_bytes, w*h*4);
            ctx->tex_w[i] = w; ctx->tex_h[i] = h;
            return i+1;
        }
    }
    return 0;
}

void lg_destroy_texture(LG_Context *ctx, uint32_t handle){
    int i = (int)handle - 1;
    if(i>=0 && i<ctx->tex_cap && ctx->tex_pixels[i]){
        free(ctx->tex_pixels[i]); ctx->tex_pixels[i]=NULL;
    }
}
