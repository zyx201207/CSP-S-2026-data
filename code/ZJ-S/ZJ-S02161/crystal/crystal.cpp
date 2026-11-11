#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,x,y) for(int (i)=(x);(i)<=(y);++i)
const ll N=5e5+10;

ll n,a[N],sum[N],m;

bool check(ll x){
    // cout<<x<<'\n';
    for(int i=1;i+x-1<=n;++i){
        if(a[i+x-1]*x-(sum[i+x-1]-sum[i-1])<=m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    rep(i,1,n) sum[i]=sum[i-1]+a[i];
    ll l=0,r=n+1,mid;
    while(l+1<r){
        mid=l+r>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<'\n';

    return 0;
}