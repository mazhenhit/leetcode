#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize)
{
    int index = 0;
    int i;
    if (numsSize == 0)
        return 0;

    for (i = 1; i < numsSize; i++)
    {
        if (nums[index] != nums[i])
            nums[++index] = nums[i];
    }
    return index + 1;
}

int main()
{

	return 0;
}
