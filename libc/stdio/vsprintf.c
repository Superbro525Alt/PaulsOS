#include <stdio.h>
#include <stdarg.h>

int vsprintf(char *str, const char *format, va_list arg) {
    int len = 0;
    char buf[32]; // Temporary buffer for numeric conversions

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 's') {
                char *s = va_arg(arg, char *);
                while (*s != '\0') {
                    *str++ = *s++;
                    len++;
                }
            } else if (*format == 'd') {
                int i = va_arg(arg, int);
                int num_chars = sprintf(buf, "%d", i);
                for (int j = 0; j < num_chars; j++) {
                    *str++ = buf[j];
                    len++;
                }
            } else if (*format == 'x') {
                unsigned int u = va_arg(arg, unsigned int);
                int num_chars = sprintf(buf, "%x", u);
                for (int j = 0; j < num_chars; j++) {
                    *str++ = buf[j];
                    len++;
                }
            } else if (*format == 'c') {
                char c = (char) va_arg(arg, int);
                *str++ = c;
                len++;
            }
        } else {
            *str++ = *format;
            len++;
        }
        format++;
    }
    *str = '\0'; // Null-terminate the string
    return len;
}