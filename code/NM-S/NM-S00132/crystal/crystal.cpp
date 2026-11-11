#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    ll ans=0;
    ll l=1;
    ll tmp=0;
    for(ll i=1;i<=n;i++){
        tmp+=(i-l)*(a[i]-a[i-1]);
        while(tmp>m&&l<i)l++,tmp-=a[i]-a[l];
        ans=max(ans,i-l+1);
    }
    printf("%lld",ans);
    return 0;
}
