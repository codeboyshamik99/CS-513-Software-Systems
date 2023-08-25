#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    const char* filename = argv[1];

    int fd = open(filename, O_RDONLY | O_CREAT, 0666);
    if (fd == -1) {
        perror("File open failed");
        exit(1);
    }

    int flags = fcntl(fd, F_GETFL);

    if (flags == -1) {
        perror("fcntl error");
        close(fd);
        exit(1);
    }

    int access_mode = flags & O_ACCMODE;

    printf("Access mode of the file %s: ", filename);
    if (access_mode == O_RDONLY) {
        printf("Read-only\n");
    } else if (access_mode == O_WRONLY) {
        printf("Write-only\n");
    } else if (access_mode == O_RDWR) {
        printf("Read-write\n");
    }

    return 0;
}

