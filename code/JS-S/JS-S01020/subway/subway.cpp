# include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, x, y, cnt, w[2005], k[505], a[505][2005], t[505][2005], pi[100005], vis[100005];
struct node {
    long long v, z;
};
struct node2 {
    long long d, v;
    bool operator <(const node2 &other) const {
        return d > other.d;
    }
};
vector <node> g[100005];
// 300 * 20 * 3
void dijkstra (int s){
    memset(pi, 0x3f, sizeof(pi));
    memset(vis, 0, sizeof(vis));
    priority_queue <node2> qz;
    pi[s] = 0;
    qz.push({0, s});
    while (!qz.empty()){
        int u = qz.top().v;
        qz.pop();
        if (vis[u] == 1){
            continue;
        }
        vis[u] = 1;
        for (vector <node>::iterator it = g[u].begin(); it != g[u].end(); it++){
            long long v = (*it).v, w = (*it).z;
            if (pi[v] > pi[u] + w){
                pi[v] = pi[u] + w;
                qz.push({pi[v], v});
            }
        }
    }
}
int main (){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    cnt = m * 2;
    for (int i = 1; i <= m; i++){
        g[i].push_back({i + m, w[i]});
        g[i + m].push_back({i, w[i]});
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k[i]; j++){
            g[++cnt].push_back({a[i][j] + m, t[i][j]});
            g[a[i][j] + m].push_back({cnt, t[i][j]});
            if (j != 1){
                g[cnt].push_back({cnt - 1, 0});
                g[cnt - 1].push_back({cnt, 0});
            }
        }
    }
    while (q--){
        cin >> x >> y;
        dijkstra(x);
        cout << pi[y] << "\n";
    }
    return 0;
}
