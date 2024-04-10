#ifndef STR_STRING_LIBRARY_H
#define STR_STRING_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>


size_t strlen_(const char *begin);


char* find(char *begin, char *end, int ch);


char* findNonSpace(char *begin);


char* findSpace(char *begin);


char* findNonSpaceReverse(char *rbegin, const char *rend);


char* findSpaceReverse(char *rbegin, const char *rend);


int strcmp_(const char *lhs, const char *rhs);


char* copy(const char *beginSource, const char *endSource,
           char *beginDestination);


char* copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));


char* copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));


#endif //STR_STRING_LIBRARY_H
