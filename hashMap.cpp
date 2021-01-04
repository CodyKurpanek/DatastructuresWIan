#include<iostream>
#include<list>
#include <array>
using namespace std;
class hashTable
{
    private:
    int size;
    list<int> *table; 
    public:
    hashTable();
    ~hashTable();
    int hashFunction(int key);
    void put(int key, int value);
    int get(int key);
};
hashTable::hashTable()
{
    size = 5;
    table = new list<int>[size];
}
hashTable::~hashTable(){};
int hashTable::hashFunction(int key)
{
    return (key % size); 
}
void hashTable::put(int key, int value)
{
    //function returns which linked list to put into
    int index = 0;
    index = hashFunction(key);
    table[index].push_back(value);
}
int hashTable::get(int key){
    int index = 0;
    index = hashFunction(key);
    table[index].front();
}



int main(){
    list<int> *table = new list<int>[4];
    table[0].push_back(4);

}
