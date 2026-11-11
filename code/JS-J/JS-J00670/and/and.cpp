#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
using ll = long long;
ll a[MAXN];
int n, m;
ll ans;
void dfs(int cur, int last, ll sum) {
    if (cur > m) {
        ans = max(sum, ans);
        return;
    }

    for (int i = last + 1; i <= n - m + cur; ++i) {
        if (cur == 1) dfs(cur + 1, i, a[i]);
        else dfs(cur + 1, i, a[i] & sum);
    }
}
int main() {
#ifndef PDEBUG
    auto _1 = freopen("and.in", "r", stdin);
    auto _2 = freopen("and.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // cout << "24" << endl;
    dfs(1, 0, 0);
    cout << ans;
}