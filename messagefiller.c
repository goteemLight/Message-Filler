#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    //Make sure the user is using the program correctly.
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./messagefiller texttoduplicate messagecharactercap\n");
        return 1;
    }

    //Parse user input.
    char *texttoduplicate = argv[1];
    int messagecharactercap = atoi(argv[2]);

    //Store the length of the duplicated text to know when the program should stop duplicating text.
    int textlength = strlen(texttoduplicate) + 1;

    FILE *copypasta = fopen("copypasta.txt", "w+");

    //Make sure file was created.
    if (!copypasta)
    {
        fprintf(stderr, "Your text file could not be created.\n");
        return 2;
    }

    //Create a variable to keep track of the amount of characters to be written into a text file.
    int charactercount = 0;

    //Keep on duplicating text into a file until it exceeds the user inputted message character cap.
    while (charactercount + textlength < messagecharactercap)
    {
        fputs(texttoduplicate, copypasta);
        fputc(' ', copypasta);
        charactercount += textlength;
    }

    fclose(copypasta);
}
