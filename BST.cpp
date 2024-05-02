#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

class BST
{
    private:
        node* root;
    public:
        BST()
        {
            root = nullptr;
        }

        void insert1(int x)
        {
            insert(x, root);
        }
        void insert(int x, node* r)
        {
            if(root == nullptr)
            {
                //Empty tree
                node* newNode = new node();
                newNode->data = x;
                newNode->left = nullptr;
                newNode->right = nullptr;
                root = newNode;
            }
            else 
            {
                if(x < r->data)
                {
                    //Insert left
                    if(r->left == nullptr)
                    {
                        node* newNode = new node();
                        newNode->data = x;
                        newNode->left = nullptr;
                        newNode->right = nullptr;
                        r->left = newNode;
                    }
                    else
                    {
                        insert(x, r->left);
                    }
                    
                }
                else
                {
                    //Insert right
                    if(r->right == nullptr)
                    {
                        node* newNode = new node();
                        newNode->data = x;
                        newNode->left = nullptr;
                        newNode->right = nullptr;
                        r->right = newNode;
                    }
                    else
                    {
                        insert(x,r->right);
                    }
                    
                }
            } 

        }

        void inorder(node* x)
        {
            if(x != nullptr)
            {
                inorder(x->left);
                cout<<x->data<<" ";
                inorder(x->right);
            }
        }

        void inorder1()
        {
            //'root' is a private member
            inorder(root);
        }
};

int main()
{
    BST b1;
    b1.insert1(12);
    b1.insert1(4);
    b1.insert1(36);
    b1.insert1(48);
    //Wrapper function
    b1.inorder1();
    return 0;
}