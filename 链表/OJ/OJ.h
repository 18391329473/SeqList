#pragma once

// �Ƴ�����Ԫ��
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

// ��ת������
#if 0
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *newHead = NULL;
	struct ListNode *node;

	while (head != NULL) {
		// ��֮ǰ��������ͷɾ
		node = head;
		head = head->next;

		// ����������ͷ��
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
// ˫��������� -�� ����ָ�뷨
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

// ɾ���������ظ��Ľ��
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
			// 1. p2 �ߵ������β
			// 2. p2 ��������ȵ�ֵ��
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

#if 0             //ɾ���ظ��Ľڵ�  

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
			while (p2 != NULL && p2->val == p1->val)  //���������
			{
				p2 = p2->next;
			}
			// 1. p2 �ߵ������β
			// 2. p2 ��������ȵ�ֵ��
			if (p2 == NULL)    // ����Ľڵ㶼��Ҫɾ�ģ���p2�ڵ�ָ��NULL
			{
				if (p0 != NULL)    /
				{
					p0->next = p2;	// NULL   ����������һ����Ϊp0
				}
				else  //   p0ΪNULL�� ֱ�ӷ���null
				{
					return NULL;
				}
				break;
			}

			if (p0 != NULL)
			{
				p0->next = p2;
			}
			else    // p0����NULL
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
		struct ListNode *ratil = NULL;   //r��������һ�����
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
			ListNode *lt = NULL;   //��xС
			ListNode *ltTail = NULL;   //С�����һ�����
			ListNode *eq = NULL;   //��x��
			ListNode *eqTail = NULL;   //������һ�����
			ListNode *gt = NULL;   //��X��
			ListNode *gtTail = NULL;   //������һ�����


			ListNode *cur = pHead;
			while (cur != NULL)
			{
				if (cur->var < x)  //��һ����С��X
				{
					
					//lt �������Ϊ�գ�ô�ѽ��
					//lt ����Ϊ�գ� lt ����ָ���һ�����
					//ltTail ��Ϊ�գ�ָ�����һ�����
					if (lt == NULL)
					{
						//��һ���������cur�嵽�������������ֻ��һ�����
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
						//��һ���������cur�嵽�������������ֻ��һ�����
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
						//��һ���������cur�嵽�������������ֻ��һ�����
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