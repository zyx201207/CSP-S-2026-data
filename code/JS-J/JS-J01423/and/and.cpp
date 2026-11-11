#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans,sum,a[200005],vis[200005],n,m;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    cin>>n>>m;sum=n;
    for(int i=1;i<=n;i++) cin>>a[i],vis[i]=1;
    for(int j=29;j>=0;j--)
    {
        int cnt=0,b=(1<<j);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]&&(a[i]&b)==b) cnt++;
        }
        if(cnt<m) continue;
        ans+=b;
        for(int i=1;i<=n;i++) if(vis[i]&&(a[i]&b)==0) vis[i]=0,sum--;
        if(sum<m) break;
    }
    cout<<ans;
}
