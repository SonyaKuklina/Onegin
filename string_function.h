#ifndef ONEGIN_STRING_FUNCTION
#define ONEGIN_STRING_FUNCTION


void Puts(const char* ptr); //вывод строки в консоль

long long int Strchr(const char* ptr, int ch); //выводит индекс первого вхождения элемента ch в строку

int Strlen(const char* ptr); //выводит длину строки (надо будет подкорректировать)

char* Strcpy(char* new_str, const char* ptr);  //копирование строки

char* Strncpy(char* new_str, const char* ptr, size_t num); //копирование n символов строки  (надо будет подредактировать)

char* Strcat(char* first_str, const char* second_str); //склеивание двух строк и возвращение указателя на первый символ

char* Strncat(char* first_str, const char* second_str, size_t num);

char* Fgets(char* ptr, int num, FILE* file);//считывает символы из входного потока

char* Getline(char* buff, int size_buff, FILE* file); //считывает строку из входного потока и сохраняет в буффер

char* Strdup(const char* str); //создаёт копию строки в динамической памяти и возвращает указатель на неё

long long int Strstr(const char* String, const char* SubString);//ищет подстроку SubString в String и возвращает индекс символа первого вхождения

int Atoi(const char* ptr);

long long int OptimizeStrstr(const char* String, const char* SubString);

#endif
