/*****************************************/
/* LICENSED UNDER THE 2LD OSL            */
/* LE-GAPI - v0.6                        */
/* include/le_texture.h                  */
/* TODO: IMPROVE THIS                    */
/*****************************************/

#ifndef LE_TEXTURE_H
#define LE_TEXTURE_H

#include <stdint.h>

// LE-GAPI HEADER
// Importing le_core.h as it has the core functionality

#include "le_core.h"

int le_crtext(LE_C *ctx, int w, int h, const void *rgba_bytes);
void le_desttext(LE_C *ctx, uint32_t handle);

#endif
