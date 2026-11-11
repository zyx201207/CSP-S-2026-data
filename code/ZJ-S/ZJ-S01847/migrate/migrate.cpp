#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int C, T, n, d, a[N], sz[N], vis[N], f[N], g[N];
vector<int> e[N];
/*
f: 以 i 为终点 恰有两条最短路的方案数
g: 以 i 为终点 恰有一条最短路的方案数
*/
int get(int x) {
    int p = upper_bound(a + 1, a + n + 1, x + d) - a;
    if (p == n + 1) return p;
    return p - 1;
}
int get2(int x) {
    int p = lower_bound(a + 1, a + n + 1, x - d) - a;
    return p;
}
void dfs(int x) {
    g[x] = 1;
    for (int y : e[x]) dfs(y);
    if (e[x].size()) g[x] += g[e[x][0]];
}
bool check(int u, int v) {
    vector<int> vec;
    int st = u;
    while (st <= v) {
        vec.push_back(st);
        st = a[get(st)];
    }
    vec.push_back(v);
    int len = vec.size();
    if (len <= 2) return 0;
    for (int i = 2; i < len; ++i) {
        if (get2(vec[i]) <= vec[i - 1]) return 0;
    } 
    return 1;
}
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n + 1; ++i) sz[i] = vis[i] = f[i] = g[i] = 0, e[i].clear();
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[n + 1] = 2e18;
    for (int i = 1; i <= n; ++i) {
        int pos = get(a[i]);
        if (pos == i || pos > n) pos = n + 1;
        // cout << pos << '\n';
        e[pos].push_back(i);
    }
    dfs(n + 1);
    // for (int i = 1; i <= n; ++i) {
    //     int pos = get2(a[i]);
    //     cout << pos << '\n';
    //     if (pos == i) continue;
    //     g[i] += i - pos - (get(a[pos]) == i);
    // }
    for (int i = 1; i <= n; ++i) {
        int pos = get2(a[i]);
        if (pos == i) continue;
        if (pos == i - 1) f[i] = f[pos];
        else {
            f[i] = g[pos + 1] + f[pos];
            // if (get(a[pos]) != pos + 1) f[i]--;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << f[i] << ' ' << g[i] << '\n';
        ans += f[i];
    }
    cout << ans << '\n';
    // int ans = 0;
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = i + 1; j <= n; ++j) {
    //         if (check(a[i], a[j])) ans++;
    //     }
    // }
    // cout << ans << '\n';
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> C >> T;
    while (T--) solve();
}
