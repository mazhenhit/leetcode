#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s)
{
	int i;
	int max = 0;
	int start = 0;
	int loc[256];
	int len = strlen(s);
	
	for(i = 0; i < 256; i++)
	{
		loc[i] = -1;
	}

	for(i = 0; i < len; i++)
	{
		if(loc[s[i]] >= start)
		{
			max = i - start > max ? i - start : max;
			start = loc[s[i]] + 1;
		}
		loc[s[i]] = i;
	}
	return len - start > max ? len - start : max;
}

int main()
{
	char *s = "bwf";
	printf("%d\n", lengthOfLongestSubstring(s));
	return 0;
}
