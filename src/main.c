#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int read_lines = 0;
    int read_bytes = 0;
    int read_words = 0;
    int read_chars = 0;
    int total_lines = 0;
    int total_words = 0;
    int total_files = 0;
    int total_bytes = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'c':
                    read_bytes = 1;
                    break;
                case 'l':
                    read_lines = 1;
                    break;
                case 'w':
                    read_words = 1;
                    break;
                case 'm':
                    read_chars = 1;
                    break;
            }
        } else {
            total_files++;
        }
    }

    if (read_lines == 0 && read_words == 0 && read_bytes == 0 && read_chars == 0) {
        read_lines = 1;
        read_words = 1;
        read_bytes = 1;
    }

    FILE *fptr;
    int no_files = 0;

    if (total_files == 0) {
        total_files = 1;
        no_files = 1;
        fptr = stdin;
    }

    for (int i = total_files; i > 0; i--) {
        if (no_files == 0) {
            if ((fptr = fopen(argv[argc - i], "rb")) == NULL) {
                printf("Error opening file");
                exit(1);
            }
        } else {
            fptr = stdin;
        }

        char last_char;
        while (!feof(fptr)) {
            char c = fgetc(fptr);
            if (c == EOF) {
                break;
            }
            if (read_bytes == 1 || read_chars == 1) {
                total_bytes++;
            }
            if (read_lines == 1) {
                if (c == '\n') {
                    total_lines++;
                }
            }
            if (read_words == 1) {
                if (!isspace(last_char) && isspace(c)) {
                    total_words++;
                }
            }
            last_char = c;
        }
        if (!isspace(last_char)) {
            total_words++;
        }
        fclose(fptr);
    }

    if (read_lines == 1) {
        printf(" %d ", total_lines);
    }
    if (read_words == 1) {
        printf(" %d ", total_words);
    }
    if (read_bytes == 1 || read_chars == 1) {
        printf(" %d ", total_bytes);
    }
    for (int i = total_files; i > 0; i--) {
        if (no_files == 0) {
            printf(" %s ", argv[argc - i]);
        }
    }
    return 0;
}