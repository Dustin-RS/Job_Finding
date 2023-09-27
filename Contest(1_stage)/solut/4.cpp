#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], b[N], c[N], qx[N], qy[N], qz[N];
int n, q;
void read(){ // ввод
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++){
        cin >> qx[i];
    }
    for (int i = 1; i <= q; i++){
        cin >> qy[i];
    }
    for (int i = 1; i <= q; i++){
        cin >> qz[i];
    }
}
void solver(){
    
    vector <pair <int, int>> with_education;
    vector <pair <int, int>> without_education;
    for (int i = 1; i <= n; i++){
        if (b[i]) with_education.push_back({a[i], i}); // добавляем пары {a[i], i} которые просят образование 
        else without_education.push_back({a[i], i});// добавляем пары {a[i], i} которые просят без образование
    }
    sort(with_education.begin(), with_education.end()); // Отсортирвем 
    sort(without_education.begin(), without_education.end());
    vector <int> pref_ans_with_education; // Префиксные минимумы по второму аргументу для with_education
    vector <int> pref_ans_without_education;// Префиксные минимумы по второму аргументу для without_education

    for (int i = 0; i < with_education.size(); i++){ // Подсчитаем префиксные минимумы
        pref_ans_with_education.push_back(with_education[i].second);
        if (i > 0) pref_ans_with_education[i] = min(pref_ans_with_education[i], pref_ans_with_education[i - 1]);
    }
    for (int i = 0; i < without_education.size(); i++){
        pref_ans_without_education.push_back(without_education[i].second);
        if (i > 0) pref_ans_without_education[i] = min(pref_ans_without_education[i], pref_ans_without_education[i - 1]);
    }
    

    
    for (int it = 1; it <= q; it++){
       int x = qx[it], y = qy[it], z = qz[it];
        
        int ans = n + 1; // Пока делаем ответ n + 1
        if (z > 0 && c[z] == 1) ans = z; // Заранее если без требований можем попасть в страну

        int pos_with_education = upper_bound(with_education.begin(), with_education.end(), make_pair(x + 1, 0)) - with_education.begin(); // Ищем максимальную позиция, такую что туда можем попасть по доходу и образование
        int pos_without_education = upper_bound(without_education.begin(), without_education.end(), make_pair(x + 1, 0)) - without_education.begin(); // Ищем максимальную позиция, такую что туда можем попасть по доходу и без образование
        pos_with_education--;
        pos_without_education--;
        
        if (pos_without_education >= 0) ans = min(ans, pref_ans_without_education[pos_without_education]); // Тогда без образнивае пойдем туда где минимальный второй аргумент который говорил об индексе страны
        if (y && pos_with_education >= 0) ans = min(ans, pref_ans_with_education[pos_with_education]); // Если у нас есть образование то так же попытаемся обновить
        if (ans == n + 1) ans = 0; // Если вообще никуда не смогли попасть от ответ 0
        cout << ans << " ";        
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