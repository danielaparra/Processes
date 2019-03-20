// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    printf("hello\n");
    int pid = fork();

    if (pid == 0) {
        execlp("ls", "ls", NULL);
        perror("exec");
        // Doesn't print this goodbye because of exec.
        printf("goodbye\n");
        exit(1);
    } else {
        wait(NULL);
        printf("goodbye\n");
    }   

    return 0;
}
