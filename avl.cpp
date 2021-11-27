#include <iostream>

using namespace std;
struct NODE
{
    int key;
    NODE* left;
    NODE* right;
};

int Height(NODE* pRoot)
{
    if (pRoot == NULL)
        return 0;
    int heightLeft = Height(pRoot->left);
    int heightRight = Height(pRoot->right);
    int heightMax = max(heightLeft, heightRight) + 1;
    return heightMax;
}

NODE* createNode(int data)
{
    NODE* p = new NODE;
    p -> key = data;
    p -> left = NULL;
    p -> right = NULL;
    return p;
}

Insert(NODE* &pRoot, int x)
{
    if (pRoot == NULL)
        pRoot = createNode(x);
    if (x > pRoot->key )
        Insert(pRoot->right , x);
    if (x < pRoot->key)
        Insert(pRoot->left , x);
    else
        return pRoot;
}

void LRotate(NODE* &pRoot)
{
    NODE* p = pRoot ->right;
    pRoot ->right = p->left;
    p ->left = pRoot;
    pRoot = p;
}

void RRotate(NODE* &pRoot){
    NODE* p = pRoot ->left;
    pRoot ->left = p->right;
    p ->right = pRoot;
    pRoot = p;
}

void Insert(NODE* &pRoot, int x){
    if (pRoot == NULL)
    {
        pRoot = createNode(x);
        return ;
    }
        
    if (pRoot -> key == x)
    {
        return ;
    }
    if (pRoot -> key > x)
    {
        Insert(pRoot->right, x);
    }
    if (pRoot -> key < x)
    {
        Insert(pRoot->left, x);
    }

    int balance = Height(pRoot->left) - Height(pRoot->right);
    
    if(balance >= 2){
        if (Height(pRoot->left->left) >= Height(pRoot->left->right)){
            RRotate(pRoot);
        }
        if (Height(pRoot->left->left) <= Height(pRoot->left->right)){
            LRotate(pRoot->left);
            RRotate(pRoot);
        }
    }

    if (balance <= -2){
        if (Height(pRoot->right->right) >= Height(pRoot->right->left)){
            LRotate(pRoot);
        }
        if (Height(pRoot->right->right) <= Height(pRoot->right->left)){
            RRotate(pRoot->left);
            LRotate(pRoot);
        }
    }
}
void Remove(NODE* &pRoot, int x){
    if (pRoot == NULL)
        return ;
    if (pRoot->key < x)
        Remove(pRoot->right, x);
    if (pRoot->key > x)
        Remove(pRoot->left, x);
    if (pRoot->key == x)
    {
        if (pRoot->right == NULL && pRoot->left == NULL)
        {
            delete pRoot;
            pRoot = NULL;
        }
        else if (pRoot->right != NULL && pRoot->left == NULL){
            NODE* p = pRoot;
            pRoot = pRoot ->left ;
            delete p;
        }
        else if (pRoot->right == NULL && pRoot->left != NULL){
            NODE* p = pRoot;
            pRoot = pRoot ->right ;
            delete p;
        }
        else if (pRoot->right != NULL && pRoot->left != NULL){
            NODE* p = pRoot->right;
            while (p->left != NULL){
                p = p ->left;
            }
            pRoot ->key = p ->key;
            Remove(pRoot ->right, pRoot ->key);
        }
    }

    if (pRoot == NULL)
        return ;

    int balance = Height(pRoot->left) - Height(pRoot->right);
    
    if(balance >= 2){
        if (Height(pRoot->left->left) >= Height(pRoot->left->right)){
            RRotate(pRoot);
        }
        if (Height(pRoot->left->left) <= Height(pRoot->left->right)){
            LRotate(pRoot->left);
            RRotate(pRoot);
        }
    }

    if (balance <= -2){
        if (Height(pRoot->right->right) >= Height(pRoot->right->left)){
            LRotate(pRoot);
        }
        if (Height(pRoot->right->right) <= Height(pRoot->right->left)){
            RRotate(pRoot->left);
            LRotate(pRoot);
        }
    }
}
int main()
{
    NODE *pRoot = createNode(5);
    cout << pRoot;
}