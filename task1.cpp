#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    long long res = 0;
    std::cin >> n;

    // длины сторон
    std::vector<int> a(n);
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    // сортировка для применения неравенства треугольника
    std::sort(a.begin(), a.end());
    
    // перебор всех троек (i,j,k) с проверкой условия
    for (int i=0; i<(n-2); i++){
        if (a[i] == 0) continue; // пропуск нулевых значений
        for (int j=i+1; j < (n-1); j++){
            for (int k=j+1; k<n; k++){
                if (a[i]+a[j]>a[k]){
                    res++;
                }
                else break;
            }
        }
    }
    std::cout << res << '\n';

    return 0;
}