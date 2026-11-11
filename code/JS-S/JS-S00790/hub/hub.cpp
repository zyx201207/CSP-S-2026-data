#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 5e5 + 5;
int c, t, n, k, a[N], r[N];
vector<int> g[N];
int mark[N], minn[N];
int ans;

int dis[N];
bool vis[N];
struct Edge {
    int v, w;
};
bool operator <(Edge x, Edge y) {
    return x.w > y.w;
}
void smaller(int st) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    priority_queue<Edge> q;
    q.push({st, 0});
    dis[st] = 0;
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        if (vis[u] == true)
            continue;
        vis[u] = true;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i], w = 1;
            // cout << v << " " << w << endl;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v, dis[v]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        minn[i] = min(minn[i], dis[i]);
}

int tong() {
    int res = -2e9;
    for (int i = 1; i <= k; i++)
        smaller(mark[i]);
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", minn[i]);
    // printf("\n\n");
    for (int i = 1; i <= n; i++)
        res = max(res, minn[i]);
    return res;
}

void init() {
    for (int i = 1; i <= n; i++)
        g[i].clear();
    memset(mark, 0, sizeof(mark));
    memset(minn, 0x3f, sizeof(minn));
}

void solve(int step, int cnt, int cntl) {
    if (cntl > 2)
        return;
    if (cnt == k) {
        for (int i = 1; i <= k; i++)
            printf("%d ", mark[i]);
        printf("\n");
        ans = min(ans, tong());
        return;
    }
    for (int i = step + 1; i <= n; i++) {
        mark[cnt + 1] = i;
        solve(i, cnt + 1, cntl + (i == step + 1));
    }
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while (t--) {
        init();
        scanf("%d %d", &n, &k);
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        solve(0, 0, 0);

        printf("%d\n", ans);
    }
    return 0;
}