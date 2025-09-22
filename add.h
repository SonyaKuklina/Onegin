#ifndef ONEGIN_ADD
#define ONEGIN_ADD

#include "string_function.h"
#include "struct_text.h"

char** ReadText(char** text);

void ChangeStrings(char** string1, char** string2);

long int SizeOfFile(void);

long int CountNewStr(char* bufer);

void FillText(char* bufer, TextPr* text_ptr, Sizes* size_par);

char* CorrectReadAndSizeFile(Sizes* size_par);

TextPr* CreateTextPointers(Sizes* size_par);

#endif
