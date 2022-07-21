#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
extern char **environ;
int main() {
    // execl
    if (!fork()) {
        printf("execl(\"/bin/ls\", \"ls\", NULL)\n");
        fflush(0);
        execl("/bin/ls", "ls", NULL);
    } else {
        wait(0);
    }

    // execlp
    if (!fork()) {
        printf("execlp(\"/bin/ls\", \"ls\", NULL)\n");
        fflush(0);
        execlp("/bin/ls", "ls", NULL);
    } else {
        wait(0);
    }

    // execle
    if (!fork()) {
        printf("execle(\"/bin/ls\", \"ls\", NULL, environ)\n");
        fflush(0);
        execl("/bin/ls", "ls", NULL, environ);
    } else {
        wait(0);
    }

    // execv
    char *argv[] = {"ls", NULL};
    if (!fork()) {
        printf("execv(\"/bin/ls\", argv)\n");
        fflush(0);
        execv("/bin/ls", argv);
    } else {
        wait(0);
    }

    // execvp
    if (!fork()) {
        printf("execvp(\"ls\", argv)\n");
        fflush(0);
        execvp("ls", argv);
    } else {
        wait(0);
    }

    // execvpe
    // if (fork()) {
    //     printf("execvpe(\"ls\", argv, environ)");
    //     execvpe("ls", argv, environ);
    // } else {
    //     wait(0);
    // }
    return 0;
}