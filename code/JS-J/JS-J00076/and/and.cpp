#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0), cin.tie(0)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define dep(i, a, b) for (int i = (a); i >= (b); i--)
#define il inline
using namespace std;
const int MAXN = 2e5 + 5;
int n, m;
ll a[MAXN], dp[MAXN][2], ans, cnt;
il void Dfs(int u, int cnt, ll res) {
    if (u > n) {
        return ;
    }
    if (cnt == m) {
        ans = max(ans, res);
        return ;
    }
    if (cnt == 0) {
        Dfs(u + 1, cnt + 1, a[u]);
        Dfs(u + 1, cnt, res);
        return ;
    } else {
        Dfs(u + 1, cnt + 1, (res & a[u]));
        Dfs(u + 1, cnt, res);
        return ;
    }
    return ;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    IOS;
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> a[i];
        if (a[i] == 0) cnt++;
    }
    if (n - cnt < m) {
        cout << 0 << endl;
        return 0;
    }
    if (n <= 20) {
        Dfs(1, 0, 0);
    }
    else if (n == 2) {
        rep(i, 1, n) {
            rep(j, i + 1, n) {rep(i, 1, n) {
            rep(j, i + 1, n) {
                ans = max(ans, (a[i] & a[j]));
            }
        }
                ans = max(ans, (a[i] & a[j]));
            }
        }
    }
    else if (n == 1) {
        rep(i, 1, n) ans = max(ans, a[i]);
        cout << ans << endl;
    }
    else if (m == n) {
        ans = a[1];
        rep(i, 2, n) ans = (ans & a[i]);
        cout << ans << endl;
    } else {
        Dfs(1, 0, 0);
    }
    cout << ans << endl;
    return 0;
}
