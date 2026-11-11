#include <bits/stdc++.h>
#define int long long
#define Pii pair<int, int>
#define Fr first
#define Sc second
#define lowbit(x) (x & (-x))

using namespace std;

const int kMaxN = 1e5 + 5, INF = 1e18;

int dep[kMaxN], Mx[kMaxN], sz[kMaxN];
int Fa[kMaxN];
int n, k;
vector<int> G[kMaxN];
bool vis[kMaxN];
int f[1005][1005];

void solve13() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        G[x].push_back(y), G[y].push_back(x);
    }
    int m = n / 2;
    int tmp = (m - k + 3) / 4;
    cout << tmp + 1 << '\n';    
}

int popcnt(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x)) ret++;
    return ret;
}

int F(int x) {
    return Fa[x] == x ? x : (Fa[x] = F(Fa[x]));
}

void M(int x, int y) {
    x = F(x), y = F(y);
    Fa[x] = y;
}

void solve3() {
    cin >> n >> k;
    int dis[20][20];
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y, x--, y--;
        G[x].push_back(y), G[y].push_back(x);
    }
    int ans = INF;
    for (int i = 0; i < (1 << n); i++) {
        int p = popcnt(i); if (p != k) continue;  
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) vis[j] = 1;
            else vis[j] = 0;
        }
        for (int j = 0; j < n; j++) Fa[j] = j;  
        for (int j = 0; j < n; j++) if (vis[j]) {
            for (auto k : G[j]) if (vis[k]) M(k, j);
        }
        int cnt = 0;
        for (int j = 0; j < n; j++) if (F(j) == j && vis[j] == 1) cnt++;
        if (cnt > 2) continue;
        fill(dis[0], dis[0] + 400, INF);
        for (int j = 0; j < n; j++) dis[j][j] = 0;
        for (int j = 0; j < n; j++) for (auto k : G[j]) dis[j][k] = 1;
        for (int k = 0; k < n; k++) {
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < n; b++) dis[a][b] = min(dis[a][b], dis[a][k] + dis[k][b]);
            }
        }
        cnt = 0;
        for (int j = 0; j < n; j++) {
            int ret = INF;
            if (vis[j]) continue;
            for (int k = 0; k < n; k++) if (vis[k]) {
                ret = min(ret, dis[j][k]);
            }
            cnt = max(cnt, ret);
        }
        
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
}

void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1, Mx[x] = dep[x], sz[x] = 1;
    for (auto v : G[x]) if (v != fa) {
        dfs(v, x), Mx[x] = max(Mx[x], Mx[v]);
    }
}

void dfs2(int x, int fa) {
    f[x][1] = Mx[x] - dep[x], f[x][0] = Mx[x] - dep[x] + 1;
    for (auto v : G[x]) {
        for (int i = sz[x]; i >= 0; i--) {
            for (int j = sz[v]; j >= 0; j--) {
                if (i == j && i == 0);
                else if (i == 0) f[x][i] = min(f[x][i], max(f[v][j], Mx[x] - dep[x] + 1));
                else if (j == 0) f[x][i] = min(f[x][i], Mx[v] - dep[x]);
                else f[x][i + j] = min(f[x][i + j], max(f[x][i], f[v][j]));
            }
        }
        sz[x] += sz[v];
    }
}

void solve6() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= n; j++) f[i][j] = INF;
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        G[x].push_back(y), G[y].push_back(x);
    }
    dfs(1, 0);
    dfs2(1, 0);
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int p = 0; p <= k; p++) {
                ans = min(ans, max(f[i][p], f[j][k - p]));
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios:: sync_with_stdio(0), cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int T = 1, c;
    cin >> c >> T;
    for (; T; T--) {
        if (c <= 3) solve3();
        // if (c <= 6 && c >= 4) solve6();
        else if (c == 13 || c == 14) solve13();
    }
    return 0;
}
/*
ulimit -s 1024000 && cd "/home/noilinux/HN-S01000/hub" && g++ hub.cpp -o hub -Wall -O2 && ./hub 
*/