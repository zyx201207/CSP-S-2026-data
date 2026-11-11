#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],l,mid,ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        mid+=(i-l-1)*(a[i]-a[i-1]);
        while(mid>m)l++,mid-=(a[i]-a[l]);
        ans=max(ans,i-l);
    }
    cout<<ans;
    return 0;
}
