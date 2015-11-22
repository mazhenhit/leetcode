#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* preProcess(char *s)
{
	int i;
	int j = 0;
	int length;
	char* ret = NULL;

	length = strlen(s);

	if(length == 0)
		return "^$";

	ret = (char *)malloc(length + 2);
	if(ret == NULL)
	{
		printf("ret is NULL.....\n");
		return NULL;
	}

	for(i = 0; i < length; i++)
	{
		ret[j++] = '#';
		ret[j++] = s[i];
	}
	ret[j++] = '#';
	ret[j] = '\0';
	return ret;
}

char* longestPalindrome(char *s)
{
	char *T = NULL;
	int n;
	char *P = NULL;
	int C = 0;
	int R = 0;
	int i;
	int i_m;
	int max_len = 0; 
	int center_index = 0;
	int start = 0;

	T = preProcess(s);
	printf("T is %s\n", T);
	n = strlen(T);
	P = (char *)malloc(sizeof(char) * n);

	for(i = 1; i < n - 1; i++)
	{
		i_m = 2 * C - i;
		P[i] = (R > i) ? (R-i < P[i_m] ? R - i : P[i_m]) : 0;

		while(T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;

		if(i + P[i] > R)
		{
			C = i;
			R = i + P[i];
		}
	}


	for(i = 1; i < n - 1; i++)
	{
		if(P[i] > max_len)
		{
			max_len = P[i];
			center_index = i;
		}
	}

	start = (center_index - 1 - max_len) / 2;
	s[start + max_len] = '\0';
	return s + start;
}

int main()
{
	char *s = "Helloabccbadefg";

	printf("%s\n", s);
	printf("%s\n", preProcess(s));
	printf("%s\n", longestPalindrome(s));
	return 0;
}
