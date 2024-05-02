#include <iostream>
using namespace std;
class node
{
    private:
        string data;
        string keyword;
        node* left;
        node* right;
    friend class Dict;

};

class Dict
{
    private:
        node* root;
    public:
        Dict()
        {
            root = nullptr;
        }
        void Insert(string key,string meaning, node* r)
        {
            if(root == nullptr)
            {
                node* newNode = new node();
                newNode->data = key;
                newNode->keyword = meaning;
                newNode->left = nullptr;
                newNode->right = nullptr;
                root = newNode;
            }
            else
            {
                if(key >= r->data)
                {
                    if(r->right == nullptr)
                    {
                        node* newNode = new node();
                        newNode->data = key;
                        newNode->keyword = meaning;
                        newNode->left = nullptr;
                        newNode->right = nullptr;
                        r->right = newNode;
                    }
                    else
                    {
                        Insert(key, meaning, r->right);
                    }


                }

                else
                {
                    if(r->left == nullptr)
                    {
                        node* newNode = new node();
                        newNode->data = key;
                        newNode->keyword = meaning;
                        newNode->left = nullptr;
                        newNode->right = nullptr;
                        r->left = newNode;
                    }
                    else
                    {
                        Insert(key, meaning, r->left);
                    }
                }
            }

        }

        void InsertDummy(string key23, string meaning23)
        {
            Insert(key23, meaning23, root);
        }

        //Preorder
        void Ascending(node* x)
        {
            if(x != nullptr)
            {
                Ascending(x->left);
                cout<<x->data<<"- "<<x->keyword<<endl;
                Ascending(x->right);
            }
            
        }

        void AscendingDummy()
        {
            Ascending(root);
        }

        void Descending(node* x)
        {
            if(x != nullptr)
            {
                Descending(x->right);
                cout<<x->data<<"- "<<x->keyword<<endl;
                Descending(x->left);
                
            }
            
        }

        void DescendingDummy()
        {
            Descending(root);
        }
};

int main()
{
    Dict d;
    string keyword1,meaning1;
    int choice=0;
    while(choice != 6)
    {
        cout<<"1. Add new keyword\n2. Delete Keyword\n3. Update Meaning\n4. Display Dictionary In Ascending Order\n5. Display Dictionary In Descending Order\n6. Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter keyword: ";
                cin.ignore(); // Ignore any previous newline character in the buffer
                getline(cin, keyword1);
                cout<<"Enter meaning: ";
                getline(cin, meaning1);
                d.InsertDummy(keyword1, meaning1);
                break;
            
            case 4:
                d.AscendingDummy();
                break;

            case 5:
                d.DescendingDummy();
                break;
            
            case 6:
                break;
            
            default:
                cout<<"Wrong Value Entered.";
                break;

        }
    }
    return 0;
}