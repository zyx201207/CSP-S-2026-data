/*
二分暗示？！
直接二分考虑判定方案
这样的话好像就是每一个点有一个管辖范围，然后我们要把整棵树覆盖了
这个好像可以直接贪心。哦好像不行，那还是 dp 吧
设 fij 表示在子树 i 中最深的没有覆盖的点距离 i 的距离为 j 所需最小代价
我发现我不擅长写部分分。。。
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5, INF = 0x3f3f3f3f, K = 21;

int c, t, n, k, fa[N], dep[N], fat[N], ans = INF;
bool vis[N], vv[N];
vector<int> T[N];

inline void dfs1(int u, int fx) {
    fa[u] = fx, dep[u] = dep[fx] + 1;
    for (int v : T[u]) if (fx != v) dfs1(v, u);
}
inline int lca(int u, int v) {
    while (u != v) {
        if (dep[u] < dep[v]) swap(u, v);
        u = fa[u];
    }
    return u;
}
inline int dis(int u, int v) {
    return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}
inline int find(int u) {
	return u == fat[u] ? u : fat[u] = find(fat[u]);
}
inline void dfs2(int i, int s) {
    if (s == k) {
        int cur = 0;
        for (int i = 1; i <= n; ++i) fat[i] = i, vv[i] = false;
        for (int i = 1; i <= n; ++i)
        	for (int j : T[i])
        		if (vis[i] == vis[j])
        			fat[find(i)] = fat[find(j)];
        for (int i = 1; i <= n; ++i) if (vis[i]) vv[find(i)] = true;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) cnt += vv[i];
        if (cnt > 2) return ;
        for (int i = 1; i <= n; ++i) 
            if (!vis[i]) {
                int mn = INF;
                for (int j = 1; j <= n; ++j)
                    if (vis[j]) mn = min(mn, dis(i, j));
                cur = max(cur, mn);
            }
        ans = min(ans, cur);
        return ;
    }
    if (i > n) return ;
    vis[i] = true;
    dfs2(i + 1, s + 1);
    vis[i] = false;
    dfs2(i + 1, s);
}

inline void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) T[i].clear();
    ans = INF;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        T[u].push_back(v), T[v].push_back(u);
    }

	dfs1(1, 0);
    dfs2(1, 0);
	cout << ans << '\n';
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);

    int c, t; cin >> c >> t;
    while (t--) solve();

    return 0;
}

/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/ 
