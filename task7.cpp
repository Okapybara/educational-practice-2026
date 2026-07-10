#include <iostream>
#include <vector>
#include <string>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int u, v; //вершины откуда и куда
    long long w; //вес
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    s--;

    // считываем ребра графа и переводим вершины в 0-индексацию
    vector<Edge> edges(m);
    for (int i=0; i<m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--; 
        edges[i].v--;
    }

    // алгоритм Беллмана-Форда: делаем n-1 проход по всем ребрам
    vector<long long> dist(n, INF);
    dist[s] = 0;
    for (int i=0; i<n-1; i++){
        bool update = false;
        for (int j=0; j<m; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            long long w = edges[j].w;

            if (dist[u] < INF){
                if (dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    update = true;
                }
            }
        }
        if (!update) break; // если за итерацию ничего не обновилось, выходим
    }

    // n-й проход для проверки на наличие отрицательного цикла
    bool negative = false;
    for (int i=0; i<m; ++i){
        int u = edges[i].u;
        int v = edges[i].v;
        long long w = edges[i].w;

        if (dist[u] < INF){
            if (dist[u] + w < dist[v]){
                negative = true;
                break;
            }
        }
    }

    // результат
    if (negative) cout << "Negative cycle" << '\n';
    else{
        for (int i=0; i<n; ++i){
            if (dist[i] == INF) cout << "inf" << " ";
            else cout << dist[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}