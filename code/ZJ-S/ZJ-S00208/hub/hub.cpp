#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, k, C, f[N], d[N], ans;
vector<int> e[N];
int find(int u) {
    return ((f[u] == u) ? u : f[u] = find(f[u]));
}
void dfs(int u, int pre, int t) {
    d[u] = d[pre] + 1;// cout << u << " " << pre << "\n";
    if ((t >> u - 1) & 1) ans = min(ans, d[u]);
    for (int v : e[u]) {
        if (v != pre) dfs(v, u, t);
    }
}
void solve() {
    cin >> n >> k; int x, y;
    for (int i = 1;i <= n;i ++) e[i].clear();
    for (int i = 1;i < n;i ++) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if (C > 3) return ; int minn = 10000;
    for (int t = 0;t < (1 << n);t ++) {
        // cout << t << "\n";
        int tot = 0, x = t;
        while (x) x -= (x & -x), tot ++;
        if (tot > k) continue;
        for (int i = 1;i <= n;i ++) f[i] = i;
        for (int i = 1;i <= n;i ++) {
            if ((t >> i - 1) & 1) {
                for (auto v : e[i]) {
                    if (!((t >> v - 1) & 1)) continue;
                    f[find(v)] = find(i);
                }
            } 
        } tot = 0;
        for (int i = 1;i <= n;i ++) if ((t >> i - 1) & 1) tot += (find(i) == i);
        if (tot > 2) continue; tot = 0;
            // for (int i = 1;i <= n;i ++) cout << ((t >> i - 1) & 1) << " "; cout << "\n";
        for (int i = 1;i <= n;i ++) {
            ans = 1000; dfs(i, 0, t); tot = max(tot, ans);
        }  minn = min(minn, tot);
        // if (tot == 2) {
        //     for (int i = 1;i <= n;i ++) cout << ((t >> i - 1) & 1) << " "; cout << "\n";

        // }
    } cout << minn - 1 << "\n";
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int T; cin >> C >> T;
    while (T --) solve();
}