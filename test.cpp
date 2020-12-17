#include <iostream>
#include <iomanip>
//#include <stack>

using namespace std;
struct node
{
    int data;
    node *next;
    node(int d){
        data = d;
    }
};
class myStack
{
    private:
        node *top;
        int count = 0;
    public:
        myStack();
        ~myStack();
        void push(int x);
        void pop();
        int peek();
        int size() const;
        bool isEmpty() const;

};
myStack::myStack(){};
myStack::~myStack(){};
int myStack::size() const
{
    return count;
}
void myStack::push(int x)
{
    //create a node
    node *temp = new node(x);
    //is stack empty?
    if(isEmpty())
    {
        //point top to that node
        top = temp; 
        count++;
    }
    //else just push
    else{
        //top node's next node is the new node we created
        temp->data = x;
        temp->next = top; //temp points to top 
        top = temp;      //we can now set top to our temp
                        //meaning temp is officially our top 
        count++;
    }
}
void myStack::pop()
{
    if(isEmpty())
    {
        cout << "You cannot delete from an empty stack!";
    }
    else
    {
        top = top->next;
        count--;
    }
}
int myStack::peek()
{
    return top->data;
}
bool myStack::isEmpty() const
{
    return top == nullptr;
}

int main(){
myStack stack; 
stack.push(9);
cout << stack.peek();
stack.push(8);
cout << stack.peek();
stack.push(4);
cout << stack.peek();
stack.push(5);
cout << stack.peek();
stack.pop();
cout << stack.peek();
cout << endl;
cout << "The size is: " << stack.size() << endl;
}

