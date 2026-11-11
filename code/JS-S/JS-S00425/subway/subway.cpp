#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 505;
const int M = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
vector <pair<int, int>> g[M];// to, val
//vector <pair<int, int>> e[N];
int n, m, d, c, q;
int w[M], k[N];
ll dis[N][N];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i= 1; i<= m; i++)
        scanf("%d", &w[i]);
    for(int i= 1; i<= n; i++){
        scanf("%d", &k[i]);
        for(int j= 1; j<= k[i]; j++){
            int cur, val;
            scanf("%d%d", &cur, &val);
            g[cur].push_back({i, val});
        }
    }

    for(int o= 1; o<= m; o++){
        for(int i= 0; i< g[o].size(); i++)
            for(int j= 0; j< g[o].size(); j++){
                int u = g[o][i].first, wu = g[o][i].second;
                int v = g[o][j].first, wv = g[o][j].second;
                //printf("%lld%lld\n%lld%lld\n%lld\n", v, wv, u, wu, dis[u][v]);
                dis[u][v] = min(dis[u][v], (ll)wu + wv);
            }
    }

    for(int i= 1; i<= n; i++) dis[i][i] = 0;
    /*for(int i= 1; i<= n; i++){
        for(int j= 1; j<= n; j++)   cout<< dis[i][j]<<" ";
        cout<< endl;
    }*/

    for(int d= 1; d<= n; d++)
        for(int i= 1; i<= n; i++)
            for(int j= 1; j<= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][d] + dis[d][j]);

    while(q--){
        int x, y;
        scanf("%d%d", &x, &y);
        ll ans = INF;
        for(int i= 0; i< g[x].size(); i++)
            for(int j= 0; j< g[y].size(); j++){
                ll v = g[x][i].first, vw = g[x][i].second;
                ll u = g[y][j].first, uw = g[y][j].second;
                //printf("%lld%lld\n%lld%lld\n%lld\n", v, vw, u, uw, dis[u][v]);
                ans = min(ans, dis[u][v] + vw + uw);
            }
        ans = ans + w[x] + w[y];
        printf("%lld\n", ans);
    }
    return 0;
}

/* for(int i= 1; i<= n; i++){
        for(int j= 1; j<= n; j++)   cout<< dis[i][j]<<" ";
        cout<< endl;
    }*/







