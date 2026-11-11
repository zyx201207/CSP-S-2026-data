#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, M = 1007;
int c, T, n, k, head[N], ver[N << 1], nxt[N << 1], tot = 1;
int dis[M][M], rt, ans, fa[N];
int get(int x) {
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x, int y, int &cnt) {
    x = get(x), y = get(y);
    if(x == y) return ;
    fa[x] = y; cnt --;
}
void add(int u, int v) {
    ver[++ tot] = v, nxt[tot] = head[u], head[u] = tot;
    ver[++ tot] = u, nxt[tot] = head[v], head[v] = tot;
}
vector<int> nd;
void work(int u, int fa, int cnt) {
    dis[u][rt] = dis[rt][u] = cnt;
    for(int i = head[u]; i; i = nxt[i]) {
        int v = ver[i];
        if(v != fa) work(v, u, cnt + 1);
    }
}
void dfs(int pos, int x) {
    if(pos == n + 1) {
        if(x) return ;
        for(int i = 1; i <= n; i ++) fa[i] = i;
        int s = nd.size();
        for(auto v : nd) {
            for(auto p : nd) {
                if(dis[v][p] == 1) merge(v, p, s);
            }
        }
        if(s != 2) return ;
        int mx = 0;
        for(int i = 1; i <= n; i ++) {
            int mn = 1e9;
            for(auto v : nd) mn = min(mn, dis[i][v]);
            mx = max(mx, mn);
        }
        ans = min(ans, mx);
        return ;
    }
    dfs(pos + 1, x);
    if(x) {
        nd.push_back(pos);
        dfs(pos + 1, x - 1);
        nd.pop_back();
    }
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> T;
    while(T --) {
        for(int i = 1; i <= n; i ++) head[i] = 0;
        tot = 1, ans = 1e9;
        cin >> n >> k;
        for(int i = 1; i < n; i ++) {
            int u, v; cin >> u >> v;
            add(u, v);
        }
        for(rt = 1; rt <= n; rt ++) work(rt, 0, 0);
        dfs(1, k);
        cout << ans << '\n';
    } 
    return 0;
}