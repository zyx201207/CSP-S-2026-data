#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int TASK_ID, t;
int n, k, s, dis[N], vis[N];
vector <int> g[N];
queue <int> que;

void dfs(int u, int fa) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (v == fa || ((s >> v) & 1) == 0) continue;
        dfs(v, u);
    }
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> TASK_ID >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 0x3f3f3f3f;
        for (int st = 0; st < (1 << n); ++st) {
            if (__builtin_popcount(st) != k) continue;
            s = (st << 1); int cnt = 0;
            for (int i = 1; i <= n; ++i) vis[i] = 0;
            for (int i = 1; i <= n; ++i)
                if ((s >> i) & 1)
                    if (!vis[i]) {
                        ++cnt;
                        dfs(i, 0);
                    }
            if (cnt > 2) continue;
            for (int i = 1; i <= n; ++i) {
                dis[i] = 0x3f3f3f3f;
                if ((s >> i) & 1) {
                    dis[i] = 0;
                    que.push(i);
                }
            }
            while (que.size()) {
                int u = que.front();
                que.pop();
                for (int v : g[u])
                    if (dis[v] > dis[u] + 1) {
                        dis[v] = dis[u] + 1;
                        que.push(v);
                    }
            }
            int res = 0;
            for (int i = 1; i <= n; ++i) res = max(res, dis[i]);
            // printf("%d : ", st);
            // for (int i = 1; i <= n; ++i) printf("%d%c", dis[i], " \n"[i == n]);
            // printf("res = %d\n", res);
            ans = min(ans, res);
        }
        printf("%d\n", ans);
    }
    fflush(stdout); fclose(stdin), fclose(stdout);
    return 0;
}