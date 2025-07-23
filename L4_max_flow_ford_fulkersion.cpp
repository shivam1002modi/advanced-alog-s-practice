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




























// flow =0
// while there exist augmenting  path from s to t in g 
// {
//     add bottleneck to flow 
//     update g
// } 




// flow =0
// while(BFS(rg,s,t,parent)==true)
// {
//         pf=infinity 
//     for (v=t;v!=s;v= parent[v])
//     {
//         u = parent[v];
//         pf = Min(pf,rg[u][v])
//     }
//     for(v=t;v!=s;v=parent[v])
//     {
//         rg[u][v]-=pf;
//         rg[v][u]+=pf;
//     }
//     flow+=pf
// }

// int main()
// {
// int fordfulkerson(int G[n][n], int s , int t)
// {
//     create rgraph[n][n]
//     for (v=0;<n;u++)
//     {
//         for(v=0;v<n;v++)
//         {
//             rgraph[u][v]=G[u][v];
//         }
//     }

//     create parent[n]//parent will be assigned by bfs 
//     max_flow = 0;
//     while(bfs(rgraph,s,t,parent))
//     {
//         path_flow=infinity;
//         for(v=tlv!=s;v=parent[v])
//         {
//             u=parent[v];
//             path_fow= Min(path_flow,rgraph[u][v]);
//         }
//     }
//     for (v=t;v!=s;v = parent[v])
//     {
//         u=parent[v];
//         rgraph[u][v]-=pathflow;
//         rgraph[v][u]+=pathflow;
//     }
//     max_flow+=path_flow;
// }return max flow;

// }

// bool bfs (rgraph[n][n],s,t,parent[n])
// {
//     visited[i]= 0
//     foor every i =0 to (n-1)
//     queue q ;
//     enqueue(q,s);
//     visited[s]=1;
//     parent[s]=-1;
//     while (q is not empty )
//     {
//         u = dequeue(q);
//         for (v=0;v<n;v++)
//         {
//             if(visited[v]==0 && rgraph[u][v]>0)
//             {
//                 if(v==t)
//                 {
//                     parent[v]=u;
//                     return true;
//                 }
//                 enqueue(q,v);
//                 visited[v] = 1;
//                 parent[v]=u
//             }
//         }
//     }return false;
// }