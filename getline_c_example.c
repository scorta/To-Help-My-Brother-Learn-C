#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char *s;
    size_t l = 0;
    s = (char*)malloc(l * sizeof(char));
    getline(&s, &l, stdin);
    
    printf("%s\n", s);

    return 0;
}
