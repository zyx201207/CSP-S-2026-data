#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010],k[50],vis[200010];
int ans=0;
int n,m;
int cnt=0;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    k[0]=1;
    for(int i=1;i<=31;i++)
    {
        k[i]=k[i-1]*2;
    }
    for(int i=31;i>=0;i--)
    {
        cnt=0;
        for(int j=1;j<=n;j++)
        {
            vis[j]=1;
        }
        for(int j=1;j<=n;j++)
        {
            if((a[j]>>i)%2==1)
            {
                cnt++;
            }
            else
            {
                vis[j]=0;
            }
        }
        if(cnt>=m)
        {
            ans+=k[i];
            for(int j=1;j<=n;j++)
            {
                if(vis[j]==0)
                {
                    a[j]=0;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
