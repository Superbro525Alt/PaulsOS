#ifndef _STDIO_H
#define _STDIO_H 1

#include <sys/cdefs.h>
#include <stdarg.h>
#include <stddef.h>

#define EOF (-1)

#ifdef __cplusplus
extern "C" {
#endif

int printf(const char* __restrict, ...);
int putchar(int);
int puts(const char*);
int sprintf(char *str, const char *format, ...);
int vsprintf(char *str, const char *format, va_list arg);
int snprintf(char* str, size_t size, const char* format, ...);
char* strncpy(char* destination, const char* source, size_t num);

#ifdef __cplusplus
}
#endif

#endif
