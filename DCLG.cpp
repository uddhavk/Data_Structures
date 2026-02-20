///////////////////////////////////////////////////////////////////////
// Final code of Doubly Circular LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#pragma pack(1)
template<class T>

class DoublyCLLnode
{
    public: 
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public:
        DoublyCLL();

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
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Linked List gets created\n";
    this->iCount = 0;
    this->first = NULL;
    this->last = NULL;
}

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        newn->prev = this->last;
        newn->next->prev = newn;
        this->first = newn;
    }
    (this->last)->next = this->first;
    (this->first)->prev = this->last;
    this->iCount++;
    
}

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    
    newn = new DoublyCLLnode<T>(no);
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->prev = this->last;
        (this->last)->next = newn;
        this->last  = newn;
    }
    
    (this->last)->next = this->first;
    (this->first)->prev = this->last;
    this->iCount++;
 
}

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no,int pos)
{
    int iCnt = 0;
    
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *newn = NULL;

    if(pos < 1 || pos > (iCount + 1))
    {
        printf("Invalid Position");
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (iCount + 1))
    {
        this->InsertLast(no);
    }
    else
    {  
        temp = this->first;
        newn = new DoublyCLLnode<T>(no);

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
        this->iCount++;

    }      
    
}

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    DoublyCLLnode<T> *temp = NULL;
    
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    { 
        delete(this->first);              
        
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        this->first = (this->first)->next;
        delete(temp);
        (this->last)->next = this->first;
        (this->first)->prev = this->last;
    }
   this->iCount--;
}

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    DoublyCLLnode<T> *temp = NULL;
    
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    { 
        delete(this->first);        
        
        this->first = NULL;
        this->last = NULL;
        
    }
    else
    {    temp = this->last;
        this->last = (this->last)->prev;

        delete(temp);

        (this->last)->next = this->first;
    (this->first)->prev = this->last;
    }
    this->iCount--;  
    
}

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *target = NULL;

    if(pos < 1 || pos > iCount)
    {
        printf("Invalid Position\n");
        return;
    }
    else if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
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
        delete(target);
        this->iCount--;
    }
    
}

template<class T>
void DoublyCLL<T> :: Display()
{
    cout<<"<=>";
    do
    {
        cout<<"| "<<first->data<<" |<=>";
        first = first->next;
    }while(first != last->next);
    cout<<"\n";
}

template<class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}


int main() 
{
    DoublyCLL<double> *dcobj = new DoublyCLL<double>(); 

    dcobj->InsertFirst(51.321);
    dcobj->InsertFirst(21.21);
    dcobj->InsertFirst(11.1);
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";

    dcobj->InsertLast(101.43);
    dcobj->InsertLast(121.543);
    dcobj->InsertLast(151.65);
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";

    dcobj->DeleteFirst();
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";

    dcobj->DeleteLast();
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";

    dcobj->InsertAtPos(455.89,4);
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";

    dcobj->DeleteAtPos(4);
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";

    return 0;
}