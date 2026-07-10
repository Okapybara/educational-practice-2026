#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    // ребра и список смежности дл неориентированного графа
    vector<vector<int>> graph(n+1);
    for (int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dist(n+1, -1);
    queue<int> q;

    // стартовая вершина
    dist[k] = 0;
    q.push(k);

    // обход в ширину для поиска кратчайших путей, просмотр соседей
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i=0; i<graph[curr].size(); i++) {
            int neighbor = graph[curr][i];
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[curr]+1;
                q.push(neighbor);
            }
        }
    }

    // от вершины k до остальных
    for (int i=1; i<=n; ++i) {
        cout << dist[i] << " ";
    }

    cout << '\n';

    return 0;
}