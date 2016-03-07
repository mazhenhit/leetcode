#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize) 
{
	int start = 0;
	int end = heightSize - 1;
	int area = 0;
	int rsl = 0;

	if(NULL == height || heightSize <= 1)
		return 0;

	while(start < end)
	{
		area = (height[start] > height[end] ? height[end] : height[start])
			* (end - start);
		rsl = rsl > area ? rsl : area;
		if(height[start] >= height[end])
			end--;
		else
			start++;
	}
	return rsl;
}

int main()
{
	return 0;
}

