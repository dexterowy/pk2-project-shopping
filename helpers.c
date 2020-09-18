#include "string.h"

void trimLine(char *line) {
   size_t lenght = strlen(line) - 1;
   if(line[lenght] == '\n') line[lenght] = '\0';
}