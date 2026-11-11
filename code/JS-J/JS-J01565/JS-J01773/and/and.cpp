#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[200005], ans;
void dfs(int x, int answ, int cnt) {
    if (x > n) {
        if (cnt == m) ans = max(ans, answ);
        return ;
    }
    if (cnt == 0) dfs(x + 1, a[x], cnt + 1);
    else dfs(x + 1, answ & a[x], cnt + 1);
    dfs(x + 1, answ, cnt);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 20 || m == 2) {
        dfs(1, 1, 0);
    } else if (m == 1) {
        for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
    } else if (m == n) {
        ans = a[1];
        for (int i = 1; i <= n; i++) ans & a[i];
    }
    cout << ans;
    return 0;
}
