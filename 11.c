#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char* filename = "output.txt";
    
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("File open failed");
        exit(1);
    }

    int new_fd = dup(fd);
    if (new_fd == -1) {
        perror("dup failed");
        close(fd);
        exit(1);
    }

    int new_fd2 = dup2(fd, 3);
    if (new_fd2 == -1) {
        perror("dup2 failed");
        close(fd);
        exit(1);
    }

    const char* data = "Hello, world!\n";
    ssize_t bytes_written1 = write(fd, data, strlen(data));
    ssize_t bytes_written2 = write(new_fd, data, strlen(data));
    ssize_t bytes_written3 = write(new_fd2, data, strlen(data));

    if (bytes_written1 == -1 || bytes_written2 == -1 || bytes_written3 == -1) {
        perror("Write error");

        exit(1);
    }

    printf("Data written to the file.\n");

  

    return 0;
}

