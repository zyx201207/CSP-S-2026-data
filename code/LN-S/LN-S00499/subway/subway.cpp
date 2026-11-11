#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[510],a[510][500010],t[510][500010],dis[500010];
bool vis[500010];
struct node{
    int v;
    int l;
};
vector <node> g[700010];
int check(int x,int y)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[x]=0;
    int p=-1;
    while(true)
    {
        p=-1;
        for(int i=1;i<=n*m;i++)
        {
            if(vis[i])
            {
                continue;
            }
            if(p==-1||dis[p]>dis[i])
            {
                p=i;
            }
        }
        if(p==-1||dis[p]==0x3f3f3f3f)
        {
            break;
        }
        vis[p]=true;
        for(node e:g[p])
        {
            int v=e.v,w=e.l;
            dis[v]=dis[p]+w;
        }
    }
    return dis[y];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        int w;
        cin>>w;
        g[i*n-n+1].push_back({i*n-n,w});
        g[i*n-n].push_back({i*n-n+1,w});
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<k[i];j++)
        {
            g[a[i][j]*n-n+i+1].push_back({a[i][j+1]*n-n+i+1,0});
            g[a[i][j+1]*n-n+i+1].push_back({a[i][j]*n-n+i+1,0});
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<check(x*n-n,y*n-n)<<'\n';
    }

    return 0;
}
