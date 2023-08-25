#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    const char* filename = "example.txt";
    
    // Create a file using creat() system call
    int fd = creat(filename, 0666);
    if (fd == -1) {
        perror("File creation failed");
        //exit(1);
    }
    
    printf("File created successfully with file descriptor: %d\n", fd);
    
   
    
    return 0;
}
