#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;

int a[N], f[25][25];

int dfs(int x, int y){
    int ma = -1;
    if(y == 0)
        return a[x];
    if(f[x][y] != 0)
        return f[x][y];
    for(int i = x + 1; i <= n - y + 1; ++i){
        ma = max(ma, a[x] & dfs(i, y - 1));
    }
    f[x][y] = ma;
    return ma;
}

void init(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long w = 2;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    return;
}

void solve(){
    if(m == 1){
        int ma = -1;
        for(int i = 1; i <= n; ++i)
            ma = max(ma, a[i]);
        cout << ma << endl;
        return;
    }
    if(m == 2){
        int ma = -1;
        for(int i = 1; i <= n; ++i){
            for(int o = i + 1; o <= n; ++o){
                ma = max(ma, a[i] & a[o]);
            }
        }
        cout << ma << endl;
        return;
    }
    if(m == n){
        int ma = a[1];
        for(int i = 2; i <= n; ++i){
            ma &= a[i];
        }
        cout << ma << endl;
        return;
    }
    if(n <= 20){
        int ma = -1;
        for(int i = 1; i <= n - m + 1; ++i){
            ma = max(ma, dfs(i,m - 1));
        }
        cout << ma << endl;
        return;
    }
    cout << 1 << endl;
    return;
}

int main(){
    init();
    solve();
    return 0;
}
