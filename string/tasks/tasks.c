#include "tasks.h"
#include "../string_library.h"


char* getEndOfString(char *s) {
    return s + strlen_(s);
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}
