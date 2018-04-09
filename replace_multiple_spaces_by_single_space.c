#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void replace_multiple_spaces_by_single_space(char *s);

int main(int argc, char * * argv) {
    size_t length = 999;
    char *s = (char *) malloc((sizeof(char) * length));
    fgets(s, length, stdin);

    replace_multiple_spaces_by_single_space(s);

    printf("%s\n", s);

    return 0;
}

void replace_multiple_spaces_by_single_space(char *s){
    char *d = s;

    while (*s != '\0') {
    	while (*s == ' ' && *(s + 1) == ' ') {
    		s++;
    	}
    	*d++ = *s++;
    }

    if (*(d - 1) == '\n') {
    	*(d - 1) = '\0';
    	return;
    }

    *d = '\0';
}
