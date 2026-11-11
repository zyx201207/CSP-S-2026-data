#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 2e5 + 5;
LL n, m, a[N], dfsans = 0;

bool cmp(LL a, LL b) {
    return a > b;
}

void dfs(int x, int dep, LL val) {
    if(dep == m) {
        dfsans = max(dfsans, val);
    }
    for(int i = x + 1; i <= n; i++) {
        dfs(i, dep + 1, val & a[i]);
    }
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    
    // freopen("and2.in", "r", stdin);
    // freopen("and2.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n <= 20) {
        dfs(0, 0, LONG_LONG_MAX);
        cout << dfsans;
    } else if(m == 1) {
        sort(a + 1, a + n + 1, cmp);
        cout << a[1];
    } else if(m == n) {
        LL ans = LONG_LONG_MAX;
        for(int i = 1; i <= n; i++)
            ans &= a[i];
        cout << ans;
    } else if(n <= 2000 && m == 2) {
        LL ans = -1;
        for(int i = 1; i <= n; i++) 
            for(int j = i + 1; j <= n; j++)
                ans = max(ans, a[i] & a[j]);
        cout << ans;
    } else {
        sort(a + 1, a + n + 1, cmp);
        LL ans = LONG_LONG_MAX;
        for(int i = 1; i <= m; i++) {
            ans &= a[i];
        }
        cout << ans;
        // CCF 能不能在这里给我 eps 分啊, 测过第四个样例了
        // 坏了 第五个过不去
    }
    return 0;
}