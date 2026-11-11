#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
using pi = pair<int, int>;
const int N = 2e6 + 10, inf = 0x3f3f3f3f;
int n, k, EU[N], EV[N], ans;
vector<pi> g[N];
bitset<N> ban;

int path[N], cnt, dis[N], pa[N];

void dfs(int u, int fa, int &rt) {
    pa[u] = fa;
    for(auto eg : g[u]) {
        int v = eg.fi, eid = eg.se;
        if(v == fa || ban[eid]) continue;
        dis[v] = dis[u] + 1;
        dfs(v, u, rt);
    }
    if(dis[u] > dis[rt]) rt = u;
}

int getdiam(int s) {
    int root1 = s; dis[s] = 0;
    dfs(s, 0, root1);
    int root2 = root1; dis[root1] = 0;
    dfs(root1, 0, root2);
    int cur = root2;
    cnt = 0;
    while(1) {
        path[++cnt] = cur;
        if(cur == root1) break;
        cur = pa[cur];
    }
    return path[(cnt + 1) / 2];
}

void dfs2(int u, int fa) {
    pa[u] = fa; dis[u] = 0;
    for(auto eg : g[u]) {
        int v = eg.fi, eid = eg.se;
        if(v == fa || ban[eid]) continue;
        dfs2(v, u);
        dis[u] = max(dis[u], dis[v] + 1);
    }
}


priority_queue<pi> Q;

void throw_adj(int u) {
    for(auto eg : g[u]) {
        int v = eg.fi, eid = eg.se;
        if(v == pa[u] || ban[eid]) continue;
        Q.push({dis[v] + 1, v});
    }    
}

void work(int eid) {
    int s = EU[eid], t = EV[eid];
    ban[eid] = 1;
    int rootS = getdiam(s);
    dfs2(rootS, 0);
    int rootT = getdiam(t);
    dfs2(rootT, 0);
    int res = max(dis[rootS], dis[rootT]);
    while(!Q.empty()) Q.pop();
    throw_adj(rootS);
    throw_adj(rootT);
    int curK = k - 2;
    while(curK > 0) {
        curK--;
        int u = Q.top().se;
        Q.pop();
        throw_adj(u);
    }
    ban[eid] = 0;
    ans = min(ans, Q.top().fi);
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        EU[i] = u, EV[i] = v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    if(k == n) {
        cout << "0\n";
        return;
    }
    ans = inf;
    for(int i = 1; i < n; i++) work(i);
    cout << ans << "\n";
}


int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cid, T; cin >> cid >> T;
    while(T--) solve();
    return 0;
}