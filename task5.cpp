#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        // обработака случая с 0 и 1
        if (n==0){
            cout << 10 << '\n';
            continue;
        }
    
        if (n==1){
            cout << 1 << '\n';
            continue;
        }

        // раскладываем число на однозначные множители от 9 до 2
        vector<int> digits;
        for (int d=9; d >= 2; d--) {
            while (n%d == 0) {
                digits.push_back(d);
                n /= d;
            }
        }

        if (n != 1) cout << -1 << '\n';
        // вывод цифр в обратном порядке для минимального числа
        else{
            for (int i = digits.size()-1; i >= 0; i--){
                cout << digits[i];
            }
            cout << '\n';
        }
    }
    return 0;
}