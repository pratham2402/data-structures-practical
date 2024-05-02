#include<iostream>
using namespace std;
class Node
{
    private:
        char data;
        Node* left;
        Node* right;
        Node* next;
    public:
        Node()
        {
            left = nullptr;
            right = nullptr;
        }
        Node(char value)
        {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    friend class Stack;
    friend class ExpTree;
};

class Stack
{
    private:
        Node* top = NULL;
    public:
        void push(Node* x)
        {
            if(top == NULL)
            {
                top = x;
            }
            else
            {
                x->next = top;
                top = x;
            }
        }

        Node* pop()
        {
            Node* temp = top;
            top = top->next;
            return temp;
        }

        Node* peek()
        {
            return top;
        }
};

class ExpTree
{
    private:
        Node* root;
    public:
        ExpTree()
        {
            root = new Node();
        }

        void buildTree(string exp)
        {
            int i=0;
            Stack stack;
            for(i = 0; exp[i] != '\0'; i++)
            {
                if(isalnum(exp[i]))
                {
                    Node* newNode = new Node(exp[i]);
                    newNode->left = nullptr;
                    newNode->right = nullptr;
                    stack.push(newNode);
                }
                else
                {
                    Node* newNode = new Node(exp[i]);
                    newNode->right = stack.pop();
                    newNode->left = stack.pop();
                    stack.push(newNode);
                }
            }
            root = stack.peek();
        }

        void inOrder(Node* x)
        {
            if(x != nullptr)
            {
                inOrder(x->left);
                cout<<x->data;
                inOrder(x->right);
            }
        }

        void wrapperInorder()
        {
            inOrder(root);
        }

        void preOrder(Node* x)
        {
            if(x != nullptr)
            {
                cout<<x->data;
                preOrder(x->left);
                preOrder(x->right);
            }
        }

        void wrapperPreorder()
        {
            preOrder(root);
        }

        void postOrder(Node* x)
        {
            if(x != nullptr)
            {
                postOrder(x->left);
                postOrder(x->right);
                cout<<x->data;
            }
        }

        void wrapperPostorder()
        {
            postOrder(root);
        }
};

int main()
{
    ExpTree tree;
    string exp;
    int choice;
    while(choice != 5)
    {
        cout<<"1. Enter postfix expression\n2. Display In Order\n3. Display Pre Order\n4. Display Post Order\n5. Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter postfix expression: ";
                cin>>exp;
                break;
            case 2:
                tree.buildTree(exp);
                cout<<"In Order: ";
                tree.wrapperInorder();
                cout<<endl;
                break;
            case 3:
                cout<<endl;
                cout<<"Pre Order: ";
                tree.wrapperPreorder();
                cout<<endl;
                break;
            case 4:
                cout<<endl;
                cout<<"Post Order: ";
                tree.wrapperPostorder();
                cout<<endl;
                break;
            case 5:
                break;
            default:
                cout<<"Incorrect Input"<<endl;
        }
    }
    return 0;
}