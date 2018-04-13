#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Insert(char s[],char s2[],int loc,int length)
{
	if (strlen(s2)<length)
	{
		for (int i=loc+strlen(s2);i<strlen(s)-(length-strlen(s2));i++) 
		{
			s[i]=s[i+(length-strlen(s2))];	
		}
		s[strlen(s)-(length-strlen(s2))]='\0';
		for (int i=loc;i<loc+strlen(s2);i++) s[i]=s2[i-loc];
	}
	else
	{	
		for (int i=strlen(s)-1;i>=loc+length;i--) 
		{
			s[i+(strlen(s2))-length]=s[i];
		}
		s[strlen(s)+(strlen(s2)-length)]='\0';
		for (int i=loc;i<loc+strlen(s2);i++) s[i]=s2[i-loc];
	}
}

void RemoveNewLine(char s[]){
	if (s && s[strlen(s) - 1] == '\n') {
		s[strlen(s) - 1] = '\0';
	}
}

int SearchFrom(const char s[], const char s1[], const size_t start) {
	for (size_t i = 0, j = start; i < strlen(s1); ++i, ++j) {
		if (s1[i] != '\n' && s1[i] != s[j]) {
			return -1;
		}
	}
	return start;
}

int Search(const char s[], const char s1[]) {
	for (size_t i = 0; i < strlen(s) - strlen(s1) + 1; ++i) {
		int result = SearchFrom(s, s1, i);
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
	size_t count = 0;
	for (size_t i = 0; i < strlen(s) - strlen(s1) + 1; ++i) {
		if (SearchFrom(s, s1, i)) {
			++count;
		}
	}

	char *result = (char*)malloc(sizeof(char) * (strlen(s) + count * (strlen(s2) - strlen(s1))));
	Copy(result, s, 0, 0, strlen(s) - 1);
	printf("\nR - S %s - %s\n", result, s);

	result[strlen(s) + count * (strlen(s2) - strlen(s1))] = '\0';

	for (int i_s = 0, pos = SearchFrom(s, s1, i_s), i = 0; pos >= 0; pos = SearchFrom(s, s1, i_s)) {
		printf("\nResult %s %d %d %d\n", result, i, i_s, pos);
		Copy(result, s, i, i_s, pos - 1);
		i += pos;
		i_s = pos + strlen(s1) - 1;
		Copy(result, s2, i, 0, strlen(s2) - 1);
		i += strlen(s2) - 1;
		
	}

	printf("%s\n", result);
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

	s = Replace(s, s1, s2);

	printf("\nS = %s \n",s);
	return 0;
}
