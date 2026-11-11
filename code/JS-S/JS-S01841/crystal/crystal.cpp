#include<bits/stdc++.h>
#define fast (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
#define ll long long
#define ld long double
#define ull unsigned long long
using namespace std;
ll n,m,a[500005],b[500005];
signed main(){
    fast;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)b[i]=a[i]-a[i-1];
    ll x=1,y=1,cnt=0,ans=0;
    while(y<=n){
        cnt+=(y-x)*b[y];
        while(cnt>m){
            cnt-=(a[y]-a[x]);
            x++;
        }
        ans=max(ans,y-x+1);
        y++;
    }
    cout<<ans;
    return 0;
}
