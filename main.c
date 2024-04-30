#include "string/string_library.h"
#include "assert.h"
#include "string/tasks/tasks.h"


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
    char string[] = "Chainsaw";
    char new_string[4];
    copy(string, string + 3, new_string);

    char res[] = "Cha";
    assert(strcmp_(new_string, res) == 0);
}


void test_copyIf() {
    char str[] = "1a45";
    char str_copy[4];
    copyIf(str, str + 3, str_copy, isdigit);

    char res[] = "14";
    assert(memcmp(str_copy, res, 2) == 0);
}


void test_copyIfReverse() {
    char str[] = "1a45";
    char str_copy[3];
    copyIfReverse(str + 3, str, str_copy, isdigit);

    char res[] = "54";
    assert(memcmp(str_copy, res, 2) == 0);
}


void test_string() {
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}


void test_removeNonLetters() {
    char s[] = "a b  l";
    removeNonLetters(s);
    ASSERT_STRING(s, "abl");
}


void test_removeExtraSpaces() {
    char s[] = "The   Texas   Chainsaw   Massacre";
    removeExtraSpaces(s);
    ASSERT_STRING(s, "The Texas Chainsaw Massacre");
}


void test_lettersToStartDigitsToEnd() {
    char string1[] = "Th223e T322exas C232hainsaw Massacre";
    char string2[] = " sp1ce  sp4ce  sp0ce";
    char string3[] = "Ive missed all the deadlines";

    forEachWord(string1, lettersToStartDigitsToEnd);
    forEachWord(string2, lettersToStartDigitsToEnd);
    forEachWord(string3, lettersToStartDigitsToEnd);

    ASSERT_STRING("The223 Texas322 Chainsaw232 Massacre", string1);
    ASSERT_STRING(" spce1  spce4  spce0", string2);
    ASSERT_STRING("Ive missed all the deadlines", string3);
}


void test_tasks() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_lettersToStartDigitsToEnd();
}


int main() {
    test_tasks();
}


