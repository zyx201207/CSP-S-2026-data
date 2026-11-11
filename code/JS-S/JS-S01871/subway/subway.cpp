#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 510;
const int M = 5e5 + 5;
const ll INF = 1e18;
int n, m, d, q;
ll w[M], dis[N][N];
vector < pair <int, ll> > bel[M];

int main(){ 
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c; cin >> c;
    cin >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        for(int j = 1; j <= k; j++){
            int a;
            ll t;
            cin >> a >> t;
            bel[a].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dis[i][j] = INF;
            if(i == j) dis[i][j] = 0;
        }
    }
    for(int cur = 1; cur <= m; cur++){
        int siz = bel[cur].size();
        for(int i = 0; i < siz - 1; i++){
            for(int j = i + 1; j < siz; j++){
                int u = bel[cur][i].first;
                int v = bel[cur][j].first;
                ll cost = bel[cur][i].second + bel[cur][j].second;
                dis[u][v] = min(dis[u][v], cost);
                dis[v][u] = min(dis[v][u], cost);
            }
        }
    }
    //Floyd
    for(int k = 1; k <= n; k++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        ll ans = INF;
        for(auto st : bel[x]){
            for(auto ed : bel[y]){
                int u = st.first;
                int v = ed.first;
                ll cur = dis[u][v] + st.second + ed.second;
                ans = min(ans, cur);
            }
        }
        ans += w[x] + w[y];
        cout << ans << "\n";
    }
    return 0;
}