#include <stdio.h>
#include <cassert>
#include <string.h>
#include "string_comparison.h"
#include <ctype.h>

int Strcmp(const char* first_string, const char* second_string) {

    assert(first_string != NULL);
    assert(second_string != NULL);

    int index1 = 0, index2 = 0;

    while (!CorrectSymb(first_string, index1))
        index1++;

    while (!CorrectSymb(second_string, index2))
        index2++;

    while ((*(first_string + index1) != '\n') && (*(second_string + index2) != '\n')) {

        if (!(EqualSymb(first_string, second_string, index1, index2))) {

                if (tolower(*(first_string + index1)) > tolower(*(second_string + index2)))
                    return 1;

                if (tolower(*(first_string + index1)) < tolower(*(second_string + index2)))
                    return -1;

        }

        index1++;
        index2++;

    }

    if (*(first_string + index1) == '\n' && *(second_string + index2) == '\n')
        return 0;

    else if (*(first_string + index1) == '\n' && *(second_string + index2) != '\n')
        return -1;

    else
        return 1;

}

int BackStrcmp(const char* first_string, const char* second_string,
               int len_str1, int len_str2) {

    assert(first_string != NULL);
    assert(second_string != NULL);

    int index1 = len_str1 - 1;
    int index2 = len_str2 - 1;

    while (!CorrectSymb(first_string, index1))
        index1--;

    while (!CorrectSymb(second_string, index2))
        index2--;

    while ((index1 != -1) && (index2 != -1)) {

        if (!(EqualSymb(first_string, second_string, index1, index2))) {

                if (tolower(*(first_string + index1)) > tolower(*(second_string + index2)))
                    return 1;

                if (tolower(*(first_string + index1)) < tolower(*(second_string + index2)))
                    return -1;

        }

        index1--;
        index2--;
    }

    if ((index1 == -1) && (index2 == -1))
        return 0;

    else if ((index1 != -1) && (index2 == -1))
        return 1;

    else
        return -1;

}




bool CorrectSymb(const char* str, int index) {

    assert(str != NULL);

    if (isalpha(*(str + index)) == 0)
        return false;

    return true;
}

bool EqualSymb(const char* string1, const char* string2,
               int index_first, int index_second) {

    assert(string1 != NULL);
    assert(string2 != NULL);

    const char* string1_copy = string1;
    const char* string2_copy = string2;

    assert(string1_copy != NULL);
    assert(string2_copy != NULL);

    if (tolower(*(string1_copy + index_first)) == tolower(*(string2_copy + index_second)))
        return true;

    else
        return false;

}
