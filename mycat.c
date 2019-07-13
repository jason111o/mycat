// Created by Jason Pippin
/* This is my version of the linux cat command during the course of
learning the c language in the cs50 Introduction to Computer Science. */
// Updates: You can now pass in the first arguments to display the help
// menu or program version... -h -v

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VERSION "\n Version 1.3\n\n"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("\n Usage: mycat [options|arg1] [arg2] [arg3] [...]\n\n");
        return 1;
    }

    // Check for options and display them if called
    int len = strlen(argv[1]);
    char version[3] = "-v";
    char help[3] = "-h";
    if (len == 2)
    {
        if (argv[1][0] == version[0] && argv[1][1] == version[1])
        {
            printf(VERSION);
            return 0;
        }
        else if (argv[1][0] == help[0] && argv[1][1] == help[1])
        {
            printf("\n mycat is a simple program developed by Jason Pippin\n");
            printf(" while learning the C programming language. It is, in its\n");
            printf(" simplest form a version of the Linux coreutils command cat.\n");
            printf(" Pass in file names as arguments on the command line to view\n");
            printf(" their contents using a getline function in C.\n");
            printf(" Usage: mycat [options|arg1] [arg2] [arg3] [...]\n\n");
            return 0;
        }
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
        if (!stream)
        {
            fprintf(stderr, "\n Unable to open \"%s\"\n\n", argv[1]);
            return 2;
        }
        
        // Read lines to stdout
        int line_counter = 1;
        printf("\n\033[01;33m%s\033[0m\n", argv[i]);
        while (nread = getline(&line, &len, stream) != -1)
        {
            if (nread == -1)
            {
                printf("\033[01;31mERROR: getline()\033[0m\n");
                return 3;
            }
            printf("\033[0m%i \033[01;36m%s", line_counter, line);
            line_counter++;
        }
        free(line);
        fclose(stream);
    }
    // End color scheme
    printf("\033[0m\n");

    return 0;
}
