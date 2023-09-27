#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
long long p[N];
int n;
void read(){
    cin >> n; // Вводим количество чисел
    for (int i = 1; i <= n; i++){
        cin >> p[i]; // Вводим сами числа
    }
}
pair <int, int> suff[N]; 
void solver(){
    for (int i = 1; i <= n; i++) suff[i] = {-1, -1}; // suff[i] = {s2, b2}, где дробь p[s2] / p[b2] максимальное. А также i < b2 < s2
    int idMx = n;

    for (int i = n - 1; i >= 1; i--){
        suff[i] = {idMx, i}; // Присваиваем 
        if (suff[i + 1].first != -1 && p[suff[i + 1].first] * p[suff[i].second] > p[suff[i].first] * p[suff[i + 1].second]){ // необходимое условие обновление suff[i] через suff[i + 1]
            suff[i] = suff[i + 1];
        }
        if (p[i] > p[idMx]) idMx = i; // На суффиксе храним индекс максимального числа
    }
    int idMn = 1; // Позиция минимального числа на префиксе 
    pair <long long, long long> ans = {-1, -1}; // будем хранить ответ в виде дроби, где первое число - это числитель, а второе знаменатель
    vector <int> idsAns; // Будем хранить индексы которые вошли в ответ 
    for (int i = 2; i <= n; i++){
        if (ans.first == -1 || ans.first * p[idMn] < ans.second * p[i]){ // Если наш ответ до этого меньше чем дробь p[i] / p[idMn]
            ans.first = p[i];
            ans.second = p[idMn];
            idsAns.clear();
            idsAns = {idMn, i};
        }
        if (suff[i + 1].first != -1){ // Если справа от i есть два индекса {s2, b2}, такие, что дробь p[s2] / p[b2] максимальное
            pair <long long, long long> ch = {p[suff[i + 1].first], p[suff[i + 1].second]}; // Перепишем в дробь числа которые стояли на позиции s2, b2
            if (ans.first == -1 || ans.first * ch.second * p[idMn] < ans.second * ch.first * p[i]){ // Необхоимое условие обновление ответа от дроби p[i] * p[s2] / p[idMn] / p[b2], где i = s1, idMn = b1;
                ans.first = ch.first * p[i];
                ans.second = ch.second * p[idMn];
                idsAns.clear();
                idsAns = {idMn, i, suff[i + 1].second, suff[i + 1].first};
            }
        }
        if (p[idMn] > p[i]) idMn = i;
    }
    if (idsAns.empty() || ans.first <= ans.second){ // То что мы нашли могло быть не выгоднее чем просто вывести K = 0
        cout << 0 << endl;
        return;
    }
    
    cout << idsAns.size() / 2 << endl;
    for (int i = 0; i < idsAns.size(); i++){
        if (i == 2) cout << endl;
        cout << idsAns[i] << " ";
        
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