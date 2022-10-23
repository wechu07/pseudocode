#include <stdio.h>

char *convert(unsigned int number, int base)
{
    static char representation[] = "0123456789ABCDEF";
    static char buffer[50];
    char *pointer;

    pointer = &buffer[49];
    *pointer = '\0';

    do
    {
        *--pointer = representation[number % base];
        number /= base;
    } while (number != 0);

    return(pointer);
}