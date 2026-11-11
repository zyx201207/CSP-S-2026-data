#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500002];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];

    sort(a+1,a+n+1);

    ll sum=0,ans=1;
    ll l=1,r=2;
    for(l=1,r=max(r,l+1);l<=n;++l){
        while(sum+(a[r]-a[r-1])*(r-l) <= m && r <= n){
            sum += (a[r]-a[r-1])*(r-l);
            ++r;
        }
        r--;
        sum -= a[r]-a[l];
        ans = max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}

