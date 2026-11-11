#include <bits/stdc++.h>
#include<cstdio>
#define int long long
using namespace std;
int c,t;
int a[301];
int dis[301][301][2];
bool vis[301][301][301];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        int n,d;
        cin>>n>>d;
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
            for(int k=1;k<=n;k++)
                dis[j][k][0]=0x3f3f3f3f;
            dis[j][j][0]=0;
        }
        for(int x=1;x<=n;x++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(vis[x][j][k]||vis[x][k][j])
                        continue;
                    vis[x][j][k]=1;
                    vis[x][k][j]=1;
                    if(dis[j][x][0]+dis[x][k][0]<dis[j][k][0])
                    {
                        dis[k][j][0]=dis[j][k][0]=dis[j][x][0]+dis[x][k][0];
                        dis[k][j][1]=dis[j][x][1]=0;
                    }
                    else if(dis[j][x][0]+dis[x][k][0]==dis[j][k][0])
                    {
                        dis[j][k][1]++;
                    }
                }
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            for(int k=j;k<=n;k++)
            {
                if(dis[j][k][1]>=2)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
