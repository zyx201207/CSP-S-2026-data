# include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 10;
int n, m, x[MAX], bucket[MAX];
stack <int> saving;
bool f[MAX];
bool isA(int n){
    for (int i = 1; i <= n; i++){
        if (x[i] > x[i + 1]) return false;
    }
    return true;
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> x[i];
    }
    if (m == 1){
        cout << n;
        return 0;
    }
    if (m == 2){
        if (x[n] == 1){
            int cnt = 0;
            for (int i = 1; i <= n; i++){
                cnt += (x[i] == 2);
            }
            cout << n << ' ' << cnt;
        }
        else{
            int cnt = 0;
            for (int i = 1; i <= n; i++){
                cnt += (x[i] == 1);
            }
            cout << cnt << ' ' << n;
        }
        return 0;
    }
    if (isA(n)){
        for (int i = 1; i <= m; i++) cout << n << ' ';
        return 0;
    }
    for (int r = 1; r <= n; r++){
        memset(f, false, sizeof f);
        while (!saving.empty()) saving.pop();
        for (int i = r; i <= n; i++){
            int tar = x[i];
            if (f[tar]){
                while (saving.top() != tar){
                    f[saving.top()] = false;
                    saving.pop();
                }
            }
            else{
                saving.push(tar);
                f[tar] = true;
            }
        }
        for (int i = 1; i <= m; i++){
            bucket[i] += f[i];
        }
    }
    for (int i = 1; i <= m; i++){
        cout << bucket[i] << ' ';
    }
    return 0;
}
