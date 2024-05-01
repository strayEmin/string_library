#include "tasks.h"
#include "../string_library.h"


char _string_buffer[MAX_STRING_SIZE + 1];
bag_of_words_t bag1;
bag_of_words_t bag2;


static void clearStringBuff() {
    char *write_ptr = _string_buffer;
    while (write_ptr != _string_buffer + MAX_STRING_SIZE + 1 && *write_ptr != '\0')
        *(write_ptr++) = '\0';
}

// task1
char* getEndOfString(char *s) {
    return s + strlen_(s);
}


void removeNonLetters(char *s) {
    char *end_source = getEndOfString(s);
    char *destination = copyIf(s, end_source, s, isgraph);
    *destination = '\0';
}

// task2
void removeExtraSpaces(char *source) {
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


void forEachWord(char *string, void (*function)(word_descriptor_t)) {
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
    clearStringBuff();
}

// task4
void replaceDigitsWithSpaces(char *string) {
    char *buffer_begin = _string_buffer;
    char *buffer_end = copy(string, getEndOfString(string), buffer_begin);
    while (buffer_begin < buffer_end) {
        if (isdigit(*buffer_begin)) {
            unsigned char a = *buffer_begin - '0';
            while (a--)
                *string++ = ' ';
        } else
            *string++ = *buffer_begin;

        buffer_begin++;
    }

    *string = '\0';
}

// task5
int wordscmp(word_descriptor_t word1, word_descriptor_t word2) {
    char w1[word1.end - word1.begin + 1];
    char w2[word2.end - word2.begin + 1];
    *copy(word1.begin, word1.end, w1) = '\0';
    *copy(word2.begin, word2.end, w2) = '\0';

    return strcmp_(w1, w2);
}


void replace(char *string, char *replaceable, char *replacement) {
    size_t replaceable_length = strlen_(replaceable);
    size_t replacement_length = strlen_(replacement);
    word_descriptor_t replaceable_word = {replaceable, replaceable + replaceable_length};
    word_descriptor_t replacement_word = {replacement, replacement + replacement_length};

    char *read_ptr, *write_ptr;
    if (replaceable_length > replacement_length) {
        read_ptr = string;
    } else {
        *copy(string, string + strlen_(string), _string_buffer) = '\0';
        read_ptr = _string_buffer;
    }

    write_ptr = string;
    word_descriptor_t cur_word;

    while (getWord(read_ptr, &cur_word)) {
        write_ptr = copy(read_ptr, cur_word.begin, write_ptr);

        if (wordscmp(cur_word, replaceable_word) == 0) {
            write_ptr = copy(replacement_word.begin, replacement_word.end, write_ptr);
        } else {
            write_ptr = copy(cur_word.begin, cur_word.end, write_ptr);
        }

        read_ptr = cur_word.end;
    }

    *write_ptr = '\0';
}

//task6
bool areWordsSorted(char *string) {
    word_descriptor_t previous_word;

    if (getWord(string, &previous_word)) {
        word_descriptor_t current_word;

        while (getWord(previous_word.end, &current_word)) {
            if (wordscmp(previous_word, current_word) > 0) {
                return false;
            }

            previous_word = current_word;
        }
    }

    return true;
}

// task7
void getBagOfWords(char *begin_search, bag_of_words_t *bag) {
    size_t word_index = 0;

    while (getWord(begin_search, bag->words + word_index)) {
        begin_search = bag->words[word_index].end;
        word_index++;
    }

    bag->size = word_index;
}


void printWord(word_descriptor_t word) {
    while (word.begin != word.end) {
        putchar(*word.begin);
        word.begin++;
    }
}


void printWordsInReverseOrder(char* string) {
    getBagOfWords(string, &bag1);

    for (size_t i = bag1.size - 1; i != -1; i--) {
        printWord(bag1.words[i]);
        putchar('\n');
    }
    bag1.size = 0;
}

// task8
static bool _isPalindrome(char *begin, char *end) {
    end--;

    if (*end == ',')
        end--;

    while (end > begin) {
        if (*begin != *end)
            return false;

        begin++;
        end--;
    }

    return true;
}


int countPalindromes(char* string) {
    int count = 0;
    char* search_ptr = string;
    word_descriptor_t word;

    while (getWord(search_ptr, &word)) {
        if (_isPalindrome(word.begin, word.end)) {
            count++;
        }

        search_ptr = word.end;
    }

    return count;
}

//task9
void shuffleWords(char* s1, char* s2, char* destination) {
    word_descriptor_t word1, word2;
    bool is_word_1_found, is_word_2_found;
    char* begin_search_1 = s1;
    char* begin_search_2 = s2;
    char* dst = destination;

    while ((is_word_1_found = getWord(begin_search_1, &word1)),
            (is_word_2_found = getWord(begin_search_2, &word2)),
            is_word_1_found || is_word_2_found) {
        if (is_word_1_found) {
            dst = copy(word1.begin, word1.end, dst);
            *dst++ = ' ';
            begin_search_1 = word1.end;
        }

        if (is_word_2_found) {
            dst = copy(word2.begin, word2.end, dst);
            *dst++ = ' ';
            begin_search_2 = word2.end;
        }
    }

    *(dst - (dst != destination)) = '\0';
}

//task10
void reverseWordsOrder(char* string) {
    getBagOfWords(string, &bag1);
    char *result = _string_buffer;

    for (size_t i = bag1.size; i > 0; i--) {
        char *s = bag1.words[i - 1].begin;
        while (s != bag1.words[i - 1].end)
            *(result++) = *s++;

        if (i != 1)
            *(result++) = ' ';
    }

    *copy(_string_buffer, result, string) = '\0';
}
