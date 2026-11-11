#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+5;
int c,n,m,d,q;
int w[N];
int dis[N][N];
int a[N][N],t[N][N];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    /*1.work out the distance to get each station from i
      2.make the shortest distance priority(how)*/
    scanf("%lld%lld%lld",&c,&n,&m);
    scanf("%lld%lld",&d,&q);//mp[i][j] is the distance from station i to station j
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
        {
            dis[i][j]=0x3f3f3f3f;
        }
   for(int i=1;i<=m;i++)dis[i][i]=0;
   for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%lld",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%lld%lld",&a[i][j],&t[i][j]);
            int v=a[i][j];
            for(int l=1;l<j;l++)
            {
                int u=a[i][l];
                    //cout<<t[i][l]+t[i][k]<<endl;
                    //cout<<v<<" "<<u<<" kk"<<endl;
                   // cout<<dis[v][u]<<" "<<t[i][l]+t[i][k]<<endl;

                 dis[v][u]=min(dis[v][u],t[i][l]+t[i][j]);
                 //cout<<v<<" "<<u<<" "<<dis[v][u]<<endl<<endl;
                 dis[u][v]=dis[v][u];
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<i;j++)
        {
            for(int k=1;k<j;k++)
            {
                if(dis[i][k]>dis[i][j]+dis[j][k]&&i!=j&&i!=k&&j!=k)
                {
                    dis[i][k]=dis[i][j]+dis[j][k];
                }
            }
        }
    }
    /*for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }*/
    while(q--)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        int ans=min(dis[x][y],dis[y][x]);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
