#include <iostream>
using namespace std;
struct node{
    int data;
    int priority;
    node *next;
};

class priority_queue
{
    private:
    node *head;

    public: 
    priority_queue();
    ~priority_queue();
    void insert(int priority, const int x);
    int min() const;
    void removeMin();
};
priority_queue::priority_queue(){
    head = nullptr;
};
priority_queue::~priority_queue(){};
void priority_queue::insert(int priority, const int x)
{   
    node *temp, *q;
    temp->priority = priority;
    temp->data = x;
    if(head == nullptr || priority < head->priority)
    {
        temp->next = head;
        head = temp; 
    }
    else
    {
        //cout << "our priority is: " << priority << endl;
        //cout << "these are the lower priorities already in: " << endl;
        q = head; 
        while(head !=nullptr && q->next->priority <= priority)
        {
            //cout << q->priority << endl;
            q = q->next;
        }
          temp->next = q->next;
          q->next = temp;
    }
 cout << "Key: " << priority << endl; 
 cout << "Value: " << temp->data;

}


int main()
{
    priority_queue pQueue;
    pQueue.insert(5, 3);
    pQueue.insert(2, 6);
    pQueue.insert(9, 2);


    return 0; 
}