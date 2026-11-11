#include<queue>
#include<iostream>
using namespace std;
bool mst;
const int N=2e6+6,M=4000,inf=1e9;
int ans,n,k,fw[N],dep[N],mxd[N],dis[N],siz[N],tick,st[N],ed[N];
bool vis[N];int f[M][M],g[M];
int tot,ver[N<<1],nxt[N<<1],head[N];
void add(int x,int y)
    {ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;}
void dfs(int x,int fa)
{
    st[x]=++tick;
    mxd[x]=dep[x]=dep[fa]+1,fw[x]=fa;
    for(int i=head[x];i;i=nxt[i])
    {
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x),mxd[x]=max(mxd[x],mxd[y]);
    }
    ed[x]=tick;
}
void sfd(int x)
{
    int ct=1;
    for(int i=head[x];i;i=nxt[i])
    {
        int y=ver[i];
        if(y==fw[x])continue;
        sfd(y);
        for(int a=1;a<=ct+siz[y];a++)
            g[a]=max(f[x][a],mxd[y]-dep[x]);
        for(int a=1;a<=ct;a++)
            for(int b=1;b<=siz[y];b++)
                g[a+b]=min(g[a+b],max(f[x][a],f[y][b]));
        for(int a=1;a<=ct+siz[y];a++)f[x][a]=g[a];
        ct+=siz[y];
    }
    siz[x]=ct;
}
int solve(int x,int y)
{
    for(int i=1;i<=n;i++)vis[i]=dis[i]=0;
    vis[x]=vis[fw[x]]=true;
    if(y)vis[y]=vis[fw[y]]=true;
    dis[fw[x]]=1;
    if(y)dis[fw[y]]=1;
    queue<int> q;
    q.push(fw[x]);
    if(y)q.push(fw[y]);
    while(q.size())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nxt[i])
        {
            int v=ver[i];
            if(vis[v])continue;
            vis[v]=true;
            dis[v]=dis[u]+1,q.push(v);
        }
    }
    int ret=0;
    for(int i=1;i<=n;i++)
        if(vis[i])ret=max(ret,dis[i]);
    return ret;
}
void work()
{
    cin>>n>>k,ans=inf;
    for(int i=1,u,v;i<n;i++)
        cin>>u>>v,add(u,v),add(v,u);
    dfs(1,0),sfd(1);
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
        {
            if(st[y]<=st[x] && st[x]<=ed[y])continue;
            if(st[x]<=st[y] && st[y]<=ed[x])continue;
            int ret=solve(x,y);
            for(int i=1;i<k;i++)
                ans=min(ans,max(max(f[x][i],f[y][k-i]),ret));
        }
    for(int x=2;x<=n;x++)
        ans=min(ans,max(f[x][k],solve(x,0)));
    tot=tick=0;
    for(int i=1;i<=n;i++)
    {
        head[i]=0;
        for(int j=1;j<=n;j++)f[i][j]=0;
    }
    cout<<ans<<'\n';
}
bool med;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--)work();
    cerr<<(1.0*clock())/CLOCKS_PER_SEC<<endl;
    cerr<<abs(&mst-&med)/1024.0/1024.0<<"MB\n";
}