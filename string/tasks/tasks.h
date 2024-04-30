#ifndef PROJECT_TASKS_H
#define PROJECT_TASKS_H

#define MAX_STRING_SIZE
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>


typedef struct word_descriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} word_descriptor_t;


typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;


typedef enum WordPrecedingFirstCommonWordReturnCode {
    WORD_PRECEDING_EMPTY_STRING,
    WORD_PRECEDING_FIRST_WORDS_IS_COMMON,
    WORD_PRECEDING_WORD_FOUND,
    WORD_PRECEDING_NOT_FOUND_COMMON_WORD
} WordPrecedingFirstCommonWordReturnCode;


typedef struct BagOfWords {
    word_descriptor_t words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;


void removeNonLetters(char *s);


void removeExtraSpaces(char *s);


int getWord(char *begin_search, word_descriptor_t *word);


int getWordReverse(char* search_end, char* search_start, word_descriptor_t* word);


void forEachWord(char* string, void (*function)(word_descriptor_t));


void lettersToStartDigitsToEnd(word_descriptor_t word);


#endif //PROJECT_TASKS_H
