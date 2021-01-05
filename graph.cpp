#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;


class node{
    public:
        string label;
        node();
        node(string label);
        bool operator==(const node& other) const{
            return label == other.label;
        }
};
node::node(){}
node::node(string label)
{
    this->label = label;
}

// namespace std {
//   template <>
//   struct hash<node>
//   {
//     std::size_t operator()(const node& k) const
//     {
//       using std::size_t;
//       using std::hash;
//       using std::string;

//       // Compute individual hash values for first,
//       // second and third and combine them using XOR
//       // and bit shifting:

//       return (hash<string>()(k.label));
//     }
//   };
// }


class myGraph
{
    private:
        unordered_map<string, node*> nodes;
        unordered_map<string, list<node*>*> adjList;
    public:
        myGraph();
        ~myGraph();
        void addNode(string label);
        void addEdge(string from, string to);
        void print();

};
myGraph::myGraph(){}
myGraph::~myGraph(){}
void myGraph::addNode(string label)
{
    unordered_map<string, node*>::iterator it = nodes.find(label);
    if(it != nodes.end())
    {
        cout << "It's already there";
        //we found the element;
    }
    else
    {
        nodes[label] = new node(label);
        adjList[label] = new list<node*>;
    }
}

void myGraph::addEdge(string from, string to)
{
    node* fromNode;
    node* toNode;
    try
    {
        fromNode = nodes.at(from);
    }
    catch(const out_of_range& oor)
    {
        cout << "the from location (" << from << ") is not in the graph!" << endl;
        return;
    }
    try
    {
        toNode = nodes.at(to);
    }
    catch(const out_of_range& oor)
    {
        cout << "the to location (" << to << ") is not in the graph!" << endl;
        return;
    }
    //add to adjacency list 
    list<node*>* currentAdjList = adjList.at(fromNode->label);
    //check if isnt already in currentAdjList
    bool isInCurrentAdjList = false;
    for(node* connection: *currentAdjList){
        if (connection->label == toNode->label){
            isInCurrentAdjList = true;
        }
    }
    if(!isInCurrentAdjList){
        currentAdjList->push_back(toNode);
    }
}

void myGraph::print(){
    unordered_map<string, list<node*>*>::iterator it;
    for (it = adjList.begin(); it != adjList.end(); it++){
        for(node* adjacency: *it->second){
            cout << it->first << " is connnected to " << adjacency->label << endl;
        }
    }
}

int main()
{
    myGraph graph;
    graph.addNode("San Diego");
    graph.addNode("New York");
    graph.addNode("Arizona");
    graph.addEdge("San Diego", "New York");
    graph.addEdge("New York", "Arizona");
    graph.addEdge("Arizona", "Sandy Eggo");
    graph.addEdge("Arizona", "San Diego");
    graph.addEdge("San Diego", "Arizona");
    
    graph.print();

    return 0;
}

