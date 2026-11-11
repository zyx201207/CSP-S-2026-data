#include<bits/stdc++.h>
using namespace std;
#define pr pair<long long,int>
struct name{
    int v,w,nxt;
} e[500005];
int idx,head[505];
long long read(){
    long long x=0,f=1;
    char ch;
    ch=getchar();
    while(ch>'9' || ch<'0')
    {
        if(ch =='0')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return f*x;
}
void build(int u,int v,int w){
    e[++idx]={v,w,head[u]};
    head[u]=idx;
}

long long dis[505],d[505][505],ansv[505][505],c,n,m,q,l,w[500005];
bool f[505][505],vis[505];
vector<pair<int,long long>> v[500005];

void fun(int s)
{
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    priority_queue<pr,vector<pr>,greater<pr>> q;
    q.push({0,s});
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u])
            continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nxt)
        {
            long long w=e[i].w,v=e[i].v;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),l=read(),q=read();
    for(int i=1;i<=m;i++)
        w[i]=read();
    for(int i=1;i<=n;i++)
    {
        int k=read();
        while(k--)
        {
            int x=read(),y=read();
            v[x].push_back({i,y});
        }
    }
    memset(d,0x5f,sizeof d);
    for(int i=1;i<=m;i++)
    {
        int s=v[i].size();
        for(int j=0;j<s;j++)
        {
            int a=v[i][j].first;
            for(int k=j+1;k<s;k++)
            {
                int b=v[i][k].first;
                d[a][b]=d[b][a]=min(d[a][b],v[i][j].second+v[i][k].second),f[a][b]=f[b][a]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j])
                build(i,j,d[i][j]);
    for(int i=1;i<=n;i++)
    {
        fun(i);
        for(int j=1;j<=n;j++)
            ansv[i][j]=dis[j];
    }
    while(q--)
    {
        int x=read(),y=read();
        int s1=v[x].size(),s2=v[y].size();
        long long ans=ansv[v[x][0].first][v[y][0].first]+v[x][0].second+v[y][0].second;
        for(int i=0;i<s1;i++)
        {
            int a=v[x][i].first;
            for(int j=0;j<s2;j++)
            {
                int b=v[y][j].first;
                ans=min(ans,ansv[a][b]+v[x][i].second+v[y][j].second);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
