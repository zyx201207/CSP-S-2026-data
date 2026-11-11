#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi pair<ll, ll>
#define mk make_pair
#define fi first
#define se second
const ll N = 1e6+5;
ll c, n, m, d, Q, w[N], K, x, y, z, dist[1005][1005];
vector<pi> e[N];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &Q);
    for(int i = n + 1; i <= n + m; i++){
        scanf("%lld", &w[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%lld", &K);
        for(int j = 1; j <= K; j++){
            scanf("%lld%lld", &x, &y);
            e[i].push_back(mk(x + n, y));
            e[x + n].push_back(mk(i, y));
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) dist[i][j] = 1e18;
        dist[i][i] = 0;
    }
    for(int i = n + 1; i <= n + m; i++){
        ll s = e[i].size();
        for(int j = 0; j < s; j++){
            for(int k = j + 1; k < s; k++){
                x = e[i][j].fi, y = e[i][k].fi, z = e[i][j].se + e[i][k].se;
                dist[x][y] = dist[y][x] = z;
            }
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while(Q--){
        scanf("%lld%lld", &x, &y);
        x += n, y += n;
        ll s1 = e[x].size(), s2 = e[y].size(), ans = 1e18;
        for(int i = 0; i < s1; i++){
            for(int j = 0; j < s2; j++){
                ans = min(ans, e[x][i].se + e[y][j].se + dist[e[x][i].fi][e[y][j].fi]);
            }
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}
