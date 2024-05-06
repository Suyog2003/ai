#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

class Graph
{
private:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V) : V(V)
    {
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight)
    {
        adjList[u].push_back({v, weight});
        // For undirected graph, uncomment the next line
        // adjList[v].push_back({u, weight});
    }

    // Function to perform Dijkstra's algorithm
    void dijkstra(int source)
    {
        vector<int> dist(V, INF);
        vector<bool> visited(V, false);

        // Priority queue to store vertex-distance pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Add source vertex to the priority queue
        pq.push({0, source});
        dist[source] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            // If vertex u is already visited, skip
            if (visited[u])
                continue;

            // Mark vertex u as visited
            visited[u] = true;

            // Update the distance of all adjacent vertices of u
            for (const auto &edge : adjList[u])
            {
                int v = edge.first;
                int weight = edge.second;
                if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print the shortest distances from the source vertex
        cout << "Shortest distances from vertex " << source << ":\n";
        for (int i = 0; i < V; ++i)
        {
            if (dist[i] == INF)
                cout << i << ": INF\n";
            else
                cout << i << ": " << dist[i] << "\n";
        }
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter the edges and weights (source destination weight):\n";
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    graph.dijkstra(source);

    return 0;
}
