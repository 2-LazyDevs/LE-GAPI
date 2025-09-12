/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.4                        */
/* src/lg_quad.c                         */
/* TODO: IMPROVE THIS                    */
/*****************************************/

#include "../include/le_gapi.h"
#include <stdint.h>

void lg_draw_quads(LG_Context *ctx, const LG_Quad *quads, int count){
    for(int q=0;q<count;q++){
        const LG_Quad *qv = &quads[q];
        if(qv->tex<=0) continue;
        int ti = qv->tex - 1;
        uint8_t *tex = (uint8_t*)ctx->tex_pixels[ti];
        int tw = ctx->tex_w[ti], th = ctx->tex_h[ti];
        if(!tex) continue;

        int x0 = (int)qv->x, y0 = (int)qv->y;
        int x1 = x0 + (int)qv->w;
        int y1 = y0 + (int)qv->h;

        for(int y=y0;y<y1;y++){
            if(y<0||y>=ctx->height) continue;
            for(int x=x0;x<x1;x++){
                if(x<0||x>=ctx->width) continue;
                float fx = (x - (float)x0) / (float)(x1-x0);
                float fy = (y - (float)y0) / (float)(y1-y0);
                int sx = (int)( (qv->u0*(1-fx) + qv->u1*fx) * tw );
                int sy = (int)( (qv->v0*(1-fy) + qv->v1*fy) * th );
                if(sx<0) sx=0; if(sx>=tw) sx=tw-1;
                if(sy<0) sy=0; if(sy>=th) sy=th-1;
                uint8_t *p = &tex[(sy*tw + sx)*4]; // RGBA
                uint32_t col = ((uint32_t)p[3]<<24) | ((uint32_t)p[0]<<16) | ((uint32_t)p[1]<<8) | p[2];
                ctx->pixels[y*ctx->width + x] = col;
            }
        }
    }
}
