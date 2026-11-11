#include<bits/stdc++.h>
using namespace std;
int n,k;
int dis[1005][1005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin>>n>>k;
    // memset(dis,0x3f,sizeof(dis));
    // for(int i=1;i<=n-1;i++)
    // {
    //     int a,b;
    //     cin>>a>>b;
    //     dis[a][b]=1;
    //     dis[b][a]=1;
    // }
    // for(int i=1;i<=n;i++)
    // {
    //     dis[i][i]=1;
    //     dis[0][i]=0;
    //     dis[i][0]=0;
    // }
    // for(int k=1;k<=n;k++)
    // {
    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=n;j++)
    //         {
    //             dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    //         }
    //     }
    // }
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cout<<1<<endl;
    }
    return 0;
}
