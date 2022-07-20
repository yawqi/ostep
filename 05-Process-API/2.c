#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int fd = open("2.txt", O_CREAT | O_RDWR);
    int pid = fork();
    if (pid) {
        for (int i = 0; i < 1000; i++) {
            write(fd, "parent\n", 7); 
        }
    } else {
        for (int i = 0; i < 1000; i++) {
            write(fd, "child\n", 6); 
        }
    }
}