#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],sum[500005];
int main(){
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+1+n);
ll ans=1;

for(ll i=1;i<=n;i++){
    sum[i]=sum[i-1]+a[i];
    ll l=1,r=i;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m)r=mid-1;
        else l=mid+1;
    }
    ans=max(ans,i-l+1);
}
        cout<<ans;
return 0;
}
