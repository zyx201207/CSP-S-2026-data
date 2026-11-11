#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> a(500009);
ll n,m;
vector<ll>p(500009);
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    a[0]=0;
    p[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=1;
    ll ans2=1;
    sort(a.begin()+1,a.begin()+n+1);
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
    }
    for(ll i=2;i<=n;i++){
        ll l=1,r=i;
        while(l<r){
            ll mid=l+(r-l)/2;
            ll cnt=(i-1-mid+1)*a[i]-(p[i-1]-p[mid-1]);
            if(cnt>m){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        ans2=i-l+1;
        ans=max(ans,ans2);
    }
    cout<<ans;
    return 0;
}