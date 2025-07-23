#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 100

int g[MAX][MAX];      // Adjacency matrix
int e[MAX * MAX][2];  // Edge list
int parent[MAX];      // Union-Find parent
int n, m;             // n = number of nodes, m = number of edges

// Find function for disjoint set
int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

// Union function for disjoint set
void union_sets(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv)
        parent[pu] = pv;
}

int main() {
    srand(time(0));

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    // Create edge list from adjacency matrix
    m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (g[i][j] == 1) {
                e[m][0] = i;
                e[m][1] = j;
                m++;
            }
        }
    }

    int minCut = m; // Initialize with max possible cut

    // Run Karger's multiple times to improve probability
    for (int trial = 0; trial < n * n * 10; trial++) {

        // Initialize disjoint set
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        // Repeat until only 2 components remain
        while (components > 2) {
            int x = rand() % m;
            int u = e[x][0];
            int v = e[x][1];

            if (find(u) != find(v)) {
                union_sets(u, v);
                components--;
            }
        }

        // Count cross-edges between two remaining components
        int cut = 0;
        for (int i = 0; i < m; i++) {
            int u = e[i][0];
            int v = e[i][1];
            if (find(u) != find(v))
                cut++;
        }

        if (cut < minCut)
            minCut = cut;
    }

    cout << "\nMinimum Cut (approx): " << minCut << endl;

    return 0;
}
