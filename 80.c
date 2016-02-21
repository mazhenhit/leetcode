#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) 
{
	int i = 2;
	int index = 2;

	if(NULL == nums || numsSize <= 0)
		return 0;
	if(numsSize <= 2)
		return numsSize;

	while(i < numsSize)
	{
		if(nums[i] != nums[index - 2])
			nums[index++] = nums[i];
	}

	return index;
}

int main()
{
	int nums[] = [1, 1, 1, 2, 2, 3];
	printf("%d\n", removeDuplicates(nums, 6));
	return 0;
}

