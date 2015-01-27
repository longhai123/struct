/*************************************************************************
	> File Name: reverse.c
	> Author: longhai
	> Mail: longhai@126.com 
	> Created Time: Tue Jan 27 15:57:05 2015
	> 顺序表的就地逆置
 ************************************************************************/

#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

void Reverse_SqList(SqList *L)
{
	int i,j,n,t;
	n = L->length;
	if (n == 0 || n == 1)	return;
	i = 0;
	j = n - 1;
	while (i < j)
	{
		t = L->data[i];
		L->data[i] = L->data[j];
		L->data[j] = t;
		i++;
		j--;
	}
}
void Create_SqList(SqList *L, int n)
{
	int i;
	L->length = n;
	i = 0;
	printf("\ninput %d data:" , n);
	while (i < n)
	{
		scanf("%d", &L->data[i]);
		i++;
	}
}
void Print_SqList(SqList *L)
{
	int i, n;
	n = L->length;
	i = 0;
	printf("\noutput %d data:", n);
	while (i < n)
	{
		printf("%d ", L->data[i]);
		i++;
	}
}

int main(void)
{
	SqList L;
	int n;
	printf("\ninput n:");
	scanf("%d", &n);
	Create_SqList(&L, n);
	Print_SqList(&L);
	Reverse_SqList(&L);
	Print_SqList(&L);
}
