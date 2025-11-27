#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    int vertices;
    list<int>* adj;

public:
    Graph(int v) {
        vertices = v;
        adj = new list<int>[v];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // BFS Traversal
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (int adjNode : adj[node]) {
                if (!visited[adjNode]) {
                    visited[adjNode] = true;
                    q.push(adjNode);
                }
            }
        }
        cout << endl;
    }

    // DFS Traversal helper
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int adjNode : adj[v]) {
            if (!visited[adjNode])
                DFSUtil(adjNode, visited);
        }
    }

    // DFS Traversal
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

// Main function
int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    cout << "Graph Traversal using BFS and DFS:" << endl;
    g.BFS(0);
    g.DFS(0);

    return 0;
}
