#include <iostream>
#include <queue>
using namespace std;

const int N = 5;

string buildings[N] =
 {
    "Main Gate",
    "Library",
    "Canteen",
    "Laboratory",
    "Admin Block"
};

int adj[N][N] = 
{
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {0, 1, 0, 1, 0}
};

void BFS(int start)
{
    bool visited[N] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << buildings[current] << " ";

        for (int i = 0; i < N; i++)
        {
            if (adj[current][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
}

void DFSUtil(int current, bool visited[])
{
    visited[current] = true;
    cout << buildings[current] << " ";

    for (int i = 0; i < N; i++)
    {
        if (adj[current][i] == 1 && !visited[i])
        {
            DFSUtil(i, visited);
        }
    }
}

void DFS(int start)
{
    bool visited[N] = {false};

    cout << "DFS Traversal: ";
    DFSUtil(start, visited);
    cout << endl;
}

int main()
{
    int start;

    cout << "Campus Building Connectivity\n";
    cout << "----------------------------\n";

    cout << "Building List:\n";

    for (int i = 0; i < N; i++)
    {
        cout << i << ". " << buildings[i] << endl;
    }

    cout << "\nEnter starting building number (0-4): ";
    cin >> start;

    if (start < 0 || start >= N)
    {
        cout << "Invalid building number!" << endl;
        return 0;
    }

    BFS(start);
    DFS(start);

    return 0;
}
