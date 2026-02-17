// Singly linear linked list

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
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = no;
    newn->next = NULL;
    
    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    
}


void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);             
    }
}


void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;        
    }
}


void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");

}

int Count(PNODE first)
{
    int iCount = 0;
    while(first != NULL)
    {
        iCount++;        
        first = first->next;
    }

    return iCount;

}

void InsertAtPos(PPNODE first,int no,int pos)
{
    int iCnt = 0;
    int iSize = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iSize = Count(*first);

    if((pos < 1) || (pos > iSize+1))
    {
        printf("Invalid Position");
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(first,no);
    }
    else
    {
        temp = *first;

        newn = (PNODE)malloc(sizeof(PNODE));
        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE first,int pos)
{ 
    int iCnt = 0;
    int iSize = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iSize = Count(*first);

    if((pos < 1) || (pos > iSize))
    {
        printf("Invalid Position");
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next  = target->next;

        free(target);
    }
}



int main()
{
    int iRet = 0;
    PNODE head = NULL;

    InsertFirst(&head,60);
    InsertFirst(&head,50);
    InsertFirst(&head,40);

    Display(head);
    iRet = Count(head);
    printf("Total Numbers of nodes are : %d\n",iRet);   
    
    InsertFirst(&head,30);
    InsertFirst(&head,20);
    InsertFirst(&head,10);
    
    Display(head);
    iRet = Count(head);
    printf("Total Numbers of nodes are : %d\n",iRet);   
    
    DeleteFirst(&head);
    Display(head);
    iRet = Count(head);
    printf("Total Numbers of nodes are : %d\n",iRet);   

    DeleteLast(&head);
    Display(head);
    iRet = Count(head);
    printf("Total Numbers of nodes are : %d\n",iRet); 

    InsertAtPos(&head,45,4);
    Display(head);
    iRet = Count(head);
    printf("Total Numbers of nodes are : %d\n",iRet); 

    DeleteAtPos(&head,4);
    Display(head);
    iRet = Count(head);
    printf("Total Numbers of nodes are : %d\n",iRet); 

    return 0;
}