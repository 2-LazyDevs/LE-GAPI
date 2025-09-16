/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.6                        */
/* include/le_quads.h                    */
/* TODO: IMPROVE THIS                    */
/*****************************************/


#ifndef LE_QUADS_H
#define LE_QUADS_H

#include <stdint.h>

#include "le_core.h"

typedef struct { 
    float x,y,w,h; 
    float u0,v0,u1,v1; 
    int tex; 
    uint32_t tint; 
} LE_Q;
// LE_Quad

void le_dq(LE_C *ctx, const LE_Q *quads, int count); // le_draw_quads, used for drawing quads

#endif