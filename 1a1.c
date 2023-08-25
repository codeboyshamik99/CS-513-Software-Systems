#include <unistd.h>
#include<stdio.h>
int main() {
    const char* source_file = "source.txt";
    const char* softlink_name = "softlink.txt";
    int status;
    status = symlink(source_file, softlink_name);
    if (status == -1)
            printf("Error while creating hard link!");
        else
            printf("Successfully created a hard link.");
    return 0;
}
