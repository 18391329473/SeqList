#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>




void SeqListInit(SeqList *sl, size_t capacity)   //初始化顺序表
{
	assert(sl != NULL);
	sl->capacity = capacity;      //给容量赋值为capacity
	sl->size = 0;                 //给size赋值为0
	sl->array = (SLDataType *)malloc(capacity *sizeof(SLDataType));
	assert(sl->array != NULL);
}

void SeqListDestroy(SeqList *sl)   // 销毁顺序表
{
	assert(sl);
	free(sl->array);
	sl->array = NULL;        //防御型代码   防止没有释放完全
	sl->capacity = sl->size = 0;
}

void SeqListPrint(SeqList *sl)    //打印顺序表
{
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d", sl->array[i]);
	}
	printf("\n");
}

void CheckCapacity(SeqList *sl)   //检测是否需要扩容
{
	//加入size和capacity的值相等，则不需要扩容
	if (sl->size < sl->capacity)
	{
		return;
	}
    //1. 申请新空间
	int newCapacity = sl->capacity * 2;
	SLDataType *newarray = (SLDataType*)malloc(newCapacity*sizeof(SLDataType));
	assert(newarray);
	//2. 搬家
	for (int i = 0; i < sl->size; i++)
	{
		newarray[i] = sl->array[i];
	}
	//3. 释放旧的空间
	free(sl->array);    //防止内存泄露
	//4. 保存新的空间
	sl->array = newarray;
	sl->capacity = newCapacity;
}

void SeqListPushBack(SeqList *sl, SLDataType data)   //尾插
{
	assert(sl != NULL);
	CheckCapacity(sl);
	sl->array[sl->size] = data;
	sl->size++;
}

void SeqListPushFront(SeqList *sl, SLDataType data)   //头插
{
	assert(sl != NULL);
	CheckCapacity(sl);
	for (int i = sl->size; i > 0; i--)   //将所有数据往后一位搬移，再将数插给第一个array【0】；
	{
		sl->array[i] = sl->array[i - 1];
		
	}
	sl->array[0] = data;
	sl->size++;
}

void SeqListPopBack(SeqList *sl)    //尾删 (直接删掉最后一个位置即可)
{
	assert(sl != NULL);
	assert(sl->size > 0);
	sl->size--;
}
void SeqListPopFront(SeqList *sl)   //头删 (让后面的覆盖住前面，减掉一个空间即可）
{
	assert(sl);
	assert(sl->size > 0);
	for (int i = 0; i < sl->size-1; i++)    
	{
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}

void SeqListInsert(SeqList *sl, size_t pos, SLDataType data)   // 在 pos 所在的下标做数据插入   （pos是一个下标，不是数据）
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

void SeqListErase(SeqList *sl, size_t pos)  // 删除 pos 所在的下标数据
{
	assert(sl);
	assert(pos >= 0 && (int)pos < sl->size);
	for (int i = pos; i < sl->size-1; i++)
	{
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}

// 查找
// 找从 0 开始的第一个，如果知道了，返回数据所在的下标
// 如果没找到返回 -1
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



void SeqListRemove(SeqList *sl, SLDataType data)     // 删除第一个遇到的 data
{
	assert(sl);
	int pos = SeqListFind(sl, data);    //查找顺序表中是否含有data
	if (pos != -1)                      
	{
		SeqListErase(sl,pos);
	}
}

void SeqListRemoveAll(SeqList *sl, SLDataType data)    // 删除所有遇到的 data
{
	assert(sl);
	//int j = 0;
	//for (int i = 0; i < sl->size; i++)   //重新创建一个数组，将不等于data 的数存进去
	//{
	//	if (sl->array[i] != data)
	//	{
	//		sl->array[j++] = sl->array[i];
	//	}
	//}
	//sl->size = j;

	int pos;
	while ((pos = SeqListFind(sl, data)) != -1)   //  O(n)  查找顺序表中是否含有data这个数据
	{
		SeqListErase(sl, pos);    //O(n)
	}
}

void SeqListModify(SeqList *sl, size_t pos, SLDataType data)  // 修改，pos 所在的下标
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

void SeqListBubbleSort(SeqList *sl)     //冒泡排序  需要强化一下
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

// 二分查找（前提是数据有序）
// 如果找到，返回数据所在下标，如果没找到，返回 -1
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