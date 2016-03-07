#include <stdio.h>
#include <stdlib.h>

int reverse(int x)
{
	int y;
	long int sum = 0;

	y = x < 0 ? -x : x;

	printf("The y is %d\n", y);

	while(y != 0)
	{
		sum *= 10;
		sum += y % 10;
		y /= 10;
	}

	if((y = sum) != sum)
		sum = 0;
	return ((x < 0) ? -sum : sum);
}

int main()
{
	int a = 1534236469;
	printf("The num is %d\n", reverse(a));
	return 0;
}
