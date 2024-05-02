#include <iostream>
using namespace std;
struct node
{
    char data;
    node* left;
    node* right;
};

class BTree
{
    private:
        node* root;
    public:
        BTree()
        {
            root = nullptr;
        }

        node* createNode()
        {
            node* tmp = new node;
            cout<<"Enter data for node: ";
            cin>>tmp->data;
            tmp->left = nullptr;
            tmp->right = nullptr;
        }

        void insert(node* r, node* newNode)
        {
            if(r != nullptr)
            {
                char choice;
                l1:
                cout<<"Enter node to left(L) or right(R) of "<<r->data<<": ";
                cin>>choice;
                if(choice == 'L' || choice == 'l')
                {
                    if(r->left == nullptr)
                    {
                        r->left = newNode;
                        return;
                    }
                    else
                    {
                        r = r->left;
                        goto l1;
                    }
                }
                else if(choice == 'R' || choice == 'r')
                {
                    if(r->right == nullptr)
                    {
                        r->right = newNode;
                        return;
                    }
                    else
                    {
                        r = r->right;
                        goto l1;
                    }
                }
                else
                {
                    cout<<"Wrong Value Entered";
                }
            }
        }

        void tree()
        {
            node* newNode = createNode();
            if(root ==  nullptr)
            {
                root = newNode;
            }
            else
            {
                insert(root, newNode);
            }
        }

        void preOrder(node* r)
        {
            if(r != nullptr)
            {
                cout<<r->data;
                preOrder(r->left);
                preOrder(r->right);
            }
        }

        void preOrder()
        {
            preOrder(root);
        }
};

int main()
{
    BTree b1;
    b1.tree();
    b1.tree();
    b1.tree();
    b1.tree();
    b1.preOrder();

    return 0;
}