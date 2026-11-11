#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int TaskId;
int T;
int n, k;
vector<int> edge[1000010];
int c[1000010];
int f[1000010];
int d[1000010];
int mi = 1 << 30;

int gf (int x) {
    if (f[x] == x) return x;
    return f[x] = gf(f[x]);
}

bool unite (int x, int y) {
    x = gf(x); y = gf(y);
    if (x != y) {
        f[x] = y;
        return true;
    } else return false;
}

bool check (){
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= n; i++) if (c[i]) {
        for (auto j : edge[i]) if (c[j]) {
            unite(i, j);
        }
    }
    int p1 = 0, p2 = 0;
    for (int i = 1; i <= n; i++) if (c[i]) {
        int val = gf(i);
        if (p1 == 0) {
            p1 = val;
        }
        if (p1 == val) continue;
        if (p2 == 0) {
            p2 = val;
        }
        if (p2 == val) continue;
        return false;
    }
    return true;
}

void bfs (){
    queue<int> q;
    for (int i = 1; i <= n; i++) d[i] = -1;
    for (int i = 1; i <= n; i++) {
        if (c[i]) {
            d[i] = 0;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto y : edge[x]) {
            if (d[y] == -1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
}

void dfs (int x, int cnt) {
    if (x == n + 1) {
        if (cnt != k) return;
        if (!check()) {
            return;
        }
        bfs();
        int ma = 0;
        for (int i = 1; i <= n; i++) ma = max(ma, d[i]);
        mi = min(mi, ma);
        return;
    }
    c[x] = 0;
    dfs(x + 1, cnt);
    c[x] = 1;
    dfs(x + 1, cnt + 1);
}

void dfs1 (int x, int par) {
    for (auto y : edge[x]) if (y != par) {
        d[y] = d[x] + 1;
        dfs1(y, x);
    }
}

void solve (){
    for (int i = 1; i <= n; i++) d[i] = -1;
    d[1] = 0;
    dfs1(1, 0);
    int maxv = -1, maxid = 0;
    for (int i = 1; i <= n; i++) if (d[i] > maxv) {
        maxv = d[i];
        maxid = i;
    }
    for (int i = 1; i <= n; i++) d[i] = -1;
    dfs1(maxid, 0);
    int maxv2 = -1, maxid2 = -1;
    for (int i = 1; i <= n; i++) if (d[i] > maxv2){
        maxv2 = d[i];
        maxid2 = i;
    }
    for (int i = 1; i <= n; i++) c[i] = 0;
    c[maxid] = c[maxid2] = 1;
    bfs();
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, d[i]);
    printf("%d\n", (ans + 1) / 2);
    c[maxid] = c[maxid2] = 0;
}

int main (){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &TaskId, &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) edge[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        if (n > 10 && k == 2) {
            solve();
            continue;
        }
        mi = 1 << 30;
        dfs(1, 0);
        printf("%d\n", mi);
    }
}
// 15 pts ~ 30 pts
