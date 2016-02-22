#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target) 
{
	int left = 0;
	int right = numsSize - 1;
	int mid;

	if(NULL == nums || numsSize <= 0)
		return -1;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(nums[mid] == target)
			return mid;
		if(nums[left] <= nums[mid])
		{
			if(nums[left] <= target && target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		else
		{
			if(nums[mid] < target && target <= nums[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return -1;
    
}

int main()
{
	return 0;
}
