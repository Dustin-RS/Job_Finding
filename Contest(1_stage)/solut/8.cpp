#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 1;
const long long INF = 1e18;
long long k;
int n;
long long a[N];
void read(){ // Ввод данных
    cin >> k;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}
void solver(){
    long long ans = INF;
    for (int i = 30; i < n; i++){ // При i >= 30 мы можем взять одинь хенкаль
        ans = min(ans, a[i]);
    }   
    n = min(n, 30);
    long long sum = 0; // То сколько мы потратили до этого 
    for (int i = n - 1; i >= 0; i--){
        bool ok = true; // Предполагаем, что i можно взять 
        for (int j = 0; j < i; j++){
            long long need = (1ll << (i - j));
            if (a[i] > a[j] * need){ // Точно нельзя брать, так как можно и дешевле 
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        long long step = (11ll << i); // (2^i)
        ans = min(ans, ((k + step - 1) / step) * a[i] + sum); // Обновляем ответ мы потратим ((k + step - 1) / step) * a[i] на то чтобы сделать k = 0, а также прибавляем сумму которая превела к такому k
        sum += (k / step) * a[i]; // Могли не полностью съесть и оставить k % step, тогда мы заплатили (k / step) * a[i] и решили доесть позже
        k %= step; // Остается k % step
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