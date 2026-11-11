#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll a[N],sum[N],b[N];
ll n,m;
ll lower(){
    ll l=1,r=n,ans;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(m>=b[mid]){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);

    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        b[i]=1LL*i*a[i]-sum[i];
    }

    ll pos=lower();
    printf("%lld\n",pos);
    return 0;
}
