// Created by Jason Pippin
/* This is my version of the linux cat command during the course of
learning the c language in the cs50 Introduction to Computer Science. */
// version 1.2
// Updates: getline() replaces getc() and can now accept more than one argument
// from the command line for files to read

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("\nUsage: mycat [arg1] [arg2] [...]\n\n");
        return 1;
    }

    // Iterate through arguments
    for (int i = 1; i < argc; i++)
    {

        // Set up for getline()
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;

        // Open file for reading
        FILE *stream;
        stream = fopen(argv[i], "r");
        
        // Read lines to stdout
        int line_counter = 1;
        printf("\n\033[01;33m%s\033[0m\n", argv[i]);
        while (nread = getline(&line, &len, stream) != -1)
        {
            if (nread == -1)
            {
                printf("\033[01;31mERROR: getline()\033[0m\n");
                return 2;
            }
            printf("\033[0m%i \033[01;36m%s", line_counter, line);
            line_counter++;
        }
        free(line);
        fclose(stream);
    }
    // End color scheme
    printf("\033[0m");
    return 0;
}
