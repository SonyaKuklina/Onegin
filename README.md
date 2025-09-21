# Onegin
## Описание проекта
> Данная программа выполняет прямую и обратную сортировки текста Онегина.
> Текст произведения берётся из файла **Onegin.txt**, а результаты сортировок и исходный текст записываются в файл **OneginOut.txt**
## Принцип работы
> Содержимое файла **Onegin.txt** считывается в буфер (одномерный массив символов), на основе которого создаётся массив **text_ptr**, каждый элемент которого хранит адрес текущей строки в буфере и её длину. Сортировка  строк происходит за счёт посимвольного сравнения с начала/с конца. Для того, чтобы поменять строки местами, меняются местами указатели на эти строки.
## Файловое разбиение программы
![](2025-09-21.png)
## Qsort
> Встроенная функция qsort получает в качестве параметров:
> 1. Указатель на массив, который нужно отсортировать (в данном случае массив типа **TextPr**, каждый элемент которого содержит адрес начала строки и её длину)
> 2. Количество в сортируемом массиве
> 3. Размер одного элемента массива в байтах
> 4. Компаратор, в который передаётся функция стравнения двух элементов массива (в данном случае это **Strcmp** и **BackStrcmp**)
## Флаги компиляции
```
g++ main.cpp string_function.cpp string_comparison.cpp add.cpp sort_string.cpp -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

```
