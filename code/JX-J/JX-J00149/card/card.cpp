#include<bits/stdc++.h>
using namespace std;
int a[500010];
int vis[500010];
int ans[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++)
        {
            bool flag=false;
            for(int k=i;k<=j-1;k++)
            {
                if(flag)
                {
                    vis[k]=1;
                }
                else if(a[k]==a[j]&&vis[k]==0)
                {
                    flag=true;
                    vis[k]=1;
                }
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(vis[j]==0)
            {
                for(int k=1;k<=m;i++)
                {
                    if(a[j]==k)
                    {
                        ans[k]++;
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
