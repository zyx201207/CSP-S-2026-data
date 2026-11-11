#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],sum[500005],ans;
ll solve(ll l,ll r){
    ll t=sum[r]-sum[l-1];
    t+=m;
    t/=(r-l+1);
    return t;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=a[i]+sum[i-1];
    }
    for(int i=1;i<=n;i++){
        ll l=1,r=i;
        while(l<=r){
            ll mid=(l+r)/2;
            ll t=solve(mid,r);
            if(t<a[i]){
                l=mid+1;
            }
            else if(t>=a[i]){
                //cout<<ans<<' '<<r<<' '<<l<<' '<<mid<<' '<<t<<' '<<a[i]<<'\n';
                ans=max(ans,i-mid+1);
                r=mid-1;

            }
        }
    }
    cout<<ans;
    return 0;
}
