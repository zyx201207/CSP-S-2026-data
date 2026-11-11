#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define ll long long
const ll maxn = 1e6 * 2 + 10;
ll c, t, n, d, xx[maxn], tmp, aans, ans;
bool vst[maxn];

void doo(ll k, ll l, ll v){
    // printf("==%lld %lld %lld\n", k, l, v);
    if(vst[k]) return;
    // printf("==%lld\n", vst[k]);
    vst[k] = 1;
    if(k == v){
        // printf("%lld, %lld\n", k, l);
        if(l == tmp){
            aans += 1;
        }else if(l < tmp || tmp == -1){
            tmp = l;
            aans = 1;
        }
    }
    // printf("%lld->", k);
    for(ll i = 1; i <= n; i++){
        if(abs(xx[i] - xx[k]) <= d && !vst[i]){
            doo(i, l + 1, v);
        }
    }
    vst[k] = 0;
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld%lld", &c, &t);
    for(ll abcdefg = 1; abcdefg <= t; abcdefg++){
        ans = 0;
        tmp = -1;
        scanf("%lld%lld", &n, &d);
        for(ll i = 1; i <= n; i++){
            scanf("%lld", &xx[i]);
        }
        for(ll i = 1; i < n; i++){
            for(ll j = i + 1; j <= n; j++){
                // printf("--%lld %lld\n", i, j);
                doo(i, 1, j);
                // printf("%lld %llds\n", aans, tmp);
                if(aans == 2){
                    ans += 1;
                    // printf("++\n");
                }
            }
        }
        printf("%lld\n", ans - 1);
    }
    return 0;
}