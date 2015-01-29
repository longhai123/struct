/*************************************************************************
	> File Name: reverse.c
	> Author: longhai
	> Mail: longhai@126.com 
	> Created Time: Tue Jan 27 15:57:05 2015
	> delete the repeated record in a linear list
 ************************************************************************/

#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

void Delrpt_SqList(SqList *L)
{
	int i,j,k;
	int n = L->length;
 	int count=0;
	ElemType t;
	for (i = 0; i < n; i++)
	{
		t = L->data[i];
		for (j = i + 1; j < n; j++)
		{
			if (L->data[j] == t) count++;
			else	break;
		}
		if (count != 0)
		{
			for (k = j; k < n; k++)
			{
				L->data[k-count] = L->data[k];
			}
			n = n - count;
			count = 0;
		}
		L->length = n;
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
	Delrpt_SqList(&L);
	Print_SqList(&L);
}
