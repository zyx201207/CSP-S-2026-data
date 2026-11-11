#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n,m,a[510000];

ll sum[510000];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1; i<=n; ++i){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i = 1; i<=n; ++i) sum[i] = a[i] + sum[i-1];
    // for(int i = 1; i<=n; ++i) cout << sum[i] << ' ';
    ll l = 1, ans = 1;
    for(int r = 1; r<=n; ++r){
        while(a[r] * (r-l+1) - (sum[r] - sum[l-1]) > m){
            ++l;
        }
        ans = max(ans,r-l+1);
        // cout << l << ' ' << r<<'\n';
    }
    printf("%lld\n",ans);
    return 0;
}
