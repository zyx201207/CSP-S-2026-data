#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;

const int N = 505;
const int M = 500005;
int c, n, m, d, q, f[N][N];
bool vis[N];
int w[M];
struct Edge {
    int v, w;
};
vector<Edge> edges[M];
vector<Edge> e[N];

void dijk(int s) {
    memset(vis, false, sizeof vis);
    f[s][s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
    q.push({0, s});
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto ed: e[u]) {
            int v = ed.v, w = ed.w;
            if(f[s][v] > f[s][u] + w) {
                f[s][v] = f[s][u] + w;
                q.push({f[s][v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
        cin >> w[i];
    for(int i=1;i<=n;i++) {
        int k;
        cin >> k;
        for(int j=1;j<=k;j++) {
            int v, w;
            cin >> v >> w;
            edges[v].push_back({i, w});
        }
    }
    for(int i=1;i<=m;i++) {
        int l = edges[i].size();
        for(int j=0;j<l;j++) {
            for(int k=0;k<l;k++) {
                if(j == k) continue;
                int u = edges[i][j].v, v = edges[i][k].v, w = edges[i][j].w+edges[i][k].w;
                e[u].push_back({v, w});
            }
        }
    }
    memset(f, 0x3f, sizeof f);
    for(int i=1;i<=n;i++) 
        dijk(i);
    for(int i=1;i<=q;i++) {
        int s, t;
        cin >> s >> t;
        LL ans = 1e18;
        for(auto eds: edges[s]) {
            for(auto edt: edges[t]) {
                LL u = eds.v, v = edt.v, val = eds.w+edt.w;
                val += f[u][v];
                ans = min(ans, val);
            }
        }
        cout << ans + w[s] + w[t] << '\n';
    }
    return 0;
}