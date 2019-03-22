// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp= fopen("text.txt", "r+");

    char text[128];

    while(fgets(text, 128, fp) != NULL) {
        printf("%s", text);
    }

    pid_t pid = fork();

    if (pid == 0) {
        fprintf(fp, "Child has accessed file.\n");

        // while(fgets(text, 128, fp) != NULL) {
        //     printf("%s", text);
        // }
    } else {
        fprintf(fp, "Parent has accessed file.\n");
        
        // while(fgets(text, 128, fp) != NULL) {
        //     printf("%s", text);
        // }
    }

    fclose(fp);

    return 0;
}
