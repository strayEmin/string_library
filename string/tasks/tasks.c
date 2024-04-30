#include "tasks.h"
#include "../string_library.h"

static char _string_buffer[MAX_STRING_SIZE + 1];

// task1
char* getEndOfString(char *s) {
    return s + strlen_(s);
}


void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

// task2
void removeExtraSpaces(char* source) {
    char* write_pointer = source;
    while (*source != '\0') {
        if (!isspace(*source) || (isspace(*source) && !isspace(*(source - 1)))) {
            *write_pointer = *source;
            write_pointer++;
        }
        source++;
    }

    *write_pointer = '\0';
}

// task3
int getWord(char *begin_search, word_descriptor_t* word) {
    word->begin = findNonSpace(begin_search);

    if (*word->begin == '\0') {
        return 0;
    }

    word->end = findSpace(word->begin);

    return 1;
}

void forEachWord(char* string, void (*function)(word_descriptor_t)) {
    char* search_point = string;
    word_descriptor_t word;

    while (getWord(search_point, &word)) {
        function(word);

        search_point = word.end;
    }
}


void lettersToStartDigitsToEnd(word_descriptor_t word) {
    char* string_buffer_end = copy(word.begin, word.end, _string_buffer);
    char* digits_end = copyIf(_string_buffer, string_buffer_end, word.begin, isalpha);

    copyIf(_string_buffer, string_buffer_end, digits_end, isdigit);
}



