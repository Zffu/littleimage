#include "../include/internals.h"

#define SEGMENT_BITS 0x7F
#define CONTINUE_BIT 0x80

size_t read_varsize(uint8_t *buff) {
  size_t value = 0;
  int position = 0;
  uint8_t current_byte;
  size_t ind = 0;

  while (1) {
    current_byte = buff[ind++];
    value |= (current_byte & SEGMENT_BITS);

    if ((current_byte & CONTINUE_BIT) == 0)
      break;

    position += 7;

    if (position >= sizeof(size_t))
      return value;
  }

  return value;
}

void write_varsize(uint8_t *buff, size_t value) {
  size_t ind = 0;

  while (1) {
    if ((value & ~SEGMENT_BITS) == 0) {
      buff[ind] = value;
      return;
    }

    buff[ind++] = ((value & SEGMENT_BITS) | CONTINUE_BIT);

    value >>= 7;
  }
}