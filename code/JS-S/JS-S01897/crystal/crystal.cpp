#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 5e5+10;
ll sum[maxn],a[maxn],n,m,ans;

ll f(ll l,ll r){return a[r]*(r-l)-(sum[r]-sum[l]);}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(ll i = 1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i = 1;i<=n;i++)
        sum[i] = sum[i-1]+a[i];
    for(ll l = 0,r = 0;r <= n;){
        while(f(l,r) > m) l++;
        while(r+1 <= n && f(l,r+1) <= m) r++;
        //cout<<l<<" "<<r<<"  r-l: "<<r-l<<"\n";
        ans = max(ans,r-l);
        r++;
    }
    cout<<ans<<"\n";
    return 0;
}