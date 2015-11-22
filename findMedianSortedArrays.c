#include <stdio.h>
#include <stdlib.h>

double findKth(int *nums1, int m, int *nums2, int n, int k);
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);

int main()
{
	int nums1[] = {1, 2, 5, 8, 9};
	int nums2[] = {2, 4, 5, 6, 7, 12};
	int i, j;
	int m = sizeof(nums1) / sizeof(nums1[0]);
	int n = sizeof(nums2) / sizeof(nums2[0]);

	printf("%f\n", findMedianSortedArrays(nums1, m, nums2, n));
	return 0;
}

double findKth(int *nums1, int m, int *nums2, int n, int k)
{
	if(m > n)
	{
		return findKth(nums2, n, nums1, m, k);
	}
	if(m == 0)
		return nums2[k - 1];
	if(k == 1)
	{
		return nums2[0] > nums1[0] ? nums1[0] : nums2[0];
	}
	
	int ia = k / 2 < m ? k / 2 : m;
	int ib = k - ia;
	if(nums1[ia - 1] < nums2[ib - 1])
		return findKth(nums1 + ia, m - ia, nums2, n, k - ia);
	else if(nums1[ia - 1] > nums2[ib - 1])
		return findKth(nums1, m, nums2 + ib, n - ib, k - ib);
	else
		return nums1[ia - 1];
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int total = nums1Size + nums2Size;
	if(total & 0x1)
	{
		return findKth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
	}
	else
	{
		return (findKth(nums1, nums1Size, nums2, nums2Size, total / 2) 
			  + findKth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1)) / 2.0;
	}
}
