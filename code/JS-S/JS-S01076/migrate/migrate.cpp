#include<bits/stdc++.h>
#define ld long double
#define ll long long
#define ii int
using namespace std;
ld Maybe_1_0_ = 0.000000000001;
const ii maxn = 2e6 + 5;
inline void rd(ii &x){
    ii res = 0, f = 1; char c = getchar();
    while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)){ res = res * 10 + c - '0'; c = getchar(); }
    x = res * f;
}
inline void rdll(ll &x){
    ll res = 0, f = 1; char c = getchar();
    while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)){ res = res * 10 + c - '0'; c = getchar(); }
    x = res * f;
}
ii c, T;
ii n;
ll m, x[maxn];
inline void solve(){
    rd(n);rdll(m);
    ll ans = 0;
    bool flg = 0;
    for(ii i = 1;i <= n;++i){
        rdll(x[i]);
        if(x[i] - x[i - 1] <= m && i >= 2) flg = 1;
    }
    if(!flg || n <= 3) printf("0\n");
    for(ii i = 1;i <= n - 3;++i){
        if(x[i + 3] - x[i] <= 2 * m) ans++;
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    rd(c);rd(T);
    while(T--) solve();
    return 0;
}
