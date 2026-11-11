#include<bits/stdc++.h>
#define N 505
#define M 500005
#define ll long long
#define inf (ll)1e18
#define mod 
using namespace std;

int read()
{
    int x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x*f;
}

vector<pair<int,int>>vec[M];
int cid,n,m,d,q,a[M],hd[M],nxt[M],pos[M],val[M],tot;
ll f[N][N];

void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cid=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=m;i++) a[i]=read();
    for(int i=1;i<=n;i++)
    {
        int k=read();
        while(k--)
        {
            int x=read(),w=read();
            pos[++tot]=i;
            val[tot]=w;
            nxt[tot]=hd[x];
            hd[x]=tot;
            // vec[x].push_back({i,w});
        }
    }
    for(int i=1;i<=n;i++) fill(f[i]+1,f[i]+n+1,inf),f[i][i]=0;
    for(int x=1;x<=m;x++)
    {
        // int len=vec[x].size();
        // for(int i=0;i<len;i++)
        // {
        //     int u=vec[x][i].first,p=vec[x][i].second;
        //     for(int j=i+1;j<len;j++)
        //     {
        //         int v=vec[x][j].first,q=vec[x][j].second;
        //         f[u][v]=min(f[u][v],1ll*p+q);
        //         f[v][u]=f[u][v];
        //         // cerr<<u<<"-"<<v<<' '<<f[u][v]<<'\n';
        //     }
        // }
        for(int i=hd[x];i;i=nxt[i])
        {
            int u=pos[i],p=val[i];
            for(int j=nxt[i];j;j=nxt[j])
            {
                int v=pos[j],q=val[j];
                f[u][v]=min(f[u][v],1ll*p+q);
                f[v][u]=f[u][v];
                // cerr<<u<<"-"<<v<<' '<<f[u][v]<<'\n';
            }
        }
    }
    floyd();
    while(q--)
    {
        int u=read(),v=read();
        ll ans=inf;
        // for(auto i:vec[u])
        // {
        //     for(auto j:vec[v])
        //     {
        //         ans=min(ans,i.second+j.second+f[i.first][j.first]);
        //     }
        // }
        for(int i=hd[u];i;i=nxt[i])
        {
            for(int j=hd[v];j;j=nxt[j])
            {
                ans=min(ans,val[i]+val[j]+f[pos[i]][pos[j]]);
            }
        }
        cout<<ans+a[u]+a[v]<<'\n';
    }
    return 0;
}
// Code by Jorisy, after retiring. Just enjoy it.
// Sometimes 0.95s sometimes 1.03s.
// Will it pass???
// Ah, i forget -O2. 0.28s. Cool.