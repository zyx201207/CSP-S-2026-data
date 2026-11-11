#include <bits/stdc++.h>
#define int long long

using namespace std;

int read()
{
    int tot=0,f=1;
    char ch=getchar();
    while(ch!='-'&&(ch>'9'||ch<'0'))
        ch=getchar();
    if(ch=='-')
        f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')
        tot=tot*10+(ch-'0'),ch=getchar();
    return tot*f;
}

const int maxn=5e5+10;
int w[maxn],c,n,m,d,q;

const int inf=1e18;

struct edge
{
    int to;
    int w;
    int nxt;
}e[maxn*4];

int cnt=0,head[maxn*2];
void add(int u,int v,int w)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].w=w;
    e[cnt].nxt=head[u];
    head[u]=cnt;
    return ;
}

int idx;
int dist[maxn*2];
bool vis[maxn];

#define fi first
#define se second

int xr,yr;
void solve()
{
    int ans=0;
    for(int i=1;i<=idx;i++)
        dist[i]=inf,vis[i]=0;
    dist[xr]=0;
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,xr});
    while(!q.empty())
    {
        int u=q.top().se;
        q.pop();
        vis[u]=1;
        for(int i=head[u];i!=-1;i=e[i].nxt)
        {
            int v=e[i].to,w=e[i].w;
            if(vis[v])
                continue;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
    ans=dist[yr];
    printf("%lld\n",ans+w[xr]+w[yr]);
    return ;
}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(head,-1,sizeof head);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)
        w[i]=read();
    idx=m+1;
    for(int i=1;i<=n;i++)
    {
        int ki=read();
        vector <int> path;
        for(int j=1;j<=ki;j++)
        {
            int aij=read(),tij=read();
            add(aij,idx,tij);
            add(idx,aij,tij);
            path.push_back(idx);
            idx++;
        }
        for(int i=1;i<ki;i++)
        {
            add(path[i],path[i-1],0);
            add(path[i-1],path[i],0);
        }
    }
    while(q--)
    {
        xr=read(),yr=read();
        solve();
    }
    return 0;
}
