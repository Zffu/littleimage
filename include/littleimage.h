/**
 * @file littleimage.h
 * @author Zffu
 * @brief littleimage is an image format that tries to compress down the image
 * size.
 * @version 0.1
 */

#include "stddef.h"
#include "stdint.h"
#include <cstdint>

typedef struct littleimage_header {
  size_t width;
  size_t height;
} littleimage_header;
