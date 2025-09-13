/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.5                        */
/* include/le_draw.h                     */
/* TODO: IMPROVE THIS                    */
/*****************************************/

#ifndef LE_DRAW_H
#define LE_DRAW_H

#include "le_gapi.h"

#include <stdint.h>

void le_dp(LE_C *ctx, int x, int y, uint32_t color); // le_draw_pixel, draws a single pixel on to the screen

void le_drl(LE_C *ctx, int x0, int y0, int x1, int y1, uint32_t color); // le_draw_line, used to draw a line via the Bresenham algorithm

void le_frect(LE_C *ctx, int x, int y, int w, int h, uint32_t color); // le_fill_rect, fills a rectangle

void le_wrtext(LE_C *ctx, int x, int y, const char *text, uint32_t color); // le_write_text, used to write text to the user's screen

// Actuall logic is in src/le_draw.c
// These are just declerations
// I'm literally writting this while making my horror game!

#endif // LE_DRAW_H
