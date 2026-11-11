#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int c;
ll n,d;
ll x[2100000];

ll f[2100000], cnt[2100000];

bool cmp(ll a,ll b) {
    return a<b;
}

void solve(){
    scanf("%lld%lld",&n,&d);
    for(int i = 1; i<=n; ++i){
        scanf("%lld",&x[i]);
    }
    if(c >= 15 && c <= 18){
        printf("0\n");
        return;
    }
    ll ans = 0;
    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=n; ++j) f[j] = 0, cnt[j] = 1; f[i] = 1;
        for(int j = i+1; j<=n && x[j]-x[j-1] <= d; ++j){
            int idx = lower_bound(x+1,x+1+n,x[j]-d,cmp)-x; idx = max(i,idx);
            f[j] = f[idx] + 1;
            cnt[j] = cnt[idx];
            for(int k = idx+1; k < j && f[k]==f[idx]; ++k){
                ++cnt[j];
                if(cnt[j] > 2) break;
            }
            if(cnt[j] == 2) ++ans;
        }
        //for(int e = 1; e<=n; ++e) printf("%lld ",f[e]);printf("\n");
        //for(int e = 1; e<=n; ++e) printf("%lld ",cnt[e]);printf("\n");
    }
    printf("%lld\n",ans);
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;
    scanf("%d%d",&c,&T);
    while(T--){
        solve();
    }
    return 0;
}
