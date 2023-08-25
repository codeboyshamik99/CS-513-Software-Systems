#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char* filename = "datafile.txt";
    
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("File open failed");
        exit(1);
    }

    const char* data1 = "0123456789";
    ssize_t bytes_written1 = write(fd, data1, 10);
    if (bytes_written1 != 10) {
        perror("Write error");
        close(fd);
        exit(1);
    }

    off_t seek_result = lseek(fd, 10, SEEK_CUR);
    if (seek_result == -1) {
        perror("lseek error");
        close(fd);
        exit(1);
    }

    const char* data2 = "abcdefghij";
    ssize_t bytes_written2 = write(fd, data2, 10);
    if (bytes_written2 != 10) {
        perror("Write error");
        close(fd);
        exit(1);
    }

    printf("lseek result: %ld\n", seek_result);

    return 0;
}

