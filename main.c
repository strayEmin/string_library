#include "string/string_library.h"
#include "assert.h"


char str1[] = ""; // len = 0
char str2[] = "nt"; // len = 2
char str3[10] = "\tHell\t"; // len = 6
char str4[30] = "i love type \"string\" in C"; // len = 25
char str5[] = " <-space"; // len = 8
char str6[] = " "; // len = 1
char str7[] = "i love type \"string\" in C"; // len = 25
char str8[] = "The Texas Chainsaw Massacre"; //  len = 27


void test_strlen_() {
    assert(strlen_(str1) == 0);
    assert(strlen_(str2) == 2);
    assert(strlen_(str3) == 6);
    assert(strlen_(str4) == 25);
}


void test_find() {
    assert(find(str1, str1, 'a') == str1);
    assert(find(str2, str2 + 2, 't') == str2 + 1);
    assert(find(str3, str3 + 5, 't') == str3 + 5);
    assert(find(str4, str4 + 10, 'l') == str4 + 2);
}


void test_findNonSpace() {
    assert(*findNonSpace(str1) == '\0' && findNonSpace(str1) == str1);
    assert(*findNonSpace(str2) == 'n' && findNonSpace(str2) == str2);
    assert(*findNonSpace(str3) == 'H' && findNonSpace(str3) == str3 + 1);
    assert(*findNonSpace(str4) == 'i' && findNonSpace(str4) == str4);
    assert(*findNonSpace(str5) == '<' && findNonSpace(str5) == str5 + 1);
    assert(*findNonSpace(str6) == '\0' && findNonSpace(str6) == str6 + 1);
}


void test_findSpace() {
    assert(findSpace(str1) == str1);
    assert(findSpace(str2) == str2 + 2);
    assert(findSpace(str3) == str3);
    assert(findSpace(str4) == str4 + 1);
}


void test_findNonSpaceReverse() {
    assert(findNonSpaceReverse(str1 - 1, str1 - 1) == str1 - 1);
    assert(findNonSpaceReverse(str2 + 1, str2 - 1) == str2 + 1);
    assert(findNonSpaceReverse(str3 + 5, str3 - 1) == str3 + 4);
    assert(findNonSpaceReverse(str4 + 24, str4 - 1) == str4 + 24);
    assert(findNonSpaceReverse(str6, str6 - 1) == str6 - 1);
}


void test_findSpaceReverse() {
    assert(findSpaceReverse(str1 - 1, str1 - 1) == str1 - 1);
    assert(findSpaceReverse(str2 + 1, str2 - 1) == str2 - 1);
    assert(findSpaceReverse(str3 + 5, str3 - 1) == str3 + 5);
    assert(findSpaceReverse(str4 + 24, str4 - 1) == str4 + 23);
    assert(findSpaceReverse(str5 + 7, str5 - 1) == str5);
    assert(findSpaceReverse(str6, str6 - 1) == str6);
}


void test_strcmp_() {
    assert(strcmp_(str4, str7) == 0);
    assert(strcmp_(str4, str2) < 0);
    assert(strcmp_(str2, str8) > 0);
    assert(strcmp_(str5, str2) < 0);
}


void test_copy() {
    char *str_copy;
    char *pc = copy(str4, str4 + 25, str_copy);
    assert(strcmp_(str4, str_copy) == 0);
    assert(pc == str_copy + 25);
}


void test_copyIf() {
    char *str_copy;
    char *pc = copyIf(str8, str8 + 27, str_copy, isupper);
    assert(memcmp(str_copy, "TTCM", 4) == 0);
}


void test_copyIfReverse() {
    char *str_copy;
    char *pc = copyIf(str8, str8 + 27, str_copy, isupper);
    assert(memcmp(str_copy, "MCTT", 4) == 0);
}


int main() {
    test_findNonSpace();

    return 0;
}