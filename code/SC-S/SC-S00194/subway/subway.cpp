#include<bits/stdc++.h>
typedef long long ll;
#define PLL pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int M = 5e5 + 10, N = 505;
const ll INF = 1e18;
int test_id, n, m, Lim, q;
ll w[M];
vector<PLL> line[N];
vector<PLL> pt[M];
ll edge[N][N], d[N][N];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &test_id, &n, &m, &Lim, &q);
    for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
    for(int i = 1; i <= n; i++){
        int k;
        scanf("%d", &k);
        while(k--){
            ll a, t;
            scanf("%lld%lld", &a, &t);
            line[i].push_back({a, t});
            pt[a].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) if(i != j){
            edge[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++){
        for(PLL e : line[i]){
            for(PLL x : pt[e.fi]){
                int j = x.fi;
                edge[i][j] = min(edge[i][j], e.se + x.se);
                edge[j][i] = min(edge[j][i], e.se + x.se);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            d[i][j] = edge[i][j];
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    while(q--){
        int x, y;
        scanf("%d%d", &x, &y);
        ll ans = INF;
        for(PLL i : pt[x]){
            for(PLL j : pt[y]){
                ans = min(ans, d[i.fi][j.fi] + i.se + j.se);
            }
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}