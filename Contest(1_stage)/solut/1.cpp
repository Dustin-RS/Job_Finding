#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, k;
int c[N], r[N], s[N];
void read(){
    cin >> n; // Ввод количество клавиш
    for (int i = 1; i <= n; i++){
        cin >> c[i]; 
    }
    for (int i = 1; i <= n; i++){
        cin >> r[i]; // ряд где стоит символ c[i] 
    }
    cin >> k;
    for (int i = 1; i <= k; i++){
        cin >> s[i];
    }
}

void solver(){
    map <int, int> where;
    for (int i = 1; i <= n; i++){
        where[c[i]] = i; // символ c[i] на клавиатуре стоит на i - той позиции в входных данных
    }
    int ans = 0;
    for (int i = 2; i <= k; i++){
        if (r[where[s[i - 1]]] != r[where[s[i]]]){ // Если ряды где стоят символы s[i - 1] и s[i] различны, тогда увеличим ответ
            ans++;
        }
    }
    cout << ans << endl; 
}   

void solve(){
    read(); 
    solver(); 
}

int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0); 
    solve();
}