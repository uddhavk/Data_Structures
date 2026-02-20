///////////////////////////////////////////////////////////////////////
// Final code of Singly Circular LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#pragma pack(1)
template<class T>

class SinglyCLLnode
{
    public: 
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;

    public:
        SinglyCLL();

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
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Linked List gets created\n";
    this->iCount = 0;
    this->first = NULL;
    this->last = NULL;
}

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    (this->last)->next = this->first;
    this->iCount++;     
}

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else 
    {
        this->last->next = newn;
        this->last = newn;
        
    }
    (this->last)->next = this->first;
    this->iCount++; 
}

template<class T>
void SinglyCLL<T> :: InsertAtPos(T no,int pos)
{
    int iCnt = 0;
    
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *newn = NULL;

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
        newn = new SinglyCLLnode<T>(no);

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLnode<T> *temp = NULL;

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
    }
    this->iCount--;
}

template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

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
        while(temp->next != this->last)
        {
            temp = temp->next;
        }
        delete(this->last);
        this->last = temp;
        temp->next = this->first;      
    }
    iCount--;
}

template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;

    if(pos < 1 || pos > (iCount + 1))
    {
        printf("Invalid Position");
        return;
    }
    if(pos == 1)
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
        delete(target);
        this->iCount--;
    }
}

template<class T>
void SinglyCLL<T> :: Display()
{
    cout<<"->";
    do
    {
        cout<<"| "<<first->data<<" |->";
        first = first->next;
    }while(first != last->next);
    cout<<"\n";
}

template<class T>
int SinglyCLL<T> :: Count()
{
    return iCount;
}


int main() 
{
    SinglyCLL<float> *scobj = new SinglyCLL<float>(); 

    scobj->InsertFirst(51.3);
    scobj->InsertFirst(21.2);
    scobj->InsertFirst(11.1);
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";

    scobj->InsertLast(101.4);
    scobj->InsertLast(121.5);
    scobj->InsertLast(151.6);
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";

    scobj->DeleteFirst();
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";

    scobj->DeleteLast();
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";

    scobj->InsertAtPos(45.77,4);
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";

    scobj->DeleteAtPos(4);
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";

    return 0;
}