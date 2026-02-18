// Doubly Circular linked list

// InsertFirst
// InsertLast
// InsertAtPosition
// DeleteFirst
// DeleteLast
// DeleteAtPosition
// Display
// Count

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next; 
    struct node *prev; 
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        newn->prev = *last;
        newn->next->prev = newn;
        *first = newn;
    }
    (*last)->next = *first;
    (*first)->prev = *last;
}

void InsertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->prev = *last;
        (*last)->next = newn;
        *last  = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
    
}

void DeleteFirst(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;
    
    if((*first == NULL) && (*last == NULL))
    {
        return;
    }
    else if(*first == *last)
    { 
        free(*first);              
        
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
        (*last)->next = *first;
        (*first)->prev = *last;
    }    

}

void DeleteLast(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;
    
    if((*first == NULL) && (*last == NULL))
    {
        return;
    }
    else if(*first == *last)
    { 
        free(*first);        
        
        *first = NULL;
        *last = NULL;
        
    }
    else
    {    temp = *last;
        *last = (*last)->prev;

        free(temp);

        (*last)->next = *first;
    (*first)->prev = *last;
    }
    
}


void Display(PNODE first,PNODE last)
{
    do
    {
        printf("| %d |<=>",first->data);
        first = first->next;
        
    }while(first != last->next);

    printf("\n");

}


int Count(PNODE first,PNODE last)
{
    int iCount = 0;

    do
    {
        iCount++;
        first = first->next;
        
    }while(first != last->next);

    return iCount;
}

void InsertAtPos(PPNODE first,PPNODE last,int no,int pos)
{
    int iSize = 0;
    int iCnt = 0;
    
    PNODE temp = NULL;
    PNODE newn = NULL;

    iSize = Count(*first,*last);

    if(pos < 1 || pos > (iSize + 1))
    {
        printf("Invalid Position");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == (iSize + 1))
    {
        InsertLast(first,last,no);
    }
    else
    {

        temp = *first;
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;
        newn->next->prev = newn;

    }   

}

void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{
    int iSize = 0;
    int iCnt = 0;
    
    PNODE temp = NULL;
    PNODE target = NULL;

    iSize = Count(*first,*last);

    if(pos < 1 || pos > iSize)
    {
        printf("Invalid Position\n");
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iSize)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        free(target);
    }
}

int main()
{
    int iRet = 0;
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head,&tail,30);
    InsertFirst(&head,&tail,20);
    InsertFirst(&head,&tail,10);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total number of nodes are : %d\n",iRet);

    InsertLast(&head,&tail,40);
    InsertLast(&head,&tail,50);
    InsertLast(&head,&tail,60);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total number of nodes are : %d\n",iRet);

    DeleteFirst(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total number of nodes are : %d\n",iRet);

    DeleteLast(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total number of nodes are : %d\n",iRet);

    InsertAtPos(&head,&tail,45,4);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total number of nodes are : %d\n",iRet);

    DeleteAtPos(&head,&tail,4);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total number of nodes are : %d\n",iRet);
    
    return 0;
}