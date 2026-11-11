#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define st first
#define nd second
#define ll long long
using namespace std;
const int N = 510, M = 5e5 + 7;
const ll INF = 1e18;
int c, n, m, d, q;
int w[M], vis[N];
ll add[N][N], dis[N][N];
vector<pii> dr[M];
priority_queue<pii, vector<pii>, greater<pii>> qu;
void dij(int s) {
    for (int i = 1; i <= n; i ++)
        vis[i] = 0, dis[s][i] = INF;
    dis[s][s] = 0, qu.push({dis[s][s], s});
    while (!qu.empty()) {
        int u = qu.top().nd; qu.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int v = 1; v <= n; v ++)
            if (dis[s][u] + add[u][v] <= dis[s][v])
                dis[s][v] = dis[s][u] + add[u][v], qu.push({dis[s][v], v});
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++)
        cin >> w[i];
    for (int i = 1, k; i <= n; i ++) {
        cin >> k;
        for (int j = 1, v, t; j <= k; j ++)
            cin >> v >> t, dr[v].push_back({i, t});
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            add[i][j] = INF;
    for (int i = 1; i <= m; i ++) {
        for (pii j : dr[i]) {
            for (pii k : dr[i]) {
                int u = j.st, v = k.st;
                if (u == v)
                    continue;
                add[u][v] = add[v][u] = min(add[u][v], j.nd + k.nd);
            }
        }
    }
    /*
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (add[i][j] == INF)
                cout << "No ";
            else
                cout << add[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    for (int i = 1; i <= n; i ++)
        dij(i);

    while (q --) {
        int x, y;
        ll ans = INF;
        cin >> x >> y;
        for (pii i : dr[x])
            for (pii j : dr[y])
                ans = min(ans, i.nd + j.nd + dis[i.st][j.st]);
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
