#include<bits/stdc++.h>
using namespace std;
int e[505][505];
int a[2000005];
struct ed{
    int ud;
    int w;
}u[505];
void c7()
{
    memset(e,0x3f,sizeof(e));
    int m,n,d,q;
    cin>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        e[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        int k;
        cin>>k;
        if(k==1)
        {
            int aa,bb;
            cin>>aa>>bb;
            continue;
        }
        for(int j=1;j<=k;j++)
            cin>>u[j].ud>>u[j].w;
        for(int j=1;j<=k;j++)
        {
            for(int l=j+1;l<=k;l++)
            {
                e[u[j].ud][u[l].ud]=min(e[u[j].ud][u[l].ud],u[j].w+u[l].w);
                e[u[l].ud][u[j].ud]=min(e[u[l].ud][u[j].ud],u[j].w+u[l].w);
            }
        }
    }
    //for(int i=1;i<=n;i++)
    //{
    //    for(int j=1;j<=n;j++)
     //       cout<<e[i][j]<<' ';
    //   cout<<endl;
    //}
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            for(int j=1;j<=n;j++)
            {
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
                e[j][i]=e[i][j];
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<e[x][y]+a[x]+a[y]<<endl;
    }
}
void c711()
{
    memset(e,0x3f,sizeof(e));
    int m,n,d,q;
    cin>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        e[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        int k;
        cin>>k;
        if(k==1)
        {
            int aa,bb;
            cin>>aa>>bb;
            continue;
        }
        int u,v,i1,i2;
        cin>>u>>i1>>v>>i2;
        e[u][v]=min(e[u][v],i1+i2);
        e[v][u]=min(e[v][u],i1+i2);
    }
    //for(int i=1;i<=n;i++)
    //{
    //    for(int j=1;j<=n;j++)
     //       cout<<e[i][j]<<' ';
    //   cout<<endl;
    //}
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            for(int j=1;j<=n;j++)
            {
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
                e[j][i]=e[i][j];
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<e[x][y]+a[x]+a[y]<<endl;
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int c;
    cin>>c;
    if(c>=7&&c<=11)
    {
        c711();
    }
    if(c<7)
    {
        c7();
    }
    return 0;
}
