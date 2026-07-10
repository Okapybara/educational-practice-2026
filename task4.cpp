#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector <long long> a(n, 0);

    // массив разностей для быстрого обновления отрезков
    for (int i=0; i<q; i++){
        int l, r;
        long long v;
        cin >> l >> r >> v;

        l--;
        r--;

        // начало и конец прибавления значения
        a[l] += v;
        if (r+1 < n) {
            a[r+1] -= v;
        }
    }

    long long curr = 0;
    // восстанавоиваем итоговый массив через префиксные суммы
    for (int i=1; i<n; i++){
        a[i] += a[i-1];

    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << '\n';

    return 0;
}