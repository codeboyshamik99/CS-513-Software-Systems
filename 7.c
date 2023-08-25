#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* input_file = fopen("file1", "rb");
    if (input_file == NULL) {
        perror("Failed to open input file");
        exit(1);
    }

    FILE* output_file = fopen("file2", "wb");
    if (output_file == NULL) {
        perror("Failed to open output file");
        fclose(input_file);
        exit(1);
    }

    int c;

    while ((c = fgetc(input_file)) != EOF) {
        if (fputc(c, output_file) == EOF) {
            perror("Write error");
            fclose(input_file);
            fclose(output_file);
            exit(1);
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("File copied successfully.\n");

    return 0;
}
