#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        // Parent process
        printf("Child process started with PID: %d\n", pid);
        exit(0);
    }

    // Child process
    setsid();  // Create a new session

    for (int i = 1; i <= 5; ++i) {
        char filename[20];
        sprintf(filename, "file%d.txt", i);

        int fd = open(filename, O_CREAT | O_WRONLY, 0666);
        if (fd == -1) {
            perror("File creation failed");
            exit(1);
        }

        printf("File %s created with file descriptor: %d\n", filename, fd);

        
    }

    while (1) {
        // Loop infinitely to keep the program running
        sleep(5);
    }

    return 0;
}
