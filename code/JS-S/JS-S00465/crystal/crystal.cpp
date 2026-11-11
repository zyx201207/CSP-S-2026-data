#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int len=5e5+5;
ll n,m,a[len],sum[len];
bool check(ll x){
    for(int i=x;i<=n;i++){
        ll ned=x*a[i];
        ned-=sum[i]-sum[i-x];
        if(ned<=m) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    ll l=1,r=n,ans=0,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<'\n';
    return 0;
}
