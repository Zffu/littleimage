#include "stddef.h"
#include "stdint.h"

size_t read_varsize(uint8_t *buff);
void write_varsize(uint8_t *buff, size_t value);
