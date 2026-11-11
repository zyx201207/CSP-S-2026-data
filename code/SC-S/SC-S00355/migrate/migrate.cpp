#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define scf scanf
#define prf printf
#define fu(_zzz_, _l_, _r_) for(auto _zzz_ = _l_; _zzz_ <= _r_; _zzz_++)
#define fd(_zzz_, _l_, _r_) for(auto _zzz_ = _l_; _zzz_ >= _r_; _zzz_--)

int cdata, n;
ll a[2000010], d;
int dis[5010][5010];
ll way[5010][5010];

void solve(){
    scf("%d%lld", &n, &d);
    fu(i, 1, n){
        scf("%lld", &a[i]);
    }

    if(cdata == 11 || cdata == 12){

    }

    memset(dis, 0x3f, sizeof(dis));
    fu(i, 1, n){
        fu(j, 1, n){
            if(abs(a[j] - a[i]) <= d)dis[i][j] = way[i][j] = 1;
        }
    }
    fu(k, 1, n){
        fu(i, 1, n){
            fu(j, 1, n){
                if(dis[i][k] <= n && dis[k][j] <= n){
                    if(dis[i][k] + dis[k][j] == dis[i][j]){
                        way[i][j] += way[i][k] * way[k][j];
                    }
                    if(dis[i][k] + dis[k][j] < dis[i][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                        way[i][j] = dis[i][k] * dis[k][j];
                    }
                }
            }
        }
    }

    ll ans = 0;
    fu(i, 1, n){
        fu(j, 1, n){
            ans += (way[i][j] == 2);
        }
    }
    prf("%lld\n", ans / 2);

    // prf("%lld %lld\n", ans, jn);
    // prf("%lld\n", res)
}

signed main(){

     freopen("migrate.in", "r", stdin);
     freopen("migrate.out", "w", stdout);

    int T;
    scf("%d%d", &cdata, &T);
    while(T--){
        solve();
    }

    return 0;
}