#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char *s)
{
	char *d = NULL;
	char *rsl = NULL;
	int *p = NULL;
	int length = 0;
	int newLen = 0;
	int i = 0;
	int j = 0;
	int C = 0;
	int R = 0;
	int im = 0;
	int maxLen = 0;
	int center = 0;
	int start = 0;

	length = strlen(s);
	newLen = 2 * length + 2;
	d = (char *)malloc(sizeof(char) * newLen);
	if(d == NULL)
	{
		printf("d is NULL...");
		return NULL;
	}
	for(i = 0; i < length; i++)
	{
		d[j++] = '#';
		d[j++] = s[i];
	}
	d[j++] = '#';
	d[j] = '\0';

	p = (int *)malloc(sizeof(int) * newLen);
	if(p == NULL)
	{
		printf("The p is NULL!\n");
		return NULL;
	}

	for(i = 1; i < newLen - 1; i++)
	{
		im = 2 * C - i;
		if(im > 0 && i + p[im] <= R)
			p[i] = p[im];
		else
			p[i] = 0;

		while(d[i + 1 + p[i]] == d[i - 1 - p[i]] && i - 1 - p[i] >= 0) 
			p[i]++;

		if(i + p[i] > R)
		{
			C = i;
			R = i + p[i];
		}
	}

	free(d);

	for(i = 1; i < newLen - 1;i++)
	{
		if(p[i] > maxLen)
		{
			maxLen = p[i];
			center = i;
		}
	}

	free(p);

	start = center - maxLen > 0 ? (center - maxLen) / 2 : (maxLen - center) / 2;
	rsl = (char *)malloc(sizeof(char) * maxLen);
	if(rsl == NULL)
	{
		printf("rsl is NULL......\n");
		return NULL;
	}
	for(i = 0; i < maxLen; i++)
	{
		rsl[i] = s[i + start];
	}
	rsl[maxLen] = '\0';
	return rsl;
}

int main()
{
	char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char *d = NULL;
	d = longestPalindrome(s);
	if(d != NULL)
		printf("%s\n", d);
	return 0;
}

