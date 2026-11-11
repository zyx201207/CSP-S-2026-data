#include<bits/stdc++.h>
#define zhan 500000
using namespace std;

struct node
{
    int y,z;
};
queue<node> q1;
int n,m,d,q,c,w[500005],g[2000][2000],num=1;
bool vis[502000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    memset(g,0x3f3f3f3f,sizeof(g));
    for(int i=1;i<=n;i++)
    {
        int k,a1,a2;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a1>>a2;
            g[i+m][a1]=a2;
            g[a1][i+m]=a2;
        }
    }
    for(int i=1;i<=n+m;i++)
    {
        g[i][i]=0;
    }
    for(int i=1;i<=n+m;i++)
    {
        for(int j=1;j<=n+m;j++)
        {
            for(int k=1;k<=n+m;k++)
            {
                g[i][k]=g[k][i]=min(g[i][j]+g[j][k],g[i][k]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<g[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
