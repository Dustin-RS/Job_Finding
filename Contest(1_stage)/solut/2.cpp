#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n;
long long x, t;
long long a[N];
void read(){
    cin >> n >> x >> t;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solver(){
    vector <pair <long long, int>> b;
    for (int i = 1; i <= n; i++){
        b.push_back({abs(a[i] - x), i}); // Запишем сколько нам необходимо, чтобы сделать a[i] = x, а также индекс i
    }
    sort(b.begin(), b.end()); // Отсортируем их, так как выгодно брать те в которых меньше всего операций чтобы сделать равным x
    vector <int> ans;
    for (int i = 0; i < b.size(); i++){
        if (b[i].first > t) break;
        ans.push_back(b[i].second); // Запоминаем индекс числа которого нам давали 
        t -= b[i].first;
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
}   

void solve(){
    read(); 
    solver(); 
}

int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0); 
    solve();
}