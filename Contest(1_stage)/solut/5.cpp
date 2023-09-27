#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int M = 8;
const int MOD = 1e9 + 7;

int dp[N][(1 << M)];
int mult(int x, int y){ // Умножение по модулю
    long long res = x * 1ll * y;
    return res % MOD;
}
void add(int &x, int y){ // Сумма по модулю 
    x += y;
    x %= MOD;
}
int bin(int a, int n){ // Бинарное возведение в степень
    int res = 1;
    while (n > 0){
        if (n % 2){
            res = mult(res, a);
        }
        a = mult(a, a);
        n /= 2;
    }
    return res;
}
int n, k;
void read(){ // Ввод 
    cin >> n >> k;
}
int get_mask_dels(int x){ // Функция которая вернет маску. Где бит на позиции i, означает, что простое число primes[i] делится на x нечетное количество раз
    vector <int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
    int mask = 0;
    for (int i = 0; i < primes.size(); i++){
        while (x % primes[i] == 0){
            x /= primes[i];
            mask ^= (1 << i);
        }
    }
    return mask;
}

void solver(){
    dp[0][0] = 1; // Начальное состояние 

    for (int i = 1; i <= n; i++){ // какой по счету игра
        for (int j = 1; j <= k; j++){ // перебираем какое число выпадет 
            int newMask = get_mask_dels(j); // Смотрю маску для числа j
            int p = bin(k, MOD - 2); // Так как равновероятно, то нужно умножать на 1 / k, а это k^(MOD - 2) % MOD
            for (int mask = 0; mask < (1 << M); mask++){ // Перебираю старую маску 
                add(dp[i][(mask ^ newMask)], mult(dp[i - 1][mask], p)); // Обновляю новое состояние через старое
            }
        }
    }
    
    cout << dp[n][0] << endl; // Ответ в состояние [n][0], так как n - игр было и не одно число не входит в произведение в нечетной степени
}   

void solve(){
    read(); 
    solver(); 
}
int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0); 
    solve();
}