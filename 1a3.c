#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char* fifo_name = "myfifo";
    mode_t fifo_mode = 0666; // Permissions
    
    // Create FIFO using mknod system call
    if (mknod(fifo_name, S_IFIFO | fifo_mode, 0) == 0) {
        printf("FIFO created successfully!\n");
    } else {
        perror("FIFO creation failed");
    }
    
    return 0;
}







