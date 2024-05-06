#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    vector<vector<int>> adj; // Adjacency List

public:
    Graph(int v) : v(v)
    {
        adj.resize(v);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSUtil(int start, vector<bool> &visited)
    {
        visited[start] = true;
        cout << start << " ";
        for (auto neighbour : adj[start])
        {
            if (!visited[neighbour])
            {
                DFSUtil(neighbour, visited);
            }
        }
    }

    void DFS()
    {
        vector<bool> visited(v, false);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

    void BFS(int start)
    {
        vector<bool> visited(v, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty())
        {
            int v = q.front();
            cout << v << " ";
            q.pop();
            for (auto neighbour : adj[v])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.DFS();
    cout << endl;
    g.BFS(0);
}
