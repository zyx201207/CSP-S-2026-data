#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll l=1,r=i,mid,now=0;
        while(l<=r){
            mid=(l+r)/2;
            //cout<<i<<" "<<mid<<" "<<mid*a[i]-(s[i]-s[i-mid])<<" "<<s[i]<<endl;
            if(mid*a[i]-(s[i]-s[i-mid])<=m){
                now=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,now);
    }
    cout<<ans<<endl;
}