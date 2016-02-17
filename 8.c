#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int myAtoi(char *str)
{
	int rsl = 0;
	int flag = 1;

	if(NULL == str)
		return 0;

	while(*str == ' ')
    {
        str++;
    }

	if(*str == '-')
    {
        flag = -1;
        str++;
    }
	else if(*str == '+')
    {
        flag = 1;
        str++;
    }

    while(*str >= '0' && *str <= '9')
    {
        if (rsl > INT_MAX / 10 ||
            (rsl == INT_MAX / 10 &&
            (*str - '0') > INT_MAX % 10))
        {
            return flag == -1 ? INT_MIN : INT_MAX;
        }

        rsl *= 10;
        rsl += *str - '0';
        if(rsl > INT_MAX)
        {
            break;
        }

        str++;
    }
	return rsl * flag;
}

int main()
{
	char *s = "9223372036854775809";
	printf("%d\n", myAtoi(s));
	return 0;
}
