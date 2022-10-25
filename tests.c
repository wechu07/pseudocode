#include "main.h"
#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

int main()
{

    void unsigned_number_to_string();
    void *pointer_to_main = (void *)main;

    _printf("Print a character: %c. Done!\n", 'G');
    _printf("Print a string: %s. Done!\n", "Hello World");
    _printf("Print a positive integer: %d. Done!\n", 10);
    _printf("Print a negative integer: %d. Done!\n", -10);
    _printf("Print a (zero) integer: %d. Done!\n", 0);
    _printf("Print a hexademical: %x. Done!\n", '0');
    _printf("Print a zero hexademical: %x. Done!\n", '0');
    _printf("Print a pointer: %p. Done!\n", pointer_to_main);

    return 0;
}