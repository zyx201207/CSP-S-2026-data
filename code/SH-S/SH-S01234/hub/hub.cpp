#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int c, t, n, k;

int tot, hd[N], nxt[N * 2], to[N * 2];
void ae(int u, int v) {
    nxt[tot] = hd[u];
    to[tot] = v;
    hd[u] = tot++;
}
void abe(int u, int v) {
    ae(u, v);
    ae(v, u);
}

int fa[N], dep[N], dp, dpv, ign;
void dfs(int u) {
    dep[u] = dep[fa[u]] + 1;
    for (int cur = hd[u]; cur; cur = nxt[cur]) {
        int v = to[cur];
        if (!dep[v] && v != ign) {
            fa[v] = u;
            dfs(v);
        }
    }
    if (dep[u] > dpv) {
        dpv = dep[u];
        dp = u;
    }
}

int s, e, d;
void findd(int i) {
    dpv = 0, memset(dep, 0, sizeof(dep)), fa[i] = i, dfs(i);
    s = dp;
    dpv = 0, memset(dep, 0, sizeof(dep)), fa[s] = s, dfs(s);
    e = dp;
    d = dpv;
}

int totd[N], dd[N];

void clean() {
    ign = 0;
    tot = 1;
    memset(hd, 0, sizeof(hd));
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    iostream::sync_with_stdio(false);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        clean();
        cin >> n >> k;

        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            abe(u, v);
        }
        findd(1);
        int lmid = s, rmid = e;
        for (int i = 0; i < (d - 1) / 3; i++) rmid = fa[rmid];
        dpv = 0, memset(dep, 0, sizeof(dep)), fa[e] = e, dfs(e);
        for (int i = 0; i < (d - 1) / 3; i++) lmid = fa[lmid];

        memset(totd, 0x3F, sizeof(totd));
        memset(dep, 0, sizeof(dep)), fa[lmid] = lmid, dfs(lmid);
        for (int i = 1; i <= n; i++) totd[i] = min(totd[i], dep[i]);
        memset(dep, 0, sizeof(dep)), fa[rmid] = rmid, dfs(rmid);
        for (int i = 1; i <= n; i++) totd[i] = min(totd[i], dep[i]);
        for (int i = 1; i <= n; i++) totd[i] = -(totd[i] - 1);
        sort(&totd[1], &totd[n + 1]);
        k -= 2;
        while (k-- > 0) {
            totd[1]++;
            sort(&totd[1], &totd[n + 1]);
        }
        cout << -totd[1] << endl;
    }
    return 0;
}