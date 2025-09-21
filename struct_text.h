#ifndef ONEGIN_STRUCT_TEXT
#define ONEGIN_STRUCT_TEXT

struct TextPr {
        char* text;
        int len_str;
       };

struct Sizes {
        long int size_text = 0;
        long int size_f = 0;
        long int size_read = 0;
       };

#endif
