/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.4                        */
/* include/lg_draw.h                     */
/* TODO: IMPROVE THIS                    */
/*****************************************/

#ifndef LG_DRAW_H
#define LG_DRAW_H

#include "le_gapi.h"

#include <stdint.h>

// Draw a single pixel
void lg_draw_pixel(LG_Context *ctx, int x, int y, uint32_t color);

// Draw a line (Bresenham algorithm)
void lg_draw_line(LG_Context *ctx, int x0, int y0, int x1, int y1, uint32_t color);

// Fill a solid rectangle
void lg_fill_rect(LG_Context *ctx, int x, int y, int w, int h, uint32_t color);

// Draw/write text to the user's screen
void lg_draw_text(LG_Context *ctx, int x, int y, const char *text, uint32_t color);

#endif // LG_DRAW_H
