#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAX 100

int parent[MAX];

// Disjoint Set Find
int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

// Disjoint Set Union
void union_sets(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv)
        parent[pu] = pv;
}
int kargerMinCut(int n, vector<pair<int, int>> &edges) {
    // Initialize each vertex as its own parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int vertices = n; // initially n components

    int m = edges.size(); // number of edges

    // Randomly contract until only 2 components remain
    while (vertices > 2) {
        int idx = rand() % m;
        int u = edges[idx].first;
        int v = edges[idx].second;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) {
            union_sets(set_u, set_v);
            vertices--;
        }
    }

    // Count crossing edges (cut size)
    int cutEdges = 0;
    for (auto &e : edges) {
        int u = e.first;
        int v = e.second;
        if (find(u) != find(v))
            cutEdges++;
    }

    return cutEdges;
}
int main() {
    srand(time(0));

    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int adj[MAX][MAX];

    cout << "Enter adjacency matrix (0/1):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    // Convert matrix to edge list
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj[i][j]) {
                edges.push_back({i, j});
            }
        }
    }

    int minCut = edges.size();

    // Run Karger's multiple times to reduce error
    int iterations = n * n * 100;
    for (int i = 0; i < iterations; i++) {
        int result = kargerMinCut(n, edges);
        if (result < minCut)
            minCut = result;
    }

    cout << "\nApproximate Min Cut: " << minCut << endl;

    return 0;
}


