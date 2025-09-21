#ifndef ONEGIN_SORT_STRING
#define ONEGIN_SORT_STRING

#include "struct_text.h"
#include "string_comparison.h"
#include "add.h"
#include "string_function.h"
#include "sort_string.h"

void BubbleSort(char** ptr, TextPr* ptr_text);

int CompareStrcmp(const void* string1, const void* string2);

int CompareBackStrcmp(const void* string1, const void* string2);

int SortAndOutOnegin(TextPr* ptr_text, char* bufer, Sizes* size_par);

void DirectSort(TextPr* ptr_text, Sizes* size_par,
                const char* title1_onegin, FILE* file_out);

void ReverseSort(TextPr* text_ptr, Sizes* size_par,
                 const char* title2_onegin, FILE* file_out);

int WithoutSort(TextPr* text_ptr, Sizes* size_par, char* bufer,
                const char* title_onegin, FILE* file_out);

#endif
