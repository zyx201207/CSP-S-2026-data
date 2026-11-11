#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N(505), M(5e5 + 5);
int _, n, m, d, q;
struct Node{
    int id;
    ll t;
};
vector<Node> g[M];
ll w[M], dis[N][N];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &_, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++) scanf("%lld", w + i);
    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= n; i++){
        int k;
        scanf("%d", &k);
        dis[i][i] = 0;
        while(k--){
            int a;
            ll t;
            scanf("%d%lld", &a, &t);
            g[a].push_back({i, t});
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < g[i].size(); j++){
            for(int k = 0; k < g[i].size(); k++){
                if(j == k) continue;
                int u = g[i][j].id, v = g[i][k].id;
                dis[u][v] = min(dis[u][v], g[i][j].t + g[i][k].t);
            }
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    while(q--){
        int u, v;
        scanf("%d%d", &u, &v);
        ll ans = 1e18;
        for(int i = 0; i < g[u].size(); i++){
            for(int j = 0; j < g[v].size(); j++){
                int x = g[u][i].id, y = g[v][j].id;
                ans = min(ans, g[u][i].t + dis[x][y] + g[v][j].t);
            }
        }
        ans += w[u] + w[v];
        printf("%lld\n", ans);
    }
    return 0;
}
