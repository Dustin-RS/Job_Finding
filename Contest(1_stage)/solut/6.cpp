#include <bits/stdc++.h>
using namespace std;

int n;
void read(){
    cin >> n; // Вводим количество чисел
}

void solver(){
    int mx = n; // Максимальное число до которого нужно выводить
    int mn = n + 1;
    int has = 0; // Переменная для того, чтобы хранить сколько чисел у нас в очереди
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x; // Вводим число
        has++; 
        mn = min(mn, x);
        if (has == mx - mn + 1){ // Если в наборе ровно столько чисел сколько и mx - mn + 1, что означает, что все числа [mn, mx] встречаются
            for (int j = mx; j >= mn; j--) cout << j << " "; // Выведем их
            cout << endl;
            has = 0; // Обнулим очерель
            mx = mn - 1; // Теперь у нас новое максимальное число до которого нужно выводить
            mn = n + 1;
        }else{
            cout << endl; 
        }
    }
}   

void solve(){
    read(); 
    
    solver(); 
}

int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0); 
    solve();
}