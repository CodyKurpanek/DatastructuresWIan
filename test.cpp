#include <iostream>
using namespace std;

//node
template<typename T> 
struct node{
    T data;
    node *next;
};
template<typename T> 
class myStack
{
    public:
    myStack();
    ~myStack();
    int pop();
    T peek();
    int size();
    void push(T x);
    bool isEmpty();
    private:
    int count;
    node<T> *top; 
};
 
//stack
template<typename T>
myStack<T>::myStack(){
    top = nullptr;
    count = 0;
};
template<typename T>
myStack<T>::~myStack(){};
template<typename T>
int myStack<T>::size()
{
    return count; 
}
template<typename T>
int myStack<T>::pop()
{
    //node *temp = new node();
    if(isEmpty())
    {
        cout << "\nCannot output from an empty stack!\n";
        return -1;
    }
    else
    {
        node<T> *tmp = top;
        int a = top->data;
        top = top->next;
        delete(tmp);
        count--;
        return a;
    }
    
}
template<typename T>
void myStack<T>::push(T x)
{
    node<T> *temp = new node<T>();
    temp->data = x; 
    if(isEmpty())
    {
        top = temp;
        count++;
    }
    else
    {
      temp->next = top;
      top = temp;
      count++;
    }
}
template<typename T>
T myStack<T>::peek()
{
    if(top == nullptr)
    {
        
    }
    else
    {
      return top->data;
    } 
}
template<typename T>
bool myStack<T>::isEmpty(){
    return top == nullptr;
}
 
//function signatures for compiler
bool isBalanced(string myString);
void reverseString(string str);


 
int main()
{
    
    return 0;
}



 
 bool isBallanced(string myString){
    //myString = "{(99 + 20) * [50]} = 20";
    myStack<char> stack;

    for(char ch: myString)
    {
        if(ch == '(' || ch == '{' || ch == '[')
        {
            stack.push(ch);
            cout << stack.peek();
        }
        if(ch == ')')
        {
            if(stack.peek() == '(')
            {
                stack.pop();
            }
            else{
                return false;
            }
        }
        if(ch == ']')
        {
            if(stack.peek() == '[')
            {
                stack.pop();
            }
            else{
                return false;
            }
        }
        if(ch == '}')
        {
            if(stack.peek() == '{')
            {
                stack.pop();
            }
            else{
                return false;
            }
        }
    }
    
    if(!stack.isEmpty())
    {
        return false;
    }
    return true;
 }
 
 
void reverseString(string str){
    myStack<char> stack;
    //for each character in str
    for(char c: str){
        //put that character into the stack
        stack.push(c);
    }
    
    string reversedString = "";
    //until the stack is empty
    while (!stack.isEmpty()){
        //take out the characters from the stack 1 by 1 and put htose into a new string
        reversedString.push_back(stack.pop());
    }
    cout << str << " reversed is: " << reversedString << "?" << endl;
}