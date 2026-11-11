#include <bits/stdc++.h>
#define N 500005
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define per(i,l,r) for(ll i=l;i>=r;i--)
#define ll long long
#define insert in
#define pb push_back
using namespace std;
ll n,m;
ll a[N];
ll fun(ll x){
    vector<ll> d;
    rep(i,1,n)if(a[i]<=x)d.pb(abs(a[i]-x));
    sort(d.begin(),d.end());
    ll lim=m,cnt=0;
    for(auto y:d){
        if(lim>=y)cnt++,lim-=y;
        else break;
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    if(a[n]<=100){
        ll ans=0;
        rep(k,a[1],a[n])ans=max(ans,fun(k));
        cout<<ans<<'\n';
        return 0;
    }
    ll f1=1;
    ll l=a[2]-a[1];
    rep(i,2,n)if(a[i]-a[i-1]!=l)f1=0;
    if(f1){
        int id=(n-1)/2+1;
        ll ans=fun(a[id]);
        cout<<ans<<'\n';
        return 0;
    }
    if(n<=5000){
        ll ans=0;
        rep(i,1,n){
            ans=max(ans,fun(a[i]));
        }
        cout<<ans<<'\n';
        return 0;
    }
}