#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p)
{
    if (*p == '\0')
        return *s == '\0';

    if (*(p + 1) != '*')
    {
        if (*p == *s || (*p == '.' && *s != '\0'))
            return isMatch(s + 1, p + 1);
        else
            return false;
    }
    else
    {
        while (*p == *s || (*p == '.' && *s != '\0'))
        {
            if (isMatch(s, p + 2))
                return true;
            s++;
        }
        return isMatch(s, p + 2);
    }
}

int main()
{
    char *s = "abc";
    char *p = ".*";
    if(isMatch(s, p))
        printf("True\n");
    else
        printf("False\n");
	return 0;
}
