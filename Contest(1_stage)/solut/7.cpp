#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n;
long long t;
int k[N];
vector <long long> p[N];
vector <int> h[N];
void read(){ // Входные данные
    cin >> n >> t; 
    for (int i = 1; i <= n; i++){
        cin >> k[i];
        p[i].resize(k[i] + 1);
        h[i].resize(k[i] + 1);
        for (int j = 1; j <= k[i]; j++){
            cin >> p[i][j] >> h[i][j];
        }
    }
}
bool ok(int min_joy){
    const int INF = 1e18;
    long long sum = 0;
    for (int i = 1; i <= n; i++){
        long long mn = INF; 
        for (int j = 1; j <= k[i]; j++){ // Для i-того друга мы среди всех подарков у которых радость хотя-бы min_joy выбираем с минимальной стоимостью
            if (h[i][j] >= min_joy){ 
                mn = min(mn, p[i][j]);
            }
        }
        if (mn == INF) return false; // Если не подарка с радостью хотя-бы min_joy то вернем false
        sum += mn; // Добавляем в сумму стоиомсть среди подходящих подарков
    }
    return sum <= t; // Сумма должна быть не больше чем сумма денег которое у нас есть
}
void solver(){
    int l = 0, r = 1e5 + 10; // границы бинарного поиска
    int ans = 0;
    while (l <= r){
        int mid = (l + r) >> 1; 
        if (ok(mid)){ // Если можно сделать, чтобы у друзей радость была хотя-бы mid
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
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