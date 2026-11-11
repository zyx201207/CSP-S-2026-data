#include <bits/stdc++.h>
using namespace std;
const int N=5e5+9;
typedef long long ll;
ll n,m,a[N],sum[N],ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
    for(ll l=1,r=1;l<=n;++l){
        while(r<n&&sum[r+1]-sum[l-1]+m>=a[r+1]*(r-l+2))r++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
