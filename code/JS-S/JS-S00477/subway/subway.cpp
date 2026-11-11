#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=503,M=5e5+3,QQ=1e5+3;
const ll inf=INT_MAX;
int c,n,m,D,Q,w[M],a[N][N],t[N][N],x[QQ],y[QQ],ans[QQ],d[20004][20004];
ll dist[M+N],t0[N];
bool vis[M+N];
struct edge{
    int to,w;
};
vector<edge> g[N+M];
struct node{
    int du,u;
};
bool operator<(node x,node y)
{
    return x.du>y.du;
}
priority_queue<node>q;
void dijkstra(int st)
{
    for(int i=1;i<=m;i++)
        dist[i]=inf,vis[i]=0;
    dist[st]=0;
    q.push({0,st});
    while(!q.empty())
    {
        node t=q.top();
        q.pop();
        if(vis[t.u]) continue;
        vis[t.u]=1;
        for(auto v:g[t.u])
            if(dist[t.u]+v.w<dist[v.to]) dist[v.to]=dist[t.u]+v.w,q.push({dist[v.to],v.to});
    }
    return;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>D>>Q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
        for(int j=1;j<=a[i][0];j++)
            cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=Q;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=inf;
    for(int i=1;i<=n;i++)
            for(int j=1;j<=a[i][0];j++)
                for(int k=1;k<=a[i][0];k++)
                    if(a[i][j]!=a[i][k]) d[a[i][j]][a[i][k]]=d[a[i][k]][a[i][k]]=t[i][j]+t[i][k],g[a[i][j]].push_back({a[i][k],t[i][j]+t[i][k]}),g[a[i][k]].push_back({a[i][j],t[i][j]+t[i][k]});
    /*for(int i=1;i<=n;i++)
    {
        t0[i]=inf;
        for(int j=1;j<=a[i][0];j++)
            t0[i]=min(t0[i],1ll*t[i][j]);
        cout<<"\n"<<t0[i]<<" ";
        for(int j=1;j<=a[i][0];j++)
        cout<<a[i][j]<<"-"<<m+i<<" ",g[a[i][j]].push_back({m+i,t0[i]}),g[m+i].push_back({a[i][j],t0[i]});
    }*/
    /*for(int i=1;i<=m;i++)
    {
        cout<<i<<" ";
        for(auto v:g[i])
            cout<<v.to<<": "<<v.w<<" ";
        cout<<"\n";
    }*/
    for(int i=1;i<=Q;i++)
    {
        dijkstra(x[i]);
        //cout<<d[x[i]][y[i]]<<" "<<dist[y[i]]<<" ";
        ans[i]=min(1ll*d[x[i]][y[i]],dist[y[i]]);
        ans[i]+=w[x[i]]+w[y[i]];
        cout<<ans[i]<<"\n";
    }
    return 0;
}
