#include <iostream> 
#include <vector>
using namespace std;

class heap
{
    private:
        vector<int> myVector;
    public:
        heap();
        ~heap();
        int getParent(int child);
        int getChild(int parent);
        void insert(int value);
        void remove();
        void bubbleUp(int child, int parent);
        void bubbleDown(int child, int parent);
};
heap::heap()
{
}
heap::~heap()
{
}
int heap::getChild(int parent)
{   
    // if second child doesnt exist, return first child
    if (parent * 2 + 2 == myVector.size()){
        return parent * 2 + 1;
    }

    int child1Value = myVector[parent * 2 + 1];
    int child2Value = myVector[parent * 2 + 2];
    if (child1Value > child2Value){
        return parent * 2 + 1;
    }
    else{
        return parent * 2 + 2;
    }
}
int heap::getParent(int child)
{
    return ((child - 1) / 2);
}
void heap::insert(int value)
{
    if(myVector.size() == 0)
    {
        myVector.push_back(value);
    }
    else
    {
        myVector.push_back(value);
        int current = myVector.size() - 1;
        int parent = getParent(current);
        while (myVector.at(current) > myVector.at(parent) && current != 0){
            bubbleUp(current, parent);
            current = parent;
            parent = getParent(current);
        }
    }
}

void heap::bubbleUp(int child, int parent)
{
    int temp = myVector.at(child);
    myVector.at(child) = myVector.at(parent);
    myVector.at(parent) = temp;
}

void heap::remove()
{
    int current = myVector.size() -1;
    myVector[0] = myVector.at(current);
    myVector.pop_back();
    int greatestChild = getChild(0);
    int parent = 0;
    while(greatestChild < myVector.size() && myVector.at(greatestChild) > myVector.at(parent))
    {
        bubbleDown(greatestChild, parent);
        parent = greatestChild;
        greatestChild = getChild(parent);
    }
}
void heap::bubbleDown(int child, int parent)
{
    int temp =  myVector.at(parent); 
    myVector.at(parent) = myVector.at(child);
    myVector.at(child) = temp;
}

int main(){
    heap myHeap;
    myHeap.insert(15);
    myHeap.insert(10);
    myHeap.insert(3);
    myHeap.insert(8);
    myHeap.insert(12);
    myHeap.insert(9);
    myHeap.insert(4);
    myHeap.insert(1);
    myHeap.insert(24);
    myHeap.remove();
    myHeap.remove();
    return(0);
}