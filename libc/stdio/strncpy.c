#include <stddef.h>

char* strncpy(char* destination, const char* source, size_t num) {
    char* dest = destination;

    // Copy characters from the source to the destination
    while (num > 0 && *source != '\0') {
        *dest = *source;
        dest++;
        source++;
        num--;
    }

    // Null-terminate the destination string
    while (num > 0) {
        *dest = '\0';
        dest++;
        num--;
    }

    return destination;
}
