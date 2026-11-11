#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
    int x = 0, flg = 0;
    char c = getchar();
    while (!isdigit(c)) {
        flg |= c == '-';
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c ^ 48);
        c = getchar();
    }
    return flg ? -x : x;
}
inline void write(int x, char div = '\n') {
    if (!x) {
        putchar('0'), putchar(div);
        return;
    }
    string s = "";
    if (x < 0) {
        putchar('-'), x = -x;
    }
    while (x) {
        s = char(x % 10 + '0') + s;
        x /= 10;
    }
    for (char c : s) {
        putchar(c);
    }
    putchar(div);
}
const int N = 1e6 + 5;
const int inf = 1e18;
int n, k, ans;
vector <int> G[N];
void addEdge(int u, int v) {
    G[u].push_back(v);
}
int ch[N];
bool isCh[N];
int fa[N];
int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
}
bool check() {
    for (int i = 1, u; i <= k; i++) {
        u = ch[i];
        fa[u] = u;
    }
    for (int i = 1, u; i <= k; i++) {
        u = ch[i];
        for (int v : G[u]) {
            if (isCh[v]) {
                merge(u, v);
            }
        }
    }
    int f1 = -1, f2 = -1;
    for (int i = 1, u; i <= k; i++) {
        u = ch[i];
        if (fa[u] != f1 && fa[u] != f2) {
            if (f1 == -1) {
                f1 = fa[u];
            } else if (f2 == -1) {
                f2 = fa[u];
            } else {
                return false;
            }
        }
    }
    return f2 != -1;
}
int dis[N], vis[N], tim;
int bfs() {
    if (!check()) {
        return inf;
    }
    tim++;
    queue <int> Q;
    int ret = 0;
    for (int i = 1, u; i <= k; i++) {
        u = ch[i];
        Q.push(u);
        vis[u] = tim;
        dis[u] = 0;
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : G[u]) {
            if (vis[v] != tim) {
                Q.push(v);
                dis[v] = dis[u] + 1;
                ret = max(ret, dis[v]);
                vis[v] = tim;
            }
        }
    }
    return ret;
}
void dfs(int u, int cnt) {
    if (cnt > k) {
        ans = min(ans, bfs());
        return;
    }
    for (int i = u + 1; i <= n; i++) {
        ch[cnt] = i;
        isCh[i] = true;
        dfs(i, cnt + 1);
        ch[cnt] = 0;
        isCh[i] = false;
    }
}
void solve() {
    n = read(), k = read(), ans = inf;
    for (int i = 1, u, v; i < n; i++) {
        u = read(), v = read();
        addEdge(u, v), addEdge(v, u);
    }
    dfs(0, 1);
    write(ans);
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int subtask = read(), T = read();
    while (T--) {
        solve();
    }
    return 0;
}
