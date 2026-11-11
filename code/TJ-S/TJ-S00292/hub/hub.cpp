#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MAXN = 1e6;

int c, t, n, k, cc, kcnt, ans, dis[MAXN];
bool ins[MAXN], vis[MAXN], dv[MAXN];

vector<int> g[MAXN];

void calc()
{
    queue<int> que;
    memset(dis, 0x3f, sizeof(dis[0]) * (n + 1));
    memset(dv, false, sizeof(dv[0]) * (n + 1));
    for (int i = 1; i <= n; i++) {
        if (ins[i]) {
            que.push(i);
            dis[i] = 0;
            dv[i] = true;
        }
    }
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (auto tar : g[cur]) {
            if (!dv[tar]) {
                dv[tar] = true;
                dis[tar] = dis[cur] + 1;
                que.push(tar);
            }
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dis[i]);
    }
    ans = min(ans, mx);
}

void gc(int cur, int fa)
{
    vis[cur] = true;
    for (auto tar : g[cur]) {
        if (tar != fa && ins[tar] && !vis[tar]) {
            gc(tar, cur);
        }
    }
}

void check()
{
    cc = 0;
    memset(vis, 0, sizeof(vis[0]) * (n + 1));
    for (int i = 1; i <= n; i++) {
        if (ins[i] && !vis[i]) {
            cc++;
            gc(i, 0);
        }
    }
    if (cc > 2) {
        return;
    }
    calc();
}

void dfs(int cur)
{
    if (kcnt > k) {
        return;
    }
    if (cur == n + 1) {
        if (kcnt == k)
            check();
        return;
    }
    kcnt++;
    ins[cur] = true;
    dfs(cur + 1);
    kcnt--;
    ins[cur] = false;
    dfs(cur + 1);
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        int u, v;
        for (int i = 1; i <= n - 1; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(ins, false, sizeof(ins[0]) * (n + 1));
        ans = 1e9;
        kcnt = 0;
        dfs(1);
        cout << ans << '\n';
    }


    return 0;
}
