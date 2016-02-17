#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows)
{
    char *rsl = NULL;
    int length = 0;
    int i,j;
    int count = 0;
    int index;

    if(NULL == s || numRows <= 1)
        return s;

    length = strlen(s);
    rsl = malloc(length + 1);
    if(rsl == NULL)
        return NULL;

    for (i = 0; i < numRows; i++)
    {
        for (j = 0, index = i; index < length;
            j++, index = (2 * numRows - 2) * j + i)
        {
            rsl[count++] = s[index]; // 垂直元素
            if (i == 0 || i == numRows - 1)
                continue; // 斜对角元素
            if (index + (numRows - i - 1) * 2 < length)
                rsl[count++] = s[index + (numRows - i - 1) * 2];
        }
    }
    rsl[count] = '\0';
    return rsl;
}

int main()
{
    printf("%s\n", convert("PAYPALISHIRING", 3));
	return 0;
}
