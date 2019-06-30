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
        printf("\nFILE: %s\n", argv[i]);
        // Assign first char before starting while loop
        char ch = fgetc(arg);
        while (ch != EOF)
        {
            putchar(ch);
            ch = fgetc(arg);
        }

        // Close arg
        fclose(arg);
    }

    // Newline for asthetics
    printf("\n");

    return 0;
}
