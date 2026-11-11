#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[500005];
ll sum[500005];
ll ans=0;

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin.tie(nullptr)->sync_with_stdio(false);

    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    ll l=1;
    for(ll i=1;i<=n;i++){
        while(l<i&&(a[i]*(i-l+1)-(sum[i]-sum[l-1])>m))l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans<<'\n';

}