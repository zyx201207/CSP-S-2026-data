#include <bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pll pair <int, int>
#define int long long
#define endl '\n'
using namespace std;
constexpr int N = 2e6 + 10, mod = 1e9 + 7;
inline int input() {
    char c = gc();
    int x = 0, f = 1;
    while (c < '0' or c > '9') {
        if (c == '-') f = -f;
        c = gc();
    }
    while (c >= '0' and c <= '9') x = x * 10 + c - '0', c = gc();
    return x * f;
}
void print(int x) {
    if (x < 0) pc('-'), x = -x;
    if (x > 9) print(x / 10);
    pc(x % 10 + '0');
}
int tc, T, n, k, ans = 0;
bool vis[N], cl[N], flag[N];
vector <int> g[N];
void dfs(int u) {
    for (auto v : g[u]) {
        if (!vis[v] or cl[v]) continue;
        cl[v] = true;
        dfs(v);
    }
    return ;
}
bool check() {
    memset(cl, 0, sizeof(cl));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] and !cl[i]) {
            if (cnt + 1 > 2) return false;
            cl[i] = true;
            dfs(i);
        }
    }
    return true;
}
int bfs(int x) {
    memset(flag, 0, sizeof(flag));
    queue <pll> q;
    while (!q.empty()) q.pop();
    q.push(make_pair(x, 0));
    while (!q.empty()) {
        int u = q.front().first, stp = q.front().second;
        q.pop();
        if (flag[u]) continue;
        flag[u] = true;
        for (auto v : g[u]) {
            if (vis[v]) return stp + 1;
            if (flag[v]) continue;
            q.push(make_pair(v, stp + 1));
        }
    }
    return 0;
}
int func() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        res = max(res, bfs(i));
    }
    return res;
}
void solve() {
    ans = LONG_LONG_MAX;
    n = input(), k = input();
    int u, v;
    for (int i = 1; i <= n; i++) g[i].resize(0);
    for (int i = 1; i < n; i++) {
        u = input(), v = input();
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = (1 << n) - 1; i >= 0; i--) {
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= n; j++) {
            if ((1 << (j - 1)) & i) {
                cnt++;
                vis[j] = true;
            }
        }
        if (cnt != k or !check()) continue;
        ans = min(ans, func());
    }
    print(ans);
    pc('\n');
    return ;
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    tc = input(), T = input();
    while (T--) solve();
    return 0;
}
