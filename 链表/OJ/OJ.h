#pragma once

// 移除链表元素
#if 0
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL) {
		return NULL;
	}

	struct ListNode *prev = head;
	struct ListNode *cur = head->next;

	while (cur != NULL) {
		if (cur->val != val) {
			prev = cur;
		}
		else {
			prev->next = cur->next;
			free(cur);
		}
		cur = prev->next;
	}

	struct ListNode *newHead = head;
	if (head->val == val) {
		newHead = head->next;
		free(head);
	}

	return newHead;
}
#endif

// 反转单链表
#if 0
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *newHead = NULL;
	struct ListNode *node;

	while (head != NULL) {
		// 对之前的链表做头删
		node = head;
		head = head->next;

		// 对新链表做头插
		node->next = newHead;
		newHead = node;
	}

	return newHead;
}
#endif

#if 0
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL) {
		return NULL;
	}

	struct ListNode *p0 = NULL;
	struct ListNode *p1 = head;
	struct ListNode *p2 = head->next;

	while (p1 != NULL) {
		p1->next = p0;

		p0 = p1;
		p1 = p2;
		if (p2 != NULL) {
			p2 = p2->next;
		}
	}

	return p0;
}
#endif

#if 0
int GetLength(struct ListNode *head) {
	int len = 0;
	struct ListNode *cur = head;
	while (cur != NULL) {
		len++;
		cur = cur->next;
	}

	return len;
}

struct ListNode* middleNode(struct ListNode* head) {
	int steps = GetLength(head) / 2;
	struct ListNode *middle = head;
	while (steps--) {
		middle = middle->next;
	}

	return middle;
}
#endif

#if 0
// 双链表遍历法 -》 快慢指针法
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	while (fast != NULL) {
		fast = fast->next;
		if (fast == NULL) {
			break;
		}

		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}
#endif

#if 0
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode *p = pListHead;
	while (p != NULL && k--) {
		p = p->next;
	}

	if (p == NULL) {
		return NULL;
	}

	while (p != NULL) {
		pListHead = pListHead->next;
		p = p->next;
	}

	return pListHead;
}
#endif

// 删除链表中重复的结点
#if 0

ListNode * deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}

	ListNode *p0 = NULL;
	ListNode *p1 = pHead;
	ListNode *p2 = pHead->next;

	while (p2 != NULL) {
		if (p1->val != p2->val) {
			p0 = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else {
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}
			// 1. p2 走到链表结尾
			// 2. p2 遇到不相等的值了
			if (p2 == NULL) {
				if (p0 != NULL) {
					p0->next = p2;	// NULL
				}
				else {
					return NULL;
				}
				break;
			}

			if (p0 != NULL) {
				p0->next = p2;
			}
			else {
				pHead = p2;
			}
			p1 = p2;
			p2 = p2->next;
		}
	}

	return pHead;
}

#endif

#if 0             //删除重复的节点  

ListNode * deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}

	ListNode *p0 = NULL;
	ListNode *p1 = pHead;
	ListNode *p2 = pHead->next;

	while (p2 != NULL)
	{
		if (p1->val != p2->val)
		{
			p0 = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else
		{
			while (p2 != NULL && p2->val == p1->val)  //两个数相等
			{
				p2 = p2->next;
			}
			// 1. p2 走到链表结尾
			// 2. p2 遇到不相等的值了
			if (p2 == NULL)    // 后面的节点都是要删的，故p2节点指向NULL
			{
				if (p0 != NULL)    /
				{
					p0->next = p2;	// NULL   此类情况最后一个数为p0
				}
				else  //   p0为NULL， 直接返回null
				{
					return NULL;
				}
				break;
			}

			if (p0 != NULL)
			{
				p0->next = p2;
			}
			else    // p0等于NULL
			{
				pHead = p2;
			}
			p1 = p2;
			p2 = p2->next;
		}
	}

	return pHead;
}

#endif


#if 0

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
		struct ListNode *r = NULL;
		struct ListNode *p1 = l1;
		struct ListNode *p2 = l2;
		struct ListNode *ratil = NULL;   //r链表的最后一个结点
		while (p1 != NULL&&p2 != NULL)
		{
			if (p1->val <= p2->val)
			{
				if (rtail == NULL)
				{
					r = rtail = p1;
				}
				else
				{
					rtail->next = p1;
					rtail = rtail->next;
				}
				p1 = p1->next;
			}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
			else
			{

					if (rtail == NULL)
					{
						r = rtail = p2;
				    }
					else
					{
						rtail->next = p2;
						rtail = rtail->next;
					}
					p2 = 2->next;
			}
	}

#endif


#if 0


		ListNode* partition(ListNode* pHead, int x)
		{
			ListNode *lt = NULL;   //比x小
			ListNode *ltTail = NULL;   //小的最后一个结点
			ListNode *eq = NULL;   //比x大
			ListNode *eqTail = NULL;   //相等最后一个结点
			ListNode *gt = NULL;   //比X大
			ListNode *gtTail = NULL;   //大的最后一个结点


			ListNode *cur = pHead;
			while (cur != NULL)
			{
				if (cur->var < x)  //第一个数小于X
				{
					
					//lt 这个链表为空，么友结点
					//lt 链表不为空， lt 并且指向第一个结点
					//ltTail 不为空，指向最后一个结点
					if (lt == NULL)
					{
						//第一种情况，把cur插到空链表里，链表里只有一个结点
						lt = ltTail = cur;
					}
					else
					{
						ltTail->next = cur;
						ltTail = ltTail->next;
					}
				}
				else if (cur->var == x)
				{
					if (eq == NULL)
					{
						//第一种情况，把cur插到空链表里，链表里只有一个结点
						eq = eqTail = cur;
					}
					else
					{
						eqTail->next = cur;
						eqTail = eqTail->next;
					}
				}
				else
				{
					if (gt == NULL)
					{
						//第一种情况，把cur插到空链表里，链表里只有一个结点
						gt = ltTail = cur;
					}
					else
					{
						gtTail->next = cur;
						gtTail = gtTail->next;
					}
				}
			}
		}
#endif

		ret != NULL;
		retTail != NULL;

		cur = head;
		while (cur)
		{
			if (cur == NULL)
			{
				retail->next = NULL;
			}
			else
			{
				retTail->next = cur;
				cur = cur->next;
				reTail = retTail->next;
			}
		}