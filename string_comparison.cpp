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

        if (EqualSymb(*(first_string + index1), *(second_string + index2)) == -1)
              return -1;

        else if (EqualSymb(*(first_string + index1), *(second_string + index2)) == 1)
              return 1;

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

        if (EqualSymb(*(first_string + index1), *(second_string + index2)) == -1)
              return -1;

        else if (EqualSymb(*(first_string + index1), *(second_string + index2)) == 1)
              return 1;

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

int EqualSymb(char string1, char string2) {

    char string1_copy = string1;
    char string2_copy = string2;
    if (tolower(string1_copy) == tolower(string2_copy))
        return 0;

    else if (tolower(string1_copy) > tolower(string2_copy))
        return 1;

    else
        return -1;

}
