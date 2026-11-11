#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    long long res=0,ans=0;
    for(int i=1,l=1;i<=n;i++){
        res+=(i-l)*(a[i]-a[i-1]);
        while(res>m)res-=(a[i]-a[l++]);
        // cerr<<"! "<<i<<' '<<l<<' '<<res<<'\n';
        ans=max(ans,i-l+1ll);
    }
    cout<<ans<<'\n';
    return 0;
}