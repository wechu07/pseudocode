#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdint.h>
#include <stdarg.h>
/**
 *struct print - structure for printing various types
 *@t: type to print
 *@f: function to print
 */
// typedef struct print
// {
// 	char *t;
// 	int (*f)(va_list);
// } print_t;

void unsigned_number_to_string(uint64_t number, int base, char *buffer);
void number_to_string(uint64_t number, int base, char *buffer);
void _vprintf(const char *format, va_list arguments);
void _printf(const char *format, ...);
char *convert(unsigned int number, int base);
int _putchar(char c);

#endif  /* _MAIN_H */