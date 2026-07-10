#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long M = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m;

    // исходная матрица чисел
    vector<vector<int>> matr(n, vector<int>(m));
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            cin >> matr[i][j];
        }
    }

    // пути для первого столбца и первой строки
    vector<vector<int>> way(n, vector<int>(m));
    way[0][0] = matr[0][0];
    for (int j = 1; j<m; j++) {
        way[0][j] = way[0][j-1] + matr[0][j];
    }
    for (int i = 1; i<n; i++) {
        way[i][0] = way[i-1][0] + matr[i][0];
    }

    // максимальная сумма для каждой клетки
    for (int i=1; i<n; i++){
        for (int j=1; j<m; j++){
            int best = max({way[i-1][j], way[i][j-1], way[i-1][j-1]});
            way[i][j] = matr[i][j] + best;
        }
    }

    //правый нижний угол
    cout << way[n-1][m-1] << '\n';
    return 0;
}