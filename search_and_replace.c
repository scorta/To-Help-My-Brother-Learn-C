#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void RemoveNewLine(char s[]) {
	if (s && s[strlen(s) - 1] == '\n') {
		s[strlen(s) - 1] = '\0';
	}
}

int CheckFrom(const char s[], const char s1[], const size_t start) {
	for (size_t i = 0, j = start; i < strlen(s1); ++i, ++j) {
		if (s1[i] != '\n' && s1[i] != s[j]) {
			return -1;
		}
	}
	return start;
}

int Search(const char s[], const char s1[], const size_t start) {
	for (size_t i = start; i < strlen(s) - strlen(s1) + 1; ++i) {
		int result = CheckFrom(s, s1, i);
		if (result >= 0) {
			return result;
		}
	}
	return -1;
}

void Copy(char dest[], const char source[], const int from_dest, const int from_source, const int to_source) {
	for (int i = from_dest, j = from_source; i <= (to_source - from_source) + from_dest; ++i, ++j) {
		dest[i] = source[j];
	}
	printf("\nCOPY dest %s \n source %s\n", dest, source);
}

char *Replace(char s[], const char s1[], const char s2[]) {
	printf("Replace\n");
	size_t result_length = 0;
	size_t count = 0;
	for (size_t i = 0; i < strlen(s) - strlen(s1) + 1; ++i) {
		if (CheckFrom(s, s1, i) >= 0) {
			++count;
		}
	}

	char *result = (char*)malloc(sizeof(char) * (strlen(s) + count * (strlen(s2) - strlen(s1))));
	Copy(result, s, 0, 0, strlen(s) - 1);
	printf("\nR - S %s - %s\n", result, s);

	result_length = strlen(s) + count * (strlen(s2) - strlen(s1));
	int temp = strlen(result);
	result[result_length] = '\0';

	for (int i_s = 0, pos = Search(s, s1, i_s), i = 0; pos >= 0; pos = Search(s, s1, i_s)) {
		printf("\nResult %s %d %d %d\n", result, i, i_s, pos);
		Copy(result, s, i, i_s, pos - 1);
		i += pos - i_s;
		i_s = pos + strlen(s1);
		Copy(result, s2, i, 0, strlen(s2) - 1);
		i += strlen(s2);
		pos = Search(s, s1, i_s);
		if (pos == -1) {
			Copy(result, s, i, i_s, strlen(s) - 1);
		}
	}

	printf("%s\n", result);

	return result;
}

int main(int argc, char** argv) {
	size_t length = 99;
	char *s, *s1, *s2;

	
	s = (char*)malloc(sizeof(char) * length);
	s1 = (char*)malloc(sizeof(char) * length);
	s2 = (char*)malloc(sizeof(char) * length);

	fgets(s, length, stdin);
	fgets(s1, length, stdin);
	fgets(s2, length, stdin);

	RemoveNewLine(s);
	RemoveNewLine(s1);
	RemoveNewLine(s2);
	

	/*s = "111 11 111 1 2 111 11 1 111 1";
	s1 = "111";
	s2 = "x";*/

	s = Replace(s, s1, s2);

	printf("\nS \n%s\n", s);
	return 0;
}
