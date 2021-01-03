#include<iostream>

using namespace std;


struct node
{
    int key_value;
    node *left;
    node *right;
};

class bTree
{
    public:
        //Constructor 
        bTree();
        //Destructor 
        ~bTree();
        
        void insert(int key);
        node *search(int key);
        void destroy_tree();
        bool equalityCheck(node *first, node *second) const;
        node *root;
    private:
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        void destroy_tree(node *leaf);    
};
bTree::bTree()
{
    root = nullptr;
}
bTree::~bTree()
{
    destroy_tree();
}
void bTree::destroy_tree()
{
    destroy_tree(root);
}
void  bTree::destroy_tree(node *leaf)
{
    if(leaf != nullptr)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}
void bTree::insert(int key)
{
    //at the root
    if(root != nullptr)
    {
        insert(key, root);
    }
    else
    {
        root = new node;
        root->key_value = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}
node *bTree::search(int key)
{
    return search(key, root);
}
node *bTree::search(int key, node *leaf)
{
if(leaf != nullptr)
{
    if(leaf->key_value == key)
    {
        return leaf;
    }
    else if(key < leaf->key_value)
    {
        return search(key, leaf->left);
    }
    else 
    {
        return search(key, leaf->right);
    }
}
    else
    {
        cout << "Does not exist";
        return nullptr;
    }
}
void bTree::insert(int key, node *leaf)
{
    if(key < leaf->key_value)
    {
        if(leaf->left != nullptr)
        {
            insert(key, leaf->left);
        }
        else
        {
            leaf->left = new node;
            leaf->left->key_value = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr; 
        }
    }
    else if(key >= leaf->key_value)
    {
        if(leaf->right != nullptr)
        {
        insert(key, leaf->right);
        }
        else
        {
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}
bool bTree::equalityCheck(node *first, node *second) const{
    if (first == nullptr || second == nullptr)
    {
        if (first == nullptr && second == nullptr)
        {
            return true;
        }
        return false;
    }
    if (first->key_value == second->key_value)
    {
        bool leftEquality = equalityCheck(first->left, second->left);
        bool rightEquality = equalityCheck(first->right, second->right);
        if (leftEquality == true && rightEquality == true)
        {
            return true;
        }
        return false;
    }
    else
    {
         return false;
    }
}




int main(){
    bTree first;
    bTree second;

    first.insert(5);
    second.insert(5);

    for (int i = 0; i <= 10; i += 2){
        first.insert(i);
    }
    for (int i = 1; i <= 10; i += 2){
        second.insert(i);
    }

    if (first.equalityCheck(first.root, second.root)){
        cout << "true";
    }
    else
    {
        cout << "false";
    }   
}
