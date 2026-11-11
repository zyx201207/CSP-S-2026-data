#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c;
int n, k, ans;
vector<int> e[N];
namespace Work1 {
    bool p[N], vis[N];
    void ck(int u, int fa) {
        vis[u] = 1;
        for (auto v : e[u]) {
            if (!p[v] || v == fa)
                continue;
            ck(v, u);
        }
    }
    int sol(int u, int fa) {
        if (p[u])
            return 0;
        int res = 1e9;
        for (auto v : e[u]) {
            if (v == fa)
                continue;
            res = min(res, sol(v, u) + 1);
        }
        return res;
    }
    void dfs(int t, int idx) {
        if (idx > k)
            return ;
        if (t == n + 1) {
            if (idx ^ k)
                return ;
            for (int i = 1; i <= n; i++)
                vis[i] = 0;
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (!p[i] || vis[i])
                    continue;
                ck(i, 0), cnt++;
                if (cnt > 2)
                    return ;
            }
            int res = 0;
            for (int i = 1; i <= n; i++) {
                res = max(res, sol(i, 0));
            }
            ans = min(ans, res);
            return ;
        }
        p[t] = 0;
        dfs(t + 1, idx);
        p[t] = 1;
        dfs(t + 1, idx + 1);
        p[t] = 0;
    }
}
void solve() {
    for (int i = 1; i <= n; i++)
        e[i].clear();
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y), e[y].push_back(x);
    }
    if (k == n) {
        cout << 0 << '\n';
        return ;
    }
    ans = 1e9;
    Work1::dfs(1, 0);
    cout << ans << '\n';
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> c >> t;
    while (t--)
        solve();
    return 0;
}