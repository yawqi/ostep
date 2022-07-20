#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int y = 100;
int main() {
    int x = 100;
    int pid = fork();
    if (pid == 0) {
        x += 10;
        y += 10;
        printf("%d\n", x);
        printf("%d\n", y);
        return 0;
    } else {
        int ret = wait(0);
        printf("%d\n", x);
        printf("%d\n", y);
    }
    return 0;
}