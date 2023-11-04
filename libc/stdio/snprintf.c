#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SNPRINTF_MAX_BUFFER 32

int snprintf(char* str, size_t size, const char* format, ...) {
    va_list args;
    va_start(args, format);

    int written = 0;
    size_t remaining = size;
    char buffer[SNPRINTF_MAX_BUFFER];

    while (*format && remaining > 1) {
        if (*format != '%') {
            str[written++] = *format;
            format++;
            remaining--;
        } else {
            format++;  // Consume '%'

            // Flags (optional)
            while (*format == ' ' || *format == '0') {
                format++;
            }

            // Width (optional)
            while (*format >= '0' && *format <= '9') {
                format++;
            }

            // Length modifiers (ignored in this simplified implementation)
            while (*format == 'h' || *format == 'l') {
                format++;
            }

            // Conversion specifier
            if (*format == 'd' || *format == 'i') {
                int value = va_arg(args, int);
                written += snprintf(buffer, SNPRINTF_MAX_BUFFER, "%d", value);
            } else if (*format == 'u') {
                unsigned int value = va_arg(args, unsigned int);
                written += snprintf(buffer, SNPRINTF_MAX_BUFFER, "%u", value);
            } else if (*format == 's') {
                const char* value = va_arg(args, const char*);
                written += snprintf(buffer, SNPRINTF_MAX_BUFFER, "%s", value);
            } else if (*format == 'x') {
                unsigned int value = va_arg(args, unsigned int);
                written += snprintf(buffer, SNPRINTF_MAX_BUFFER, "%#x", value);
            } else {
                // Unsupported format specifier, print as-is
                str[written++] = '%';
                str[written++] = *format;
                remaining -= 2;
            }

            // Copy the buffer into the output string
            size_t copy_len = remaining < (size_t)written ? remaining : (size_t)written;
            strncpy(&str[written - written], buffer, copy_len);
            format++;
        }
    }

    va_end(args);

    if (remaining > 0) {
        str[written] = '\0';  // Null-terminate the output string
    } else {
        // Handle overflow, set the last character to null terminator
        str[size - 1] = '\0';
        // TODO: Set errno to EOVERFLOW.
        return -1;
    }

    return written;
}
