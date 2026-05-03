#include "stddef.h"
#include "stdint.h"

size_t read_varint(uint8_t *buff);
void write_varint(uint8_t *buff, size_t value);
