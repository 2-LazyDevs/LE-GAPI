/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.6                        */
/* src/le_texture.c                      */
/* TODO: IMPROVE THIS                    */
/*****************************************/

#include "../include/le_texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../include/thirdparty/stb_image.h"

#include <stdlib.h>
#include <string.h>

// Low-level API (manual RGBA)

int le_crtext(LE_C *ctx, int w, int h, const void *rgba_bytes){
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

void le_desttext(LE_C *ctx, uint32_t handle) {
    int i = (int)handle - 1;
    if (i >= 0 && i < ctx->tex_cap && ctx->tex_pixels[i]) {
        free(ctx->tex_pixels[i]);
        ctx->tex_pixels[i] = NULL;
        ctx->tex_w[i] = 0;
        ctx->tex_h[i] = 0;
    }
}

// High-level API (loaded via stb_image)

int le_loadtext(LE_C *ctx, const char *filename) {
    int w, h, channels;
    unsigned char *data = stbi_load(filename, &w, &h, &channels, 4);
    if (!data) {
        /* TODO: ADD A MESSSAGE BOX */
        return -1;
    }
    
    int texthand = le_crtext(ctx, w, h, data); // Texture handler
    stbi_image_free(data);
    return texthand;
}

void le_freetext(LE_C *ctx, uint32_t texthand) {
    le_desttext(ctx, texthand)
}