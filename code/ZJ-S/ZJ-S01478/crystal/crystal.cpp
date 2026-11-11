#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],sum[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,ans=0,l;
    cin>>n>>m;
    l=n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=n;i>=1;i--){
        while(l>=2&&a[i]*(i-l+2)-(sum[i]-sum[l-2])<=m) l--;
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}