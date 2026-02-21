#include <iostream>
using namespace std;

#pragma pack(1)
class Stacknode
{
    public: 
        int data;
        Stacknode *next;

        Stacknode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class Stack
{
    private:
        Stacknode *first;
        int iCount;

    public: 
        Stack();
        void push(int);
        int pop();
        int peep();
        void Display();
        int Count();

};

Stack:: Stack()
{
    cout<<"Stack gets cerated successfully\n";

    this->first = NULL;
    this->iCount = 0;
}

void Stack :: push(int no)
{
    Stacknode *newn = NULL;
    newn = new Stacknode(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

int Stack :: pop()
{
    int Value = 0;
    Stacknode *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;

    delete temp;

    this->iCount--;

    return Value;
}

int Stack :: peep()
{
    int Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;
    return Value;
}

void Stack :: Display()
{
    Stacknode *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }

}

int Stack :: Count()
{
    return this->iCount;
}


int main() 
{
    Stack *stobj = new Stack();

    stobj->push(11);
    stobj->push(21);
    stobj->push(51);
    stobj->push(101);

    stobj->Display();
    cout<<"Number of elements is stack are : "<<stobj->Count()<<"\n";
    cout<<"Return value of peep is : "<<stobj->peep()<<"\n";
    
    stobj->Display();
    cout<<"Number of elements is stack are : "<<stobj->Count()<<"\n";

    cout<<"Poped elemet is : "<<stobj->pop()<<"\n";
    stobj->Display();
    cout<<"Number of elements is stack are : "<<stobj->Count()<<"\n";
    
    stobj->push(121);
    stobj->Display();
    cout<<"Number of elements is stack are : "<<stobj->Count()<<"\n";

    delete stobj;


    return 0;
}