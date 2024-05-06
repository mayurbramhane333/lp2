#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[100];
vector<bool> vis(100);
queue<int> q;
void bfs() {

    if (q.empty())
    {
        return;
        
    }
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (int v : vec[u]) {
        if (!vis[v]) {
            q.push(v);
            vis[v] = true;
        }
    }
    bfs();
    
}

void dfs(int u) {
    vis[u] = true;
    cout << u << " ";

    for (int v : vec[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, edge, u, v;
    cout << "Enter Number of Vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> edge;

    for (int i = 0; i < edge; i++) {
        cout << "Enter the source index: ";
        cin >> u;
        cout << "Enter the destination index: ";
        cin >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    cout << "\nGraph\n";

    for (int i = 1; i <= n; i++) {
        cout << i << "-->";
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nBFS Traversal: ";
    q.push(1);
    vis[1]=true;
    bfs(); // Starting BFS from node 1

    // Reset visited array
    fill(vis.begin(), vis.end(), false);

    cout << "\nDFS Traversal: ";
    dfs(1); // Starting DFS from node 1

    return 0;
}
