// Created by Jason Pippin
/* This is my version of the linux cat command during the course of
learning the c language in the cs50 Introduction to Computer Science. */
// version 1.1
// added in line numbering and color prompt scheme for visual asthetics

#include <stdio.h>

int main(int argc, char *argv[])
{
    // Test for at least one argument
    if (argc < 2)
    {
        fprintf(stderr, "Usage: mycat [arg1] [arg2] ...\n");
        return 1;
    }

    // Loop through arguments passed in
    for (int i = 1; i < argc; i++)
    {
        // Open argument if valid
        FILE *arg = fopen(argv[i], "r");
        if (arg == NULL)
        {
            fprintf(stderr, "Error: Could not open file.\n");
            return 2;
        }

        // Print file name
        printf("\n\033[01;34mFILE: %s\n", argv[i]);
        // Assign first char before starting while loop
        char ch = fgetc(arg);
        // int for line counting
        int line_num = 0;
        // Print first line number
        printf("\033[01;33m%i\033[01;36m  ", line_num);
        while (ch)
        {
            if (ch == EOF)
            {
                break;
            }
            else if ( ch == '\n')
            {
                line_num++;
                putchar(ch);
                printf("\033[01;33m%d\033[01;36m  ", line_num);
                ch = fgetc(arg);
            }
            else
            {
                putchar(ch);
                ch = fgetc(arg);
            }
        }

        // Close arg
        fclose(arg);
        
        // End color scheme
        printf("\033[0m");
    }

    // Newline for asthetics
    printf("\n");

    return 0;
}
