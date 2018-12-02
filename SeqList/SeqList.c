#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>




void SeqListInit(SeqList *sl, size_t capacity)   //��ʼ��˳���
{
	assert(sl != NULL);
	sl->capacity = capacity;      //��������ֵΪcapacity
	sl->size = 0;                 //��size��ֵΪ0
	sl->array = (SLDataType *)malloc(capacity *sizeof(SLDataType));
	assert(sl->array != NULL);
}

void SeqListDestroy(SeqList *sl)   // ����˳���
{
	assert(sl);
	free(sl->array);
	sl->array = NULL;        //�����ʹ���   ��ֹû���ͷ���ȫ
	sl->capacity = sl->size = 0;
}

void SeqListPrint(SeqList *sl)    //��ӡ˳���
{
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d", sl->array[i]);
	}
	printf("\n");
}

void CheckCapacity(SeqList *sl)   //����Ƿ���Ҫ����
{
	//����size��capacity��ֵ��ȣ�����Ҫ����
	if (sl->size < sl->capacity)
	{
		return;
	}
    //1. �����¿ռ�
	int newCapacity = sl->capacity * 2;
	SLDataType *newarray = (SLDataType*)malloc(newCapacity*sizeof(SLDataType));
	assert(newarray);
	//2. ���
	for (int i = 0; i < sl->size; i++)
	{
		newarray[i] = sl->array[i];
	}
	//3. �ͷžɵĿռ�
	free(sl->array);    //��ֹ�ڴ�й¶
	//4. �����µĿռ�
	sl->array = newarray;
	sl->capacity = newCapacity;
}

void SeqListPushBack(SeqList *sl, SLDataType data)   //β��
{
	assert(sl != NULL);
	CheckCapacity(sl);
	sl->array[sl->size] = data;
	sl->size++;
}

void SeqListPushFront(SeqList *sl, SLDataType data)   //ͷ��
{
	assert(sl != NULL);
	CheckCapacity(sl);
	for (int i = sl->size; i > 0; i--)   //��������������һλ���ƣ��ٽ��������һ��array��0����
	{
		sl->array[i] = sl->array[i - 1];
		
	}
	sl->array[0] = data;
	sl->size++;
}

void SeqListPopBack(SeqList *sl)    //βɾ (ֱ��ɾ�����һ��λ�ü���)
{
	assert(sl != NULL);
	assert(sl->size > 0);
	sl->size--;
}
void SeqListPopFront(SeqList *sl)   //ͷɾ (�ú���ĸ���סǰ�棬����һ���ռ伴�ɣ�
{
	assert(sl);
	assert(sl->size > 0);
	for (int i = 0; i < sl->size-1; i++)    
	{
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}

void SeqListInsert(SeqList *sl, size_t pos, SLDataType data)   // �� pos ���ڵ��±������ݲ���   ��pos��һ���±꣬�������ݣ�
{
	assert(sl);
	CheckCapacity(sl);
	assert(pos >= 0 && (int)pos <= sl->size);
	for (int i = sl->size-1; i >=(int) pos; i--)
	{
		sl->array[i+1] = sl->array[i];
	}
	sl->array[pos] = data;
	sl->size++;
}

void SeqListErase(SeqList *sl, size_t pos)  // ɾ�� pos ���ڵ��±�����
{
	assert(sl);
	assert(pos >= 0 && (int)pos < sl->size);
	for (int i = pos; i < sl->size-1; i++)
	{
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}

// ����
// �Ҵ� 0 ��ʼ�ĵ�һ�������֪���ˣ������������ڵ��±�
// ���û�ҵ����� -1
int SeqListFind(SeqList *sl, SLDataType data)
{
	assert(sl);
	for (int i = 0; i < sl->size; i++)
	{
		if (sl->array[i] == data)
		{
			return i;
		}
	}
	return -1;
}



void SeqListRemove(SeqList *sl, SLDataType data)     // ɾ����һ�������� data
{
	assert(sl);
	int pos = SeqListFind(sl, data);    //����˳������Ƿ���data
	if (pos != -1)                      
	{
		SeqListErase(sl,pos);
	}
}

void SeqListRemoveAll(SeqList *sl, SLDataType data)    // ɾ������������ data
{
	assert(sl);
	//int j = 0;
	//for (int i = 0; i < sl->size; i++)   //���´���һ�����飬��������data �������ȥ
	//{
	//	if (sl->array[i] != data)
	//	{
	//		sl->array[j++] = sl->array[i];
	//	}
	//}
	//sl->size = j;

	int pos;
	while ((pos = SeqListFind(sl, data)) != -1)   //  O(n)  ����˳������Ƿ���data�������
	{
		SeqListErase(sl, pos);    //O(n)
	}
}

void SeqListModify(SeqList *sl, size_t pos, SLDataType data)  // �޸ģ�pos ���ڵ��±�
{
	assert(sl);
	assert(pos >= 0 &&(int) pos < sl->size);
	sl->array[pos] = data;
}

static void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
} 

void SeqListBubbleSort(SeqList *sl)     //ð������  ��Ҫǿ��һ��
{
	assert(sl);
	
	for (int i = 0; i <sl->size-1; i++)
	{
		for (int j = 0; j <=sl->size-2-i; j++)
		{
			if (sl->array[j] > sl->array[j + 1])
			{
				swap(sl->array+j, sl->array+j + 1);
			}
		}
	}
}

// ���ֲ��ң�ǰ������������
// ����ҵ����������������±꣬���û�ҵ������� -1
int SeqListBinarySearch(SeqList *sl, SLDataType data)
{
	assert(sl);
	int left = 0;
	int right = sl->size - 1;	
	
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (data==sl->array[mid])
		{
			return mid;
		}
		if (data>sl->array[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	
	}
	return -1;
}