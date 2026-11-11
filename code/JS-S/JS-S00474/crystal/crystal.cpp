#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+2;
int n,m;
int a[M],d[M];
int ans=-1;
int cnt=0;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
    {
        d[i]=d[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    int l=1,r=1;
    for(l=1;l<=n;l++)
    {
        while(r<=n&&d[r]-d[l-1]-(l-1)*(a[r]-a[l])<=m) r++;
        ans=max(ans,r-l);
    }
    cout<<ans;
    return 0;
}
