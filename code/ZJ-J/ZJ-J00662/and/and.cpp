#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N], n, m, res = INT_MIN;
void dfs(int dep, int cnt, int ans) {
    // cout << dep << '\t' << cnt << '\t' << ans << '\n';
    if (dep > n || cnt > m) {
        if (cnt == m) res = max(res, ans);
        return ;
    }
    if (cnt == 0) dfs(dep+1, cnt+1, a[dep]);
    else dfs(dep+1, cnt+1, (ans & a[dep]));
    dfs(dep+1, cnt, ans); // 不选
}
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0, 0);
    cout << res;
    return 0;
}