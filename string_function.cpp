#include <stdio.h>
#include "string_function.h"
#include <cassert>
#include <string.h>

void Puts(const char* ptr) {

    assert(ptr != NULL);

    while (*ptr != '\0') {

        putchar(*ptr);
        ptr++;

    }

    putchar('\n');

}

long long int Strchr(const char* ptr, int ch) {

    assert(ptr != NULL);

    long long int num_symbol = 0;
    const char* ptr_start = ptr;

    assert(ptr_start != NULL);

    while (*ptr != '\0') {

        if (*ptr == ch) {

            num_symbol = ptr - ptr_start;
            break;

        }

        ptr++;

    }

    return num_symbol;

}

int Strlen(const char* ptr) {

    assert(ptr != NULL);

    int str_len = 0;
    while (*ptr != '\0') {
        str_len++;
        ptr++;
    }
    return str_len;
}

char* Strcpy(char* new_str, const char* ptr) {

    assert(new_str != NULL);
    assert(ptr     != NULL);

    char* now_new_str = new_str;

    assert(now_new_str != NULL);

    int index = 0;

    while (*(ptr + index) != '\0') {

        *(now_new_str + index) = *(ptr + index);
        index++;

    }

    *(now_new_str + index) = '\0';
    return new_str;

}

char* Strncpy(char* new_str, const char* ptr, size_t num) {

    assert(new_str != NULL);
    assert(ptr     != NULL);

    char* now_new_str = new_str;

    assert(now_new_str != NULL);

    int index = 0;

    while (*(ptr + index) != '\0') {

        if (num == 0)
            break;

        *(now_new_str + index) = *(ptr + index);
        index++;
        num--;

    }

    *(now_new_str + index) = '\0';
    return new_str;

}

char* Strcat(char* first_str, const char* second_str) {

       assert(first_str  != NULL);
       assert(second_str != NULL);

       char* start_first_str = first_str;

       assert(start_first_str != NULL);

       while (*first_str != '\0')
            first_str++;

       int index = 0;

       while (*(second_str + index) != '\0') {

            *(first_str + index) = *(second_str + index);
            index++;

       }

       *(first_str + index) = '\0';
       return start_first_str;

}

char* Strncat(char* first_str, const char* second_str, size_t num) {

       assert(first_str  != NULL);
       assert(second_str != NULL);

       char* start_first_str = first_str;

       assert(start_first_str != NULL);

       while (*first_str != '\0')
            first_str++;

       int index = 0;

       while (*(second_str + index) != '\0') {

            if (num == 0)
                break;

            *(first_str + index) = *(second_str + index);
            index++;
            num--;

       }

       *(first_str + index) = '\0';
       return start_first_str;

}

char* Fgets(char* ptr, int num, FILE* file) {

     assert(ptr  != NULL);
     assert(file != NULL);

     if ((file == NULL) || (num == 0))
        return NULL;

     char* new_ptr = ptr;

     assert(new_ptr != NULL);

     int c = fgetc(file);

     while ((c != EOF) && (c != '\0')) {

            if (num == 0)
                break;

            *ptr = c;
            num--;

            if (*ptr == '\n') {
                ptr++;
                break;
            }

            c = fgetc(file);
            ptr++;

     }

     *ptr = '\0';
     return new_ptr;

}


char* Strdup(const char* str) {

    assert(str != NULL);

    if (malloc((Strlen(str) + 1) * sizeof(char)) == NULL)
        return NULL;

    char* buff_copy = (char*) malloc((Strlen(str) + 1) * sizeof(char));
    char* start_buff_copy = buff_copy;

    assert(buff_copy       != NULL);
    assert(start_buff_copy != NULL);

    int index = 0;

    while (*(str + index) != '\0') {

          *(buff_copy + index) = *(str + index);
          index++;

    }

    *(buff_copy + index)= '\0';
    return start_buff_copy;

}

char* Getline(char* buff ,int size_buff, FILE* file) {

    assert(buff != NULL);
    assert(file != NULL);

    if (realloc(buff, (size_buff + 1) * sizeof(char)) == NULL)
        return NULL;

    buff = (char*) realloc(buff, (size_buff + 1) * sizeof(char));
    char* start_buff = buff;

    assert(start_buff != NULL);

    if ((file == NULL) || (size_buff == 0))
        return NULL;

    int c = fgetc(file);

    while ((c != EOF) && (c != '\0')) {

           if (size_buff == 0)
                break;

            *buff = c;
            size_buff--;
            c = fgetc(file);
            buff++;

    }

    *buff = '\0';
    return start_buff;

}

long long int Strstr(const char* String, const char* SubString) {

    assert(String    != NULL);
    assert(SubString != NULL);

    int len_str = Strlen(SubString);

    if ((len_str) > (Strlen(String)))
        return -1;

    int number_of_matches = 0;
    const char* start_ptr = String;
    int index = 0;

    assert(start_ptr != NULL);

    while (*(String + index) != '\0') {

         while (*(String + index) == *(SubString + index)) {

              number_of_matches++;
              index++;

         }

         if (number_of_matches == len_str)
            return String - start_ptr;

         number_of_matches = 0;
         String++;
         index = 0;
    }

    return -1;

}

int Atoi(const char* ptr) {

    assert(ptr != NULL);

    int num = 0;
    bool have_minus = false;
    int index = 0;

    while (*(ptr + index) == ' ')
        index++;

    if (*(ptr + index) == '-') {
        have_minus = true;
        index++;
    }

    while (('0' <= *(ptr + index)) && (*(ptr + index) <= '9'))  {

        num = 10 * num + (*(ptr + index) - '0');
        index++;

    }

    if (have_minus)
        return (-num);

    return num;

}

long long int OptimizeStrstr(const char* String, const char* SubString) {

    assert(String    != NULL);
    assert(SubString != NULL);

    const char* start_string = String;
    int count_symbols[26];

    assert(start_string != NULL);

    for (int i = 0; i < 26; i++) //заполняем массив -1
        count_symbols[i] = -1;

    int index = 0;

    while (*(SubString + index) != '\0') { //заполняем массив с индексами

        count_symbols[*(SubString + index) - 'a'] = index; //записываем индекс самого праваого вхождения элемента в подстроку
        index++;

    }

    int len_substring = Strlen(SubString) - 1;
    index = len_substring;

    while (*(String + index) != '\0') {

        while (*(String + index) == *(SubString + index))  {
            index--;
        }

        if (index == -1)
             return String - start_string;

        if (count_symbols[*(String + index) - 'a'] != -1) {
             String = String + (len_substring - count_symbols[*(String + index) - 'a']);

        } else {
            String = String + len_substring + 1;

        }

        index = len_substring;

    }

    return -1;

}
