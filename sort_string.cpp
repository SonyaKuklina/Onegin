#include <stdio.h>
#include "sort_string.h"
#include "struct_text.h"
#include <cassert>
#include "string_comparison.h"

void BubbleSort(TextPr* text_ptr, Sizes* size_par, int (*StringComp)(const char*, const char*)) {

    assert(size_par -> size_text != NULL);
    assert(size_par -> size_f    != NULL);
    assert(size_par -> size_read != NULL);
    assert(text_ptr -> text      != NULL);
    assert(text_ptr -> len_str   != NULL);

    for (int i = 0; i < (size_par -> size_text) - 1; i++) {
        for (int j = 0; j < (size_par-> size_text) - 1; j++) {

            if (StringComp((text_ptr + j) -> text, (text_ptr + j + 1) -> text) == 1) {

                ChangeStrings(&((text_ptr + j) -> text), &((text_ptr + j + 1) -> text));
            }
        }
    }

}

int CompareStrcmp(const void* string1, const void* string2) {

    assert(string1 != NULL);
    assert(string2 != NULL);

    const TextPr* str1 = (const TextPr*)(string1);
    const TextPr* str2 = (const TextPr*)(string2);

    assert(str1 != NULL);
    assert(str2 != NULL);

    return Strcmp(str1 -> text ,str2 -> text);

}

int CompareBackStrcmp(const void* string1, const void* string2) {

    assert(string1 != NULL);
    assert(string2 != NULL);

    const TextPr* str1 = (const TextPr*)(string1);
    const TextPr* str2 = (const TextPr*)(string2);

    assert(str1 != NULL);
    assert(str2 != NULL);

    return BackStrcmp(str1 -> text, str2 -> text, str1 -> len_str, str2 -> len_str);

}

int SortAndOutOnegin(TextPr* text_ptr, char* bufer, Sizes* size_par) {

    assert(size_par -> size_text != NULL);
    assert(size_par -> size_f    != NULL);
    assert(size_par -> size_read != NULL);
    assert(text_ptr -> text      != NULL);
    assert(text_ptr -> len_str   != NULL);
    assert(bufer != NULL);

    const char* title1_onegin = "ONEGIN. REGUAL SORTING\n\n";
    const char* title2_onegin = "\n\n\n\n\nONEGIN. REVERSE SORT\n\n";
    const char* title_onegin  = "\n\n\n\n\nONEGIN. WITHOUT SORT\n\n";

    FILE* file_out = fopen("OneginOut.txt", "w");

    if (file_out == NULL)
        return -1;

    Sort(text_ptr, size_par, title1_onegin, file_out, CompareStrcmp);
    Sort(text_ptr, size_par, title2_onegin, file_out, CompareBackStrcmp);

    if (WithoutSort(text_ptr, size_par, bufer, title_onegin, file_out) == -1)
        return -1;

    return 0;

}

void Sort(TextPr* text_ptr, Sizes* size_par,
                const char* title1_onegin, FILE* file_out,
                int (*CompareString)(const void*, const void*)) {

    assert(size_par -> size_text != NULL);
    assert(size_par -> size_f    != NULL);
    assert(size_par -> size_read != NULL);
    assert(text_ptr -> text      != NULL);
    assert(text_ptr -> len_str   != NULL);
    assert(file_out != NULL);

    qsort(text_ptr, (size_par -> size_text), sizeof(TextPr), CompareString);

    fputs(title1_onegin, file_out);
    int index = 0;
    TextPr* start_text_ptr = text_ptr;

    assert(start_text_ptr != NULL);

    while (index < (size_par -> size_text)) {

        fprintf(file_out, "%.*s", (start_text_ptr -> len_str) + 1, start_text_ptr -> text);
        index++;
        start_text_ptr++;

    }

}

int WithoutSort(TextPr* text_ptr, Sizes* size_par, char* bufer,
                const char* title_onegin, FILE* file_out) {

    assert(text_ptr != NULL);
    assert(size_par != NULL);
    assert(file_out != NULL);
    assert(bufer != NULL);

    free(text_ptr);

    fputs(title_onegin, file_out);

    if (fwrite(bufer, sizeof(char), size_par -> size_f, file_out) != (size_t)(size_par -> size_read))
        return -1;

    free(bufer);

    return 1;

}
