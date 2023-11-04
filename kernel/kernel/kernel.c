#include <stdio.h>
#include <time.h>

#include <kernel/tty.h>
#include <kernel/fs/fs.h>
#include <kernel/keyboard/keyboard.h>
#include <kernel/types.h>

void kernel_main(void) {
	terminal_initialize();
	printf("Hello, kernel World!\n");
    printf("Press any key to continue...\n");

    keyboard_init();
    while (1) {
        hex key = get_key_down();
        printf("Key Pressed: ");
        printf("%x", key);
        printf(" ");
        printf(keycode_to_string(key));
        printf("\n");

    }

}
