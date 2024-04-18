#include <iostream>
#include <string>
using namespace std;
struct edge
{
    char dest;
    int cost;
    struct edge* link;
};

struct node
{
    struct node* next;
    char name;
    struct edge* adj;
};

class graph
{
    node* start;
    public:
        graph()
        {
            start=NULL;
        }
        void displayg(int v, int e);
        void scangraph(int v, int e);
};

void graph::displayg(int v, int e)
{
    node* ptr;
    edge* p;
    ptr = start;
    while(ptr != NULL)
    {
        cout<<endl;
        cout<<ptr->name;
        p=ptr->adj;
        while(p != NULL)
        {
            cout<<"--> "<<p->dest << " & cost: "<<p->cost;
            p = p->link;
        }
        ptr = ptr->next;
        if(ptr != NULL)
        {
            cout<<endl<<"|";
        }
    }
}

void graph::scangraph(int v, int e)
{
    int i,cost;
    char s,d;
    int n = 65;
    node* ptr;
    node* bptr;
    edge* p;
    edge* bp;
    for(i=0;i<v;i++)
    {
        ptr = new node;
        ptr->name = (65+i);
        ptr->next = NULL;
        ptr->adj = NULL;
        if(start == NULL)
        {
            start = ptr;
        }
        else
        {
            bptr = start;
            while(bptr->next !=  NULL)
            {
                bptr = bptr->next;  
            }
            bptr->next = ptr;
        }
    }
    cout<<endl<<"Please enter source city and destination city";
    cout<<endl<<"Starting from A upto number of cities like A,B,C,D";
    for(i=0;i<e;i++)
    {
        l1:
            cout<<endl<<"Edge no -> "<<i+1<<endl;
            cout<<"Source City-> ";
            cin>>s;
            cout<<"Destination City-> ";
            cin>>d;
            cout<<"Cost-> ";
            cin>>cost;
            if((s>=65 && s<(65+v)) && (d>=65 && d<(65+v)))
            {
                bptr = start;
                while(bptr->name != s)
                {
                    bptr = bptr->next;
                }
                if(bptr != NULL)
                {
                    p = new edge;
                    p->dest = d;
                    p->cost = cost;
                    p->link = NULL;
                    bp = bptr->adj;
                    if(bp == NULL)
                    {
                        bptr->adj = p;
                    }
                    else
                    {
                        while(bp->link != NULL)
                        {
                            bp = bp->link;
                        }
                        bp->link = p;
                    }
                }
            }
            else
            {
                cout<<"Please enter correct vertex no's";
                goto l1;
            }
    }
}

int main()
{
    int ch,cont,v,e;
    graph g1;
    do
    {
        cout<<endl<<"Menu";
        cout<<endl<<"1. Create graph using adjacency list";
        cout<<endl<<"2. Display Graph";
        cout<<endl<<"Enter choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"No of cities: ";
                cin>>v;
                cout<<"No of flights: ";
                cin>>e;
                g1.scangraph(v,e);
                break;
            case 2:
                g1.displayg(v,e);
                break;
        }
        cout<<endl<<"Do you want to continue? (1 for continue): ";
        cin>>cont;
    }

    while(cont==1);

    return 0;
}
