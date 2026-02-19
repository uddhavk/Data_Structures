////////////////////////////////////////////////////////////////////////////////////
// Final Code of Doubly Linear LinkedList Using Generic Approach
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#pragma pack(1)
template<class T>

class DoublyLLLnode
{
    public:
    T data;
    node *prev;
    node *next;
    
    noDoublyLLLnodede(T no)
    {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
    }
        
};
    
template<class T>
class DoublyLLL
{
    public:
    DoublyLLLnode<T> *first;
    int iCount;
    
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        
        void Display();
        int Count();        
};
    
template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";
    
    this->first = NULL;
    this->iCount = 0;
    
}

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        temp = this->first;
        
        newn = new DoublyLLLnode<T>(no);
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        newn->prev = temp;
        newn->next->prev = newn;
        temp->next = newn;
        
        this->iCount++;
    }

}

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->next->prev = NULL;  //
    }
    this->iCount--;

}

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next =NULL;     
        
    }
    this->iCount--;

}

template<class T>
void DoublyLLL<T>:: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;;
    DoublyLLLnode<T> *target = NULL;;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;

        this->iCount--;
    }

}

template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    cout<<"\nNULL<=>";

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }

    cout<<"NULL\n";

}

template<class T>
int  DoublyLLL<T> :: Count()
{
    return this->iCount;
}


int main()
{
    DoublyLLL<int> *dobj = new DoublyLLL<int>();

    dobj->InsertFirst(51);
    dobj->InsertFirst(21);
    dobj->InsertFirst(11);
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast(101);
    dobj->InsertLast(121);
    dobj->InsertLast(151);
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos(3000,4);
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";

    delete dobj;

    return 0;
}