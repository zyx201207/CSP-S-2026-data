#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,ans=0;
vector<ll>a,sum;
bool check(ll x,ll y){
    ll cnt=(y-x)*a[y]-sum[y-1]+sum[x-1];
    if(cnt<=m){
        return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    a.push_back(0);
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    sum.push_back(0);
    for(ll i=1;i<=n;i++){
        sum.push_back(sum[i-1]+a[i]);
    }
    for(ll i=1;i<=n;i++){
        ll l=1,r=i,res=i;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(check(mid,i)){
                r=mid-1;
                res=mid;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans<<'\n';
    return 0;
}
