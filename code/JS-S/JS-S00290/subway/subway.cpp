#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, int>;
#define fi first
#define se second

const int N = 509, M = 5e5 + 9;
const ll INF = 1e18;
vector<int> a[N], t[N];
int w[M], k[N];
int c, n, m, d, q;

namespace sub1{
    ll dis[609][609];

    void solve(){
        for(int i = 1; i < 609; i++) for(int j = 1; j < 609; j++){
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
        for(int i = 1; i <= n; i++){
            int u = m + i;
            for(int j = 1; j <= k[i]; j++) {
                //cout << a[i][j] << ' ' << u << '\n';
                dis[a[i][j]][u] = dis[u][a[i][j]] = t[i][j];
            }
        }
        
        for(int k = 1; k <= n + m; k++)
            for(int i = 1; i <= n + m; i++)
                for(int j = 1; j <= n + m; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        
        while(q--){
            int x, y;
            cin >> x >> y;
            //cout << dis[x][y] << ' ' << w[x] << ' ' << w[y] << '\n';
            cout << dis[x][y] + w[x] + w[y] << '\n';
        }
    }
}

namespace sub2{
    bool in[M][3];
    ll dis[M][3];

    void solve(){
        ll D = INF;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k[i]; j++) in[a[i][j]][i] = 1;
            for(int j = 1; j <= k[i]; j++) dis[a[i][j]][i] = t[i][j];
        }

        for(int i = 1; i <= m; i++)
            if(in[i][1] && in[i][2]) D = min(D, dis[i][1] + dis[i][2]);

        while(q--){
            int x, y;
            cin >> x >> y;
            ll ans = INF;
            if(in[x][1] && in[y][1]) ans = min(ans, dis[x][1] + dis[y][1]);
            if(in[x][2] && in[y][2]) ans = min(dis[x][2] + dis[y][2], ans);
            if(in[x][1] && in[y][2]) ans = min(ans, dis[x][1] + D + dis[y][2]);
            if(in[x][2] && in[y][1]) ans = min(ans, dis[x][2] + D + dis[y][1]);
            cout << ans + w[x] + w[y] << '\n';
        }
    }
}

namespace std{
    vector<pii> G[N + M];
    bool in[M][29], vis[N + M];
    ll dis1[M][29], dis[N + M], D[29][29];
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    void dijkstra(int s){
        for(int i = 1; i <= n + m; i++) dis[i] = INF, vis[i] = 0;
        dis[s] = 0;
        pq.push({0, s});
        while (!pq.empty()){
            int u = pq.top().se; pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto it : G[u]){
                int v = it.fi, w = it.se;  
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        
    }

    void solve(){
        for(int i = 1; i <= n; i++){
            int u = i + m;
            for(int j = 1; j <= k[i]; j++) in[a[i][j]][i] = 1;
            for(int j = 1; j <= k[i]; j++) {
                int v = a[i][j];
                G[u].push_back({v, t[i][j]});
                G[v].push_back({u, t[i][j]});
                dis1[a[i][j]][i] = t[i][j];
            }
        }

        for(int i = 1; i <= n; i++){
            dijkstra(i + m);
            for(int j = 1; j <= n; j++) {
                D[i][j] = dis[j + m];
            }
        }

        while(q--){
            int x, y;
            cin >> x >> y;
            vector<int> a, b;
            for(int i = 1; i <= n; i++){
                if(in[x][i]) a.push_back(i);
                if(in[y][i]) b.push_back(i);
            }
            ll ans = INF;
            for(int i : a){
                for(int j : b){
                    ans = min(ans, dis1[x][i] + dis1[y][j] + D[i][j]);
                }
            }
            cout << ans + w[x] + w[y] << '\n';
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        a[i].resize(k[i] + 1);
        t[i].resize(k[i] + 1);
        for(int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][j];
    }

    if(c <= 8){
        sub1::solve();
        return 0;
    }
    if(c == 20 || c == 21){
        sub2::solve();
        return 0;
    }
    std::solve();
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/