#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    int d = 1;

    if(x < 0)
        return false;

    while(x / d >= 10)
        d *= 10;

    while(x > 0)
    {
        if((x / d) != (x % 10))
        {
            return false;
        }
        x %= d;
        x /= 10;
        d /= 100;
    }
    return true;
}

int main()
{
    int a;
    scanf("%d", &a);
    if(isPalindrome(a))
        printf("True\n");
    else
        printf("False\n");
	return 0;
}
