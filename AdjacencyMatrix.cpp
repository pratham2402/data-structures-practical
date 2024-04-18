#include <iostream>
#include <vector>
using namespace std;

void scangraph(vector<vector<int>>& adjMat, char Dir) {
    int V, E;
    cout << "Enter How many vertices? ";
    cin >> V;

    adjMat.resize(V + 1, vector<int>(V + 1, 0));

    cout << "Enter Number of edges: ";
    cin >> E;

    int sr, ds, wt;

    for (int i = 0; i < E; i++) {
        cout << "Enter source, destination, and weight of the edge " << i + 1 << ": ";
        cin >> sr >> ds >> wt;

        if (sr >= 1 && sr <= V && ds >= 1 && ds <= V) 
        {
            adjMat[sr][ds] = wt;
            if (Dir == 'U') 
                adjMat[ds][sr] = wt;
        } 
        else 
        {
            cout << "Enter correct vertices for the edge." << endl;
            i--; 
        }
    }
}

void displayg(const vector<vector<int>>& adjMat) {
    cout << "Adjacency Matrix is: " << endl;
    for (size_t i = 1; i < adjMat.size(); ++i) {
        for (size_t j = 1; j < adjMat[i].size(); ++j) 
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int ch, cont;
    char Dir;
    vector<vector<int>> adjMat;

    do {
        cout << endl << "Menu";
        cout << endl << "1. Create graph using adjacency matrix";
        cout << endl << "2. Display Graph";
        cout << endl << "Enter choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Graph is directed/undirected (D/U): ";
                cin >> Dir;
                scangraph(adjMat, Dir);
                break;
            case 2:
                displayg(adjMat);
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }

        cout << endl << "Do you want to continue? (1 for continue): ";
        cin >> cont;
    } while(cont == 1);

    return 0;
}
