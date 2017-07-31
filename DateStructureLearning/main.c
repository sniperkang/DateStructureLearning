#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

typedef int Status;
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length==0 || i<1 || i>L.length)
        return ERROR;
    *e =  L.data[i-1];
    return OK;
}

int ListLength(SqList L)
{
    return L.length;
}

int LocateElem(SqList L, ElemType e)
{
    int i;
    for(i=1; i<=L.length; i++)
    {
        ElemType *eTemp = NULL;
        if(GetElem(L, i, eTemp))
        {
            if(e == *eTemp)
                return i;
        }
        else
            printf ("Error!\n");
    }
    //abnomal return value
    return L.length+1;
}

//better one
int LocateElem1(SqList L, ElemType e)
{
    int i;
    for(i=1; i<=L.length; i++)
    {
        if(e == L.data[i])
            return i;
    }
    //abnomal return value
    return L.length+1;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if(L->length == MAXSIZE)
        return ERROR;
    if(i<1 || i>L->length+1)
        return ERROR;
    if(i <= L->length)
    {
        for(k=L->length-1; k>=i-1; k--)
            L->data[k+1] = L->data[k];
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;
    if(L->length == 0)
        return ERROR;
    if(i<1 || i>L->length)
        return ERROR;
    *e = L->data[i-1];
    if(i<L->length)
    {
        for(k=i; k<L->length; k++)
            L->data[k-1] = L->data[k];
    }
    L->length--;
    return OK;
}

void unionL(SqList *La, SqList Lb)
{
    int La_len, Lb_len, i;
    ElemType e;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    for(i=1; i<=Lb_len; i++)
    {
        GetElem(Lb, i, &e);
        if(!LocateElem(*La, e))
            ListInsert(La, ++La_len, e);
    }
}

int main(void)
{
    printf("Hello World!\n");
    return 0;
}
//change
