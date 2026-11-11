#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define scf scanf
#define prf printf
#define fu(_zzz_, _l_, _r_) for(auto _zzz_ = _l_; _zzz_ <= _r_; _zzz_++)
#define fd(_zzz_, _l_, _r_) for(auto _zzz_ = _l_; _zzz_ >= _r_; _zzz_--)

int n;
ll a[500010], m;

signed main(){

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scf("%d%lld", &n, &m);
    fu(i, 1, n){
        scf("%lld", &a[i]);
    }

    sort(a + 1, a + n + 1);

    int j = 1, ans = 1;
    ll s = 0;
    fu(i, 2, n){
        s += (a[i] - a[i - 1]) * (i - j);
        while(s > m){
            s -= (a[i] - a[j++]);
        }
        ans = max(ans, i - j + 1);
    }

    prf("%d\n", ans);

    return 0;
}