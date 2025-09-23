#include <stdio.h>
#include "struct_text.h"
#include <cassert>
#include <string.h>
#include "string_function.h"
#include "add.h"

void ChangeStrings(char** string1, char** string2) {

    assert(string1 != NULL);
    assert(string2 != NULL);

    char* per = *string1;

    assert(per != NULL);

    *string1 = *string2;
    *string2 = per;

}


long int SizeOfFile(void) {

    FILE* file_open = fopen("Onegin.txt", "rb");

    if (file_open == NULL)
        return -1;

    fseek(file_open, 0, SEEK_END);

    long int size_of_file = ftell(file_open);

    rewind(file_open);
    fclose(file_open);

    return size_of_file;

}

long int CountNewStr(char* bufer) {

    assert(bufer != NULL);

    long int count_str = 0;
    long long int c = Strchr(bufer,'\n');
    char* start_bufer = bufer;

    assert(start_bufer != NULL);

    while (c != 0) {

        count_str++;
        start_bufer += c + 1;
        c = Strchr(start_bufer,'\n');

    }

    return count_str;

}

void FillText(char* bufer, TextPr* text_ptr, Sizes* size_par) {

     assert(size_par -> size_text != NULL);
     assert(size_par -> size_f    != NULL);
     assert(size_par -> size_read != NULL);
     assert(text_ptr != NULL);
     assert(bufer    != NULL);

     long int start_string = 0;
     TextPr* text_ptr_start = text_ptr;

     assert(text_ptr_start != NULL);

     for (int index = 0; index < (size_par -> size_f) - 1; index++) {

         if (*(bufer + index) == '\n') {

              (text_ptr_start -> len_str) = index - start_string;
              (text_ptr_start -> text) = (bufer + index) - (text_ptr_start -> len_str);
              text_ptr_start++;
              start_string = index + 1;

         }

     }

}

char* CorrectReadAndSizeFile(Sizes* size_par) {

    assert(size_par != NULL);

    if (SizeOfFile() == -1)
        return NULL;

    else
        (size_par -> size_f) = SizeOfFile();


    FILE* file_in = fopen("Onegin.txt", "r");

    if ( file_in == NULL )
        return NULL;

    char* bufer = (char*) calloc(((size_par -> size_f) + 1), sizeof(char));

    assert(bufer != NULL);

    if ( bufer == NULL )
        return NULL;

    (size_par -> size_read) = fread(bufer, sizeof(char), size_par -> size_f, file_in);
    (size_par -> size_f) = (size_par -> size_read);
    *(bufer + (size_par -> size_read)) = '\0';

    (size_par -> size_text) = CountNewStr(bufer);

    return bufer;

}

TextPr* CreateTextPointers(Sizes* size_par) {

    assert(size_par -> size_text != NULL);
    assert(size_par -> size_f    != NULL);
    assert(size_par -> size_read != NULL);


    return (TextPr*)calloc((size_par -> size_text), sizeof(TextPr));

}
