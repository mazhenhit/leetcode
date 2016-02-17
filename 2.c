#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int tmp = 0;
	int t1, t2;
	int carry = 0; 
    struct ListNode* l3 = NULL;
	struct ListNode* tail = l3;
	while(l1 != NULL || l2 != NULL)
	{
		struct ListNode* pNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		t1 = 0;
		t2 = 0;
		if(l1 != NULL)
		{
			t1 = l1->val;
			l1 = l1->next;
		}
		if(l2 != NULL)
		{
			t2 = l2->val;
			l2 = l2->next;
		}
		tmp = t1 + t2 + carry;
		pNode->val = tmp % 10;
		carry = tmp / 10;
		pNode->next = NULL;
		if(l3 == NULL)
		{
			l3 = pNode;
			tail = l3;
		}
		else
		{
			tail->next = pNode;
			tail = pNode;
		}
	}

	if(carry)
	{
		struct ListNode* pNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		pNode->val = 1;
		pNode->next = NULL;
		tail->next = pNode;
	}
	return l3;
}

int main()
{
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;
	struct ListNode* l3 = NULL;
	struct ListNode* cur = NULL;

	int a[] = {1, 9, 2, 9, 4, 4, 1, 0, 3};
	int b[] = {2, 3, 0, 1, 0, 6, 9, 2, 0, 1};

	int len1 = sizeof(a) / sizeof(a[0]);
	int len2 = sizeof(b) / sizeof(b[0]);

	int i = 0;
	while(i < len1)
	{
		struct ListNode* pNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		pNode->val = a[i];
		pNode->next = NULL;
		if(l1 == NULL)
		{
			l1 = pNode;
			cur = l1;
		}
		else
		{
			cur->next = pNode;
			cur = pNode;
		}
		i++;
	}

	i = 0;

	while(i < len2)
	{
		struct ListNode* pNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		pNode->val = b[i];
		pNode->next = NULL;
		if(l2 == NULL)
		{
			l2 = pNode;
			cur = l2;
		}
		else
		{
			cur->next = pNode;
			cur = pNode;
		}
		i++;
	}
	
	cur = l1;
	while(cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");

	cur = l2;
	while(cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");

	l3 = addTwoNumbers(l1, l2);
	cur = l3;
	while(cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");

	cur = l3;
	while(cur != NULL)
	{
		l3 = cur;
		cur = cur->next;
		free(l3);
	}
	cur = l1;
	while(cur != NULL)
	{
		l1 = cur;
		cur = cur->next;
		free(l1);
	}
	cur = l2;
	while(cur != NULL)
	{
		l2 = cur;
		cur = cur->next;
		free(l2);
	}
	return 0;
}
