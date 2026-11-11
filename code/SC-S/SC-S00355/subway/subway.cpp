/*

m 地铁站数    5e5
n 地铁条数    500
q 计划数    1e5
d 每个地铁站的容量    20

w_v 表示 口 -> 站厅    1e9
k_i 表示第 i 条地铁的长度     m
a_ij 表示第 i 条地铁经过的第 j 个站点    m
t_ij 表示站厅 -> a_ij 站台时间    1e9
x_i, y_i 第 i 个出行计划的 起点，终点    m

*/


#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define scf scanf
#define prf printf
#define fu(_zzz_, _l_, _r_) for(auto _zzz_ = _l_; _zzz_ <= _r_; _zzz_++)
#define fd(_zzz_, _l_, _r_) for(auto _zzz_ = _l_; _zzz_ >= _r_; _zzz_--)

int cdata, n, m, q, d;
ll tim[500010];
vector<int> a[510];
vector<ll> t[510];
int len[510];
struct Q{
    int x, y;
}qs[100010];

vector<pair<int, ll>> sub[500010];

ll re[510][510];

signed main(){

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scf("%d%d%d%d%d", &cdata, &n, &m, &d, &q);
    fu(i, 1, m){
        scf("%lld", &tim[i]);
    }
    fu(i, 1, n){
        scf("%d", &len[i]);
        a[i].resize(len[i] + 1);
        t[i].resize(len[i] + 1);
        fu(j, 1, len[i]){
            scf("%d%lld", &a[i][j], &t[i][j]);
            sub[a[i][j]].push_back({i, t[i][j]});
        }
    }
    fu(i, 1, q){
        scf("%d%d", &qs[i].x, &qs[i].y);
    }

    //m d

    memset(re, 0x3f, sizeof(re));
    fu(i, 1, n){
        re[i][i] = 0;
        fu(j, 1, len[i]){
            for(auto [sw, tt] : sub[a[i][j]]){
                if(sw != i){
                    re[i][sw] = min(re[i][sw], t[i][j] + tt);
                }
            }
        }
    }

    // fu(i, 1, n){
    //     fu(j, 1, n){
    //         re[i][j] = min(re[i][j], re[j][i]);
    //         prf("%lld%c", re[i][j], " \n"[j == n]);
    //     }
    // }


    //n^3
    fu(k, 1, n){
        fu(i, 1, n){
            fu(j, 1, n){
                if(re[i][k] <= 1e15 && re[k][j] <= 1e15){
                    re[i][j] = min(re[i][j], re[i][k] + re[k][j]);
                }
            }
        }
    }

    // fu(i, 1, n){
    //     fu(j, 1, n){
    //         prf("%lld%c", re[i][j], " \n"[j == n]);
    //     }
    // }

    //q d^2
    fu(qq, 1, q){
        ll ans = 1e18;
        for(auto [i, ti] : sub[qs[qq].x]){
            for(auto [j, tj] : sub[qs[qq].y]){
                ans = min(ans, ti + re[i][j] + tj);
            }
        }
        prf("%lld\n", tim[qs[qq].x] + ans + tim[qs[qq].y]);
    }

    return 0;
}