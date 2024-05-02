#include <iostream>
using namespace std;
struct TBTnode
{
    int data;
    TBTnode* left;
    TBTnode* right;
    bool lbit;
    bool rbit;
};

class TBT
{
    private:
        TBTnode* root;
        TBTnode* dummyNode;
    public:
        TBT()
        {
            root = nullptr;
            dummyNode = nullptr;
        }

        TBTnode* createNode()
        {
            TBTnode* tmp = new TBTnode;
            tmp->left = tmp->right = nullptr;
            tmp->lbit = tmp->rbit = 1;
            cout<<"Enter data: ";
            cin>>tmp->data;
            return tmp;
        }

        void createTree()
        {
            TBTnode* newNode = nullptr;
            newNode = createNode();
            if(root == nullptr)
            {
                root = newNode;
                dummyNode = new TBTnode();
                dummyNode->data = 999;
                dummyNode->left = root;
                //Extra
                dummyNode->right = dummyNode;
                root->left = root->right = dummyNode;
            }

            else
            {
                insert(root, newNode);
            }
        }

        void insert(TBTnode* r, TBTnode* newNode)
        {
            if(newNode->data < r->data)
            {
                if(r->lbit == 1)
                {
                    newNode->left = r->left;
                    newNode->right = r;
                    r->left = newNode;
                    r->lbit = 0;
                }
                else
                {
                    insert(r->left, newNode);
                }
            }

            if(newNode->data >= r->data)
            {
                if(r->rbit == 1)
                {
                    newNode->right = r->right;
                    newNode->left = r;
                    r->rbit = 0;
                    r->right = newNode;
                }
                else
                {
                    insert(r->right, newNode);
                }
            }

        }

        void inOrder(TBTnode* root, TBTnode* dummyNode)
        {
            while(root != dummyNode)
            {
                while(root->lbit == 0) //Left Subtree
                {
                    root = root->left;
                }

                cout<<" "<<root->data;

                while(root->rbit == 1) //Right Subtree
                {
                    root = root->right;
                    if(root == dummyNode)
                    {
                        return;
                    }
                    cout<<" "<<root->data;
                }
                root = root->right;
            }
        }

        void dummyInorder()
        {
            inOrder(root, dummyNode);
        }
};

int main()
{
    TBT t;
    int choice = 0;
    while(choice != 3)
    {
        cout<<"1. Insert Value\n2. Inorder\n3. Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                t.createTree();
                break;
            
            case 2:
                t.dummyInorder();
                break;
            
            case 3:
                break;

            default:
                cout<<"Wrong Value Entered"<<endl;
        }
    }
    return 0;
}
