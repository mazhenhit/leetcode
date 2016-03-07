#include <stdlib.h>
#include <stdio.h>

#define PRIME 217

typedef struct list
{
	int index;
	struct list * pNext;
}list;

typedef list * listNode;

int *twoSum(int *nums, int numsSize, int target);

int main()
{
	int a[] = {0,4,3,0};
	int target = 0;

	int *p = twoSum(a, sizeof(a)/sizeof(a[0]), target);
	if(p != NULL)
		printf("%d %d\n", p[0], p[1]);
	
	free(p);
	return 0;
}

void hashMapFree(listNode hashTable, int primeNumber)
{
    int i = 0;
    for (i = 0; i < primeNumber; i++)
    {
        listNode tail = hashTable[i].pNext;
        while(NULL != tail)
        {
            listNode tmp = tail;
            tail = tail->pNext;
            free(tmp);
        }
    }
    free(hashTable);
}

int *twoSum(int *nums, int numsSize, int target)
{
	int i = 0, bias;
	int *p = (int *)malloc(2 * sizeof(int));
	int primeValue = PRIME;
	listNode hashMap = (listNode)malloc(sizeof(list) * primeValue);
	
	for(i = 0; i < primeValue; i++)
	{
		hashMap[i].index = -1;
		hashMap[i].pNext = NULL;
	}
	
	for(i = 0; i < numsSize; i++)
	{
		bias = abs(nums[i] % primeValue);
		if(hashMap[bias].index == -1)
		{
			hashMap[bias].index = i;
		}
		else
		{
			listNode tail = (listNode)malloc(sizeof(list));
			tail->index = i;
			tail->pNext = hashMap[bias].pNext;
			hashMap[bias].pNext = tail;
		}
	}
	
	for(i = 0; i < numsSize; i++)
	{
		bias = abs((target - nums[i]) % primeValue);
		if(hashMap[bias].index == -1)
			continue;
		else if(nums[hashMap[bias].index] == target - nums[i] && hashMap[bias].index != i)
		{
			p[0] = i + 1;
			p[1] = hashMap[bias].index + 1;
			hashMapFree(hashMap, primeValue);
			return p;
		}
		else
		{
			listNode pNode = hashMap[bias].pNext;
			while(pNode != NULL)
			{
				if(nums[pNode->index] + nums[i] == target)
				{
					p[0] = i + 1;
					p[1] = pNode->index + 1;
					hashMapFree(hashMap, primeValue);
					return p;
				}
				else
					pNode = pNode->pNext;
			}
		}
	}
	hashMapFree(hashMap, primeValue);
	return p;
}
