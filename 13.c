#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for data on STDIN for 10 seconds...\n");

    int result = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);
    
    if (result == -1) {
        perror("select error");
        exit(1);
    } else if (result == 0) {
        printf("No data received within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            printf("Data available on STDIN within 10 seconds.\n");
        } else {
            printf("Unknown file descriptor.\n");
        }
    }

    return 0;
}

