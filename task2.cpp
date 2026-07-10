#include <iostream>
#include <queue>

int main(){
    int n;
    std::cin >> n;

    // создается очередь, где на вершине всегда минимальный элемент
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minclans;
    for (int i = 0; i < n; i++){
        long long a;
        std::cin >> a;
        minclans.push(a);
    }

    // объединение элементов
    for (int j = 0; j < n-1; j++){
        // два самых маленьких числа
        long long a = minclans.top();
        minclans.pop();
        long long b = minclans.top();
        minclans.pop();

        std::cout << a << " " << b << '\n';
        minclans.push(a+b); // их сумма возвращается обратно в очередь
    }

    return 0;
}