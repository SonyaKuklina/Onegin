#ifndef ONEGIN_STRING_FUNCTION
#define ONEGIN_STRING_FUNCTION


void Puts(const char* ptr); //����� ������ � �������

long long int Strchr(const char* ptr, int ch); //������� ������ ������� ��������� �������� ch � ������

int Strlen(const char* ptr); //������� ����� ������ (���� ����� �����������������)

char* Strcpy(char* new_str, const char* ptr);  //����������� ������

char* Strncpy(char* new_str, const char* ptr, size_t num); //����������� n �������� ������  (���� ����� ����������������)

char* Strcat(char* first_str, const char* second_str); //���������� ���� ����� � ����������� ��������� �� ������ ������

char* Strncat(char* first_str, const char* second_str, size_t num);

char* Fgets(char* ptr, int num, FILE* file);//��������� ������� �� �������� ������

char* Getline(char* buff, int size_buff, FILE* file); //��������� ������ �� �������� ������ � ��������� � ������

char* Strdup(const char* str); //������ ����� ������ � ������������ ������ � ���������� ��������� �� ��

long long int Strstr(const char* String, const char* SubString);//���� ��������� SubString � String � ���������� ������ ������� ������� ���������

int Atoi(const char* ptr);

long long int OptimizeStrstr(const char* String, const char* SubString);

#endif
