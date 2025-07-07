#include <iostream>
using namespace std;
/*int foo(int &x,int c)
{

    c=c-1;
    if(c==0)
        return 1;
    x=x+1;
  
    return (foo(x,c)*x);
}
*/
// int main()
// {
//     int x=-1;
//     unsigned int y = 2;
// // integer promotion
//     if(x > y)
//     cout<<"X is greater";
//     else
//     cout<<"Y is greater";
// }

// //----------------OPERATOR OVERLOADING-------------------------------
// class Complex {
//     private:
//     int real;
//     int imag;
//     public:
//     Complex(int r=0, int i=0)
//     {
//         real=r;
//         imag=i;
//     }
//     Complex operator + (Complex & obj)
//     {
//         Complex res;
//         res.real= real+ obj.real;
//         res.imag= imag+ obj.imag;
//         return res;

//     }
//     void display()
//     {
//         cout<<real<<" + i"<<imag<<endl;
//     }

// };
// int main()
// {
// Complex c1(12,6);
// Complex c2(8,8);
// Complex c3 = c1 + c2;
// c3.display();

// }
// ----------------------------------------------------------------------------------------

//////////////////////////////Polymorphism/////////////////////////////////////////////////
// class base{
//     public:
//     virtual void Func1()
//     {
//         cout<<"This is base Class Function1"<<endl;
//     }
//     virtual void Func2()
//     {
//         cout<<"This is base Class Function2"<<endl;
//     }
// };
// class derived : public base{
//     public:
//     void Func1()
//     {
//         cout<<"This is derived Class Function1"<<endl;
//     }
//     void func2(){
//         cout<<"This is derived Class Function2"<<endl;
//     }
// };
// int main()
// {   derived d;
//     base *baseptr;
//     baseptr = &d;
//     baseptr -> Func1();
//     baseptr -> Func2();
//     return 0;
// }
//------------------------------------------------------------------------------------------------------
//-------------------Linked List------------------------------------------------------------------------
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insert_at_end(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insert_at_head(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

void deleteHead(node *&head)
{

    node *todelete = head;
    head = head->next;
    delete todelete;
}
void deletion(node *&head, int value)
{
    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else if (head->next == NULL)
    {
        deleteHead(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != value)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
bool search(node * &head, int key)
{  node* temp= head;
    while(temp!=NULL){
        temp=temp->next;
        if(temp->data==key)
        {
           deletion(head,key);
           return true;   
        }
    }
    return false;
}


int main()
{
    node *head = NULL;
    insert_at_end(head, 1);
    insert_at_end(head, 2);
    insert_at_end(head, 3);
    insert_at_end(head, 4);
    display(head);
    insert_at_head(head, 0);
    display(head);
    deleteHead(head);
    deletion(head, 3);
    display(head);
    if (search(head, 4))
        cout << "Element found and deleted sucessfully" << endl;
    else
        cout << "Element Not found" << endl;

    display(head);

    return 0;
}
