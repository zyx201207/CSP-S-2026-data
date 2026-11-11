#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int INF = 1e9;

int n, k;
vector<int> g[N];
int fa[N], dep[N];
bool vis[N];
int cnt;

void dfs1(int u, int p, int d) {
    fa[u] = p;
    dep[u] = d;
    for (int v : g[u]) {
        if (v != p) dfs1(v, u, d + 1);
    }
}

void cover(int u, int p, int r) {
    vis[u] = true;
    if (r == 0) return;
    for (int v : g[u]) {
        if (v != p) cover(v, u, r - 1);
    }
}
 
bool check(int R) {
    for (int i = 1; i <= n; i++) vis[i] = false;
    cnt = 0;
    while (1) {
        int u = -1, mx = -1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dep[i] > mx) {
                mx = dep[i];
                u = i;
            }
        }
        if (u == -1) break;
        int c = u;
        for (int i = 0; i < R && fa[c] != 0; i++) c = fa[c];
        cover(c, 0, R);
        cnt++;
        if (cnt > 2) return false;
    }
    return cnt <= 2;
}

int d[15][15];

void bfs(int s) {
    for (int i = 1; i <= n; i++) d[s][i] = INF;
    d[s][s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (d[s][v] == INF) {
                d[s][v] = d[s][u] + 1;
                q.push(v);
            }
        }
    }
}

int solve() {
    for (int i = 1; i <= n; i++) bfs(i);
    int ans = INF;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) != k) continue;
        vector<int> a;
        for (int i = 1; i <= n; i++) {
            if (mask >> (i - 1) & 1) a.push_back(i);
        }
        int e = 0;
        for (int u : a) {
            for (int v : g[u]) {
                if ((mask >> (v - 1) & 1) && u < v) e++;
            }
        }
        if (k - e > 2) continue;
        int r = 0;
        for (int i = 1; i <= n; i++) {
            int mn = INF;
            for (int j : a) mn = min(mn, d[i][j]);
            r = max(r, mn);
        }
        ans = min(ans, r);
    }
    return ans;
}

int main() {
	freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c, t;
    scanf("%d %d", &c, &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (n <= 10) {
            printf("%d\n", solve());
        } else if (k == 2) {
            dfs1(1, 0, 0);
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (check(mid)) r = mid;
                else l = mid + 1;
            }
            printf("%d\n", l);
        } else {
            printf("0\n");
        }
    }
    return 0;
}
