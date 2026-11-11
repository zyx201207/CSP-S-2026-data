#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
struct cb
{
    int ne;
    int w;
};
struct yh{
    int x;
    int w;
    bool operator<(const yh & x)const
    {
        return w>x.w;
    }
};
int c,n,m,d,q;
int t[100001];
int a[100001];
int b[100001];
int dis[100001];
bool vis[100001];
vector<cb>ct[100001];
void dijkstra(int u)
{
    dis[u]=0;
    priority_queue<yh>dyh;
    dyh.push({u,0});
    while(!dyh.empty())
    {
        int x=dyh.top().x;
        dyh.pop();
        if(vis[x])
            continue;
        for(int i=0;i<ct[x].size();i++)
        {
            if(dis[ct[x][i].ne]>dis[x]+ct[x][i].w)
            {
                dis[ct[x][i].ne]=dis[x]+ct[x][i].w;
                dyh.push({ct[x][i].ne,dis[ct[x][i].ne]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[j]>>t[j];
            for(int x=1;x<j;x++)
            {
                ct[a[x]].push_back({a[j],t[j]+t[x]});
                ct[a[j]].push_back({a[x],t[j]+t[x]});
            }
        }
    }

    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        for(int j=1;j<=m;j++)
        {
            dis[j]=0x3f3f3f3f;
            vis[j]=0;
        }
        dijkstra(u);
        cout<<dis[v]+b[u]+b[v]<<endl;
    }
    return 0;
}
