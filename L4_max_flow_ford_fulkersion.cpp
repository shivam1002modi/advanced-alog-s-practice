#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;

#define N 100  // You can set the max number of vertices

// BFS to find if there is a path from source to sink
bool bfs(int rGraph[N][N], int s, int t, int parent[], int n) {
    bool visited[N];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                parent[v] = u;
                if (v == t)
                    return true;
                q.push(v);
                visited[v] = true;
            }
        }
    }

    return false;
}

// Ford-Fulkerson Algorithm
int fordFulkerson(int G[N][N], int s, int t, int n) {
    int rGraph[N][N]; // Residual graph
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            rGraph[u][v] = G[u][v];

    int parent[N];  // Stores path
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent, n)) {
        int path_flow = INT_MAX;

        // Find minimum residual capacity of the path
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // Update residual capacities
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

// Sample usage
int main() {
    int n = 6; // Number of vertices

    // Example graph
    int G[N][N] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;
    cout << "The maximum possible flow is: " << fordFulkerson(G, source, sink, n) << endl;

    return 0;
}
