/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.5                        */
/* src/le_draw.c                         */
/* TODO: IMPROVE THIS                    */
/*****************************************/

#include "../include/le_draw.h"
#include "../include/le_font8x8.h"

// Internal helper: check bounds
static inline int in_bounds(LE_C *ctx, int x, int y) {
    return (x >= 0 && x < ctx->width && y >= 0 && y < ctx->height);
}

void le_dp(LE_C *ctx, int x, int y, uint32_t color) {
    if (!in_bounds(ctx, x, y)) return;
    ctx->pixels[y * ctx->width + x] = color;
}

void le_drl(LE_C *ctx, int x0, int y0, int x1, int y1, uint32_t color) {
    int dx = (x1 > x0) ? (x1 - x0) : (x0 - x1);
    int sx = (x0 < x1) ? 1 : -1;
    int dy = (y1 > y0) ? (y0 - y1) : (y1 - y0);
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx + dy;

    while (1) {
        le_drl(ctx, x0, y0, x1, y1, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void le_frect(LE_C *ctx, int x, int y, int w, int h, uint32_t color) {
    for (int j = 0; j < h; j++) {
        int py = y + j;
        if (py < 0 || py >= ctx->height) continue;
        for (int i = 0; i < w; i++) {
            int px = x + i;
            if (px < 0 || px >= ctx->width) continue;
            ctx->pixels[py * ctx->width + px] = color;
        }
    }
}

void le_drcircle(LE_C *ctx, int cx, int cy, int radius, uint32_t color) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        le_dp(ctx, cx + x, cy + y, color);
        le_dp(ctx, cx + y, cy + x, color);
        le_dp(ctx, cx - y, cy + x, color);
        le_dp(ctx, cx - x, cy + y, color);
        le_dp(ctx, cx - x, cy - y, color);
        le_dp(ctx, cx - y, cy - x, color);
        le_dp(ctx, cx + y, cy - x, color);
        le_dp(ctx, cx + x, cy - y, color);

        y += 1;
        if (err <= 0) {
            err += 2*y + 1;
        } 
        if (err > 0) {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void le_fcircle(LE_C *ctx, int cx, int cy, int radius, uint32_t color) {
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x*x + y*y <= radius*radius) {
                le_dp(ctx, cx + x, cy + y, color);
            }
        }
    }
}

// Draw a single 8x8 character
void le_drchar(LE_C *ctx, int x, int y, char c, uint32_t color) {
    if (c < 0 || c > 127) return; // Only basic ASCII for now, I'm thinking to expand this.
    /* TODO: EXPAND THIS, USE UNICODE INSTEAD OF BASIC ASCII*/
    for (int row = 0; row < 8; row++) {
        uint8_t bits = font8x8_basic[(int)c][row];
        for (int col = 0; col < 8; col++) {
            if (bits & (1 << col)) {
                le_dp(ctx, x + col, y + row, color);
            }
        }
    }
}

// Draw a text string
void le_wrtext(LE_C *ctx, int x, int y, const char *text, uint32_t color) {
    for (int i = 0; text[i] != '\0'; i++) {
        le_drchar(ctx, x + i * 8, y, text[i], color); // 8 pixels per char
    }
}
