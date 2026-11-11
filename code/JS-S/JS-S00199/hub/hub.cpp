#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+5, N2 = 5e3+5;
ll c, t, n, K, x, y, dist[N2][N2], fa[N];
vector<ll> e[N];
ll f(ll k){
    if(fa[k] == k) return k;
    else return fa[k] = f(fa[k]);
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%lld%lld", &c, &t);
    while(t--){
        scanf("%lld%lld", &n, &K);
        for(int i = 1; i <= n; i++) e[i].clear();
        if(c <= 3){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++) dist[i][j] = 1e18;
                dist[i][i] = 0;
            }
        }
        for(int i = 1; i < n; i++){
            scanf("%lld%lld", &x, &y);
            e[x].push_back(y), e[y].push_back(x);
            if(c <= 3) dist[x][y] = dist[y][x] = 1;
        }
        if(c <= 3){
            for(int k = 1; k <= n; k++){
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j <= n; j++){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
            ll ans = 1e18;
            for(int i = 0; i < (1 << n); i++){
                ll cnt = 0;
                for(int j = 1; j <= n; j++) fa[j] = j;
                for(int j = 1; j <= n; j++){
                    if(!(i & (1 << j - 1))) continue;
                    cnt++;
                    for(int k = 0; k < e[j].size(); k++){
                        ll tmp = e[j][k];
                        if(tmp < j && i & (1 << tmp - 1)){
                            ll fx = f(j), fy = f(tmp);
                            fa[fx] = fy;
                        }
                    }
                }
                if(cnt != K) continue;
                cnt = 0;
                for(int j = 1; j <= n; j++){
                    if(i & (1 << j - 1) && fa[j] == j) cnt++;
                }
                if(cnt > 2) continue;
                ll r = 0;
                for(int j = 1; j <= n; j++){
                    if(i & (1 << j - 1)) continue;
                    ll d = 1e18;
                    for(int k = 1; k <= n; k++){
                        if(i & (1 << k - 1)) d = min(d, dist[j][k]);
                    }
                    r = max(r, d);
                }
                ans = min(ans, r);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
