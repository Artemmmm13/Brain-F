#include <stdio.h>
#define MEMORY_SIZE 30000
#define OUTPUT_BUFFER_SIZE 30000

void brain_fuck_interpreter(char* code){
    char memory[MEMORY_SIZE] = {0};
    char* ptr = memory;
    char output_buffer[OUTPUT_BUFFER_SIZE];
    int output_index = 0;


    while (*code != '\0'){
        switch (*code) {
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '+':
                ++(*ptr);
                break;
            case '-':
                --(*ptr);
                break;
            case '.':
                output_buffer[output_index++] = *ptr;
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                if (*ptr == 0){
                    int counter = 1;
                    while (counter > 0){
                        ++code;
                        if (*code == '['){
                            ++counter;
                        }
                        else if (*code == ']'){
                            --counter;
                        }
                    }
                }
                break;
            case ']':
                if (*ptr != 0){
                    int counter = 1;
                    while (counter > 0){
                        --code;
                        if (*code == '['){
                            --counter;
                        }
                        else if (*code == ']'){
                            ++counter;
                        }
                    }
                }
                break;
            default:
                break;
        }
        ++code;
    }
    output_buffer[output_index] = '\0';
    int i = 0;
    while (output_buffer[i] != '\0'){
        printf("%c", output_buffer[i]);
        ++i;
    }
}

int main() {
    return 0;
}
