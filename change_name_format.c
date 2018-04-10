//This program change name in the format "Family Name - Middle Name - Name" to "Name - Family Name - Middle Name"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Search (char source[], int x);
void Copy (char source[], char dest[], int loc, int length);

int main (int argc, char **argv)
{
    size_t length = 99;
    char dest[3][length];
    int start = 0;
    char *source = (char *) malloc (sizeof (char) * length);
    fgets (source, length, stdin);

    for (int i = 0; i < strlen (source);)
    {
        Copy (source, dest[start++], i, Search (source, i) - i);
        i = Search (source, i) + 1;
    }
    printf ("Output:\n%s\n%s\n%s\n", dest[2], dest[0], dest[1]);
    return 0;
}

int Search (char source[], int x)
{
    for (int i = x + 1; i < strlen (source); i++)
        if (source[i] == ' ')
            return i;
    return strlen (source) - 1;
}

void Copy (char source[], char dest[], int loc, int length)
{
    for (int i = loc, j = 0; i < loc + length; ++i, ++j)
    {
        dest[j] = source[i];
    }
    dest[length] = '\0';
}
