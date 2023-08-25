#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

    while (1) {
        // Your background process logic here
        // This loop will run infinitely in the background
        sleep(5);  // Sleep for 5 seconds before the next iteration
    }

    return 0;
}

