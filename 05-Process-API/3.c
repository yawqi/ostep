#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid < 0) {
        printf("fork failed!\n");
    } else if (pid == 0) {
        printf("hello");
    } else {
        sleep(1);
        printf(" goodbye\n");
    }
    return 0;
}