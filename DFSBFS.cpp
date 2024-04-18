#include <iostream>
#include <vector>
using namespace std;

int st[10],top=-1,Q[10],front=-1,rear=-1;

void insertQ(int v)
{
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        Q[rear]=v;
    }
    else if(rear<9)
    {
        Q[++rear]=v;
    }
    else
    {
        cout<<"Queue Overflow";
    }
}

int deleteQ()
{
    int v=-1;
    if(front == (rear+1))
    {
        cout<<"Queue Empty";
    }
    else if(front==-1 && rear == -1)
    {
        cout<<"Queue Empty";
    }
    else
    {
        v=Q[front];
        front++;
    }
    return v;
}


void push(int v)
{
    if(top<9)
    {
        st[++top]=v;
    }
    else
    {
        cout<<"Stack is full";
    }
}

int pop()
{
    int v=-1;
    if(top!=-1)
    {
        v=st[top];
        top--;
    }
    else
    {
        cout<<"Stack is empty";
    }
    return v;
}



int main() {

    int V, E;
    char Dir;

    cout << "Enter How many vertices? ";
    cin >> V;

    vector<vector<int>> adjMat(V + 1, vector<int>(V + 1, 0));
    //int adjMat[V + 1][V + 1];


    cout << "Graph is directed/undirected (D/U): ";
    cin >> Dir;

    cout << Dir;

    cout << "Enter Number of edges: ";
    cin >> E;

    int sr, ds, wt;

    for (int i = 0; i < E; i++) {
        cout << "Enter source, destination, and weight of the edge " << i + 1 << ": ";
        cin >> sr >> ds >> wt;

        if (sr >= 1 && sr <= V && ds >= 1 && ds <= V) {
            adjMat[sr][ds] = wt;
            if (Dir == 'U') 
                adjMat[ds][sr] = wt;
        } else {
            cout << "Enter correct vertices for the edge." << endl;
            i--; 
        }
    }

    // Print adjacency matrix
    cout << "Adjacency Matrix is: " << endl;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    //DFS
    int visited[V+1];
    int sv;
    cout<<"Enter from which vertex you want to start traversal: ";
    cin>>sv;
    for(int i=1;i<=V;i++)
    {
        visited[i]=0;
    }
    push(sv);
    while(top!=-1)
    {
        sv=pop();
        if(visited[sv]==0)
        {
            cout<<sv<<" ->";
            visited[sv]=1;
            for(int i=1;i<=V;i++)
            {
                if(adjMat[sv][i]>0)
                {
                    push(i);
                }
            }
        }
    }


    cout<<endl;
    cout<<"Enter from which vertex you want to start traversal: ";
    cin>>sv;
    for(int i=1;i<=V;i++)
    {
        visited[i]=0;
    }
    insertQ(sv);
    visited[sv]=1;
    while(front!=(rear+1))
    {
        sv=deleteQ();
        cout<<sv<<" ->";
        for(int i=1;i<=V;i++)
        {
            if((adjMat[sv][i]>0) && visited[i]==0)
            {
                insertQ(i);
                visited[i]=1;
            }
        }
    }


    return 0;
}
