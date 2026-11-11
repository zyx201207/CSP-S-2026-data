#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 505, maxm = 100005;
const ll inf = (ll)1e18;
int c, n, m, d, q;
ll w[maxn];
vector<pair<int, ll>> g[maxm];
ll dis[maxm];
int vis[maxm];
int getid(int x, int id) {
    return n + (x - 1) * 20 + id; 
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> m >> n >> d >> q;
    for (int i = 1; i <= n; i++) cin >> w[i];
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            int k;
            cin >> k;
            if (k == 1) {
                ll a, b;
                cin >> a >> b;
                continue;
            }
            cnt++;
            int lastu, u;
            ll ww;
            for (int j = 1; j <= k; j++) {
                cin >> u >> ww;
                if (j != 1) {
                    int idu = getid(u, cnt), idv = getid(lastu, cnt);
                    g[idu].push_back({idv, 0});
                    g[idv].push_back({idu, 0});
                }
                int idu = getid(u, i);
                g[u].push_back({idu, ww});
                g[idu].push_back({u, ww});
                lastu = u;
            }
        }
        for (int qe = 1; qe <= q; qe++) {
            int x, y;
            cin >> x >> y;
            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
            q.push({0, x});
            dis[x] = 0;
            vis[x] = qe;
    //        cout << qe << '\n';
            while (!q.empty()) {
                pair<ll, ll> now = q.top();
                q.pop();
                int dist = now.first, u = now.second;
    //            cout << u << '\n';
                if (u == y) {
                    cout << (ll)(dist + w[x] + w[y]) << '\n';
                    break;
                }
                if (dist != dis[u]) continue;
                for (int i = 0; i < (int)g[u].size(); i++) {
                    ll vv = g[u][i].first, ww = g[u][i].second;
                    int v = (int)vv;
                    if (vis[v] != qe) {
                        vis[v] = qe;
                        dis[v] = inf;
    //                    cout << 11 << " " << vis[v] << " " << qe << " ";
                    }
    //                cout << vis[v] << " ";
                    if (dis[u] + ww < dis[v]) {
    //                	cout << dis[u] << " " << dis[v] << " " << v << " " << ww << '\n';
                        dis[v] = dis[u] + ww;
                        q.push({dis[v], v});
                    }
                }
            }
        }
    return 0;
}