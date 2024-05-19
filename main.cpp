#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c/-w] [input_file_name]\n", argv[0]);
        return 1;
    }

    FILE *file;
    char *filename = argv[2];
    char *parameter = argv[1];
    char ch;
    int charCount = 0;
    int wordCount = 0;
    int inWord = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        charCount++;

        if (parameter[1] == 'c' && isspace(ch)) {
            continue;
        }

        if (isalnum(ch) && !inWord) {
            inWord = 1;
            wordCount++;
        } else if (!isalnum(ch)) {
            inWord = 0;
        }
    }

    fclose(file);

    if (parameter[1] == 'c') {
        printf("¡Á?¡¤?¨ºy¡êo%d\n", charCount);
    } else if (parameter[1] == 'w') {
        printf("¦Ì£¤¡ä¨º¨ºy¡êo%d\n", wordCount);
    }

    return 0;
}
