#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
#include<stdlib.h>


void TestSeqList()
{
	SeqList seqList;  //����һ��SeqList���͵ı���
	SeqListInit(&seqList, 10);
//	SeqListPrint(&seqList);
	SeqListPushBack(&seqList, 5);
//	SeqListPushBack(&seqList, 4);
//	SeqListPushBack(&seqList, 4);
	SeqListPushBack(&seqList, 4);
//	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 3);
	SeqListPushFront(&seqList, 1);
//    SeqListPopBack(&seqList);
//	SeqListPopFront(&seqList);
//	SeqListInsert(&seqList, 1, 9);   //���±�Ϊ1�Ŀռ����9
//	SeqListErase(&seqList, 1);       //ɾ���±�Ϊ1������
//	int ret=SeqListFind(&seqList,3);
//	printf("%d\n", ret);
//	SeqListRemove(&seqList, 4);
//	SeqListRemoveAll(&seqList, 4);
//	SeqListModify(&seqList, 0, 4);//���±�Ϊ0�����ݸ�Ϊ4
	SeqListBubbleSort(&seqList);
	
	int ret= SeqListBinarySearch(&seqList, 1);
	printf("%d\n", ret);

	SeqListPrint(&seqList);

}
int main()
{
	TestSeqList();
	system("pause");
	return 0;
}