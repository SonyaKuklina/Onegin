#ifndef ONEGIN_STRING_COMPARISON
#define ONEGIN_STRING_COMPARISON

#include "string_function.h"

int Strcmp(const char* first_string, const char* second_string,
           int len_str1, int len_str2);

int BackStrcmp(const char* first_string, const char* second_string,
               int len_str1, int len_str2);

bool CorrectSymb(const char* str, int index);

bool EqualSymb(const char* string1, const char* string2, int index_first, int index_second);

#endif
