//#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <stdlib.h> //для выделения динамической памяти
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "string_function.h"
#include "string_comparison.h"
#include "add.h"
#include "sort_string.h"
#include "struct_text.h"

int main(void) {

    Sizes size_par = {};

    char* bufer = CorrectReadAndSizeFile(&size_par);

    if (bufer == NULL)
        return -1;

    TextPr* text_ptr = (TextPr*) calloc(size_par.size_text, sizeof(TextPr));

    FillText(bufer, text_ptr, &size_par);

    if (SortAndOutOnegin(text_ptr, bufer, &size_par) == -1)
        return -1;

    return 0;
}





