#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

// the function that we are implementing is _printf
// @format: the string to be formatted
// @arguments: object (struct) containing the arguments to be handled
// _vprintf: the function that implements each argument
void _printf(const char *format, ...)
{

    va_list arguments;
    va_start(arguments, format);

    _vprintf(format, arguments);

    va_end(arguments);
}