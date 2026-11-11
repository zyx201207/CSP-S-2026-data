#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+5;
int n;
ll m;
ll a[maxn];
ll sum[maxn];
int ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
    int i=1,j=2;
    while(j<=n){
        int mid=(i+j)>>1;
        ll t=(sum[j]-sum[mid])-(sum[mid-1]-sum[i-1]);
        if(t<m) ans=max(ans,(j++)-i+1);
        else j=max(j,(++i)+1);
    }
    cout<<ans<<'\n';
    return 0;
}