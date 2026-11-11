#include<bits/stdc++.h>
#define ll long long
#define inf 3e18
#define atn 522222
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define f(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
ll n,m,a[atn];
bool ck(ll x){
    ll tt=0,mn=inf;
    f(i,1,x-1){
        tt+=a[x]-a[i];
    }
    mn=min(mn,tt);
    f(i,2,n-x+1){
        tt=tt-(a[i+x-2]-a[i-1])+(x-1)*(a[i+x-1]-a[i+x-2]);
        mn=min(mn,tt);
    }
    return (mn<=m);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    f(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    ll l=1,r=n,ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(ck(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
