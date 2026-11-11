#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int>z[505];
vector<long long>g[505], w[505], g1[500005], w1[500005];
long long d[505][505];
int vis[505], cnt;
long long a[500005];
long long dk[505][505];
struct node{
    int x;
    long long dis;
    friend bool operator < (node l, node r) {
        return l.dis > r.dis;
    }
};
void dij(int s) {
    for (int i = 1; i <= cnt; i++)
        vis[i] = 0, d[s][i] = 1e18;
    d[s][s] = 0;
    priority_queue<node>q;
    q.push({s, 0});
    while (!q.empty()) {
        int x = q.top().x;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = 0; i < (int)g[x].size(); i++) {
            int y = g[x][i];
            long long ww = w[x][i];
            if (d[s][y] > d[s][x] + ww) {
                d[s][y] = d[s][x] + ww;
                q.push({y, d[s][y]});
            }
        }
    }
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int c, n, m, D, q;
    cin >> c >> n >> m >> D >> q;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    cnt = n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            int b, t;
            cin >> b >> t;
            g1[b].push_back(i);
            w1[b].push_back(t);
            z[i][b] = t;
        }
    }
    memset(dk, 0x3f, sizeof(dk));
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (int)g1[i].size(); j++)
        for (int k = j + 1; k < (int)g1[i].size(); k++) {
            int x = g1[i][j], y = g1[i][k];
            dk[x][y] = dk[y][x] = min(dk[x][y], w1[i][j] + w1[i][k]);
        }
    }
    for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
        if(dk[i][j] <= 2e9) {
            g[i].push_back(j);
            w[i].push_back(dk[i][j]);
            g[j].push_back(i);
            w[j].push_back(dk[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        dij(i);
    while (q--) {
        int x, y;
        cin >> x >> y;
        long long ans = 1e18;
        for (int k1: g1[x])
            for (int k2: g1[y])
                ans = min(ans, a[x] + a[y] + z[k1][x] + z[k2][y] + d[k1][k2]);
        cout << ans << "\n";
    }
    return 0;
}

