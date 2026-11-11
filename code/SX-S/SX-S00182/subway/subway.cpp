#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
const int N=505;
ll w[N][N][3];
bool st[N][N][3];
int pos[N][N];
int c,n,m,dddd,q;
const int M=5e5+5;
ll pre[M];
struct node{
    int v;
    ll we;
};
vector<node> to[M];
vector<int> g[N+2];
struct tg{
    int i,j,k;
};
vector<tg> del;
ll d[N+2];
bool vis[N+2];
typedef pair<ll,int> PII;
void dij(int x)
{
    for(int i=0;i<N+2;i++)
    {
        d[i]=inf;
        vis[i]=0;
    }
    priority_queue<PII,vector<PII>,greater<PII> > q;
    q.push({0,x});
    d[x]=0;
    while(q.size())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto j:g[u])
        {
            ll we=inf;
            for(int k=0;k<=2;k++)
                if(!st[u][j][k])
                    we=min(we,w[u][j][k]);
            if(we==inf) continue;
            if(d[j]>d[u]+we)
            {
                d[j]=d[u]+we;
                q.push({d[j],j});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    for(int k=0;k<3;k++)
        w[i][j][k]=inf;        
    cin>>c>>n>>m>>dddd>>q;
    for(int i=1;i<=m;i++)
        cin>>pre[i];
    for(int i=1;i<=n;i++)
    {
        int ki;cin>>ki;
        while(ki--)
        {
            int ai,ti;
            cin>>ai>>ti;
            to[ai].push_back({i,ti});
        }
    }
    for(int i=1;i<=m;i++)
    {
        int len=to[i].size();
        for(int x=0;x<len;x++)
        {
            for(int y=0;y<len;y++)
            {
                if(x==y) continue;
                int u=to[i][x].v;
                int v=to[i][y].v;
                ll wei=to[i][x].we+to[i][y].we;
                if(wei<=w[u][v][0]){
                    w[u][v][2]=w[u][v][1];
                    w[u][v][1]=w[u][v][0];
                    w[u][v][0]=wei;
                }else if(wei<=w[u][v][1]){
                    w[u][v][2]=w[u][v][1];
                    w[u][v][1]=wei;
                }else if(wei<=w[u][v][2])
                    w[u][v][2]=wei;
            }
        }
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        if(w[i][j][0]!=inf)
        {
            g[i].push_back(j);
            g[j].push_back(i);
        }
    while(q--)
    {
        int xr,yr;
        cin>>xr>>yr;
        int len=to[xr].size();
        for(int x=0;x<len;x++)
        {
            g[n+1].push_back(to[xr][x].v);
            w[n+1][to[xr][x].v][0]=to[xr][x].we;
            for(int y=x+1;y<len;y++)
            {
                int u=to[xr][x].v;
                int v=to[xr][y].v;
                ll wei=to[xr][x].we+to[xr][y].we;
                for(int k=0;k<3;k++)
                if(w[x][y][k]==wei&&st[x][y][k]==0) 
                {
                    st[x][y][k]=1;
                    k=4;
                    del.push_back({x,y,k});
                }
            }
        }        
        len=to[yr].size();
        for(int x=0;x<len;x++)
        {
            g[to[yr][x].v].push_back(n+2);
            w[to[yr][x].v][n+2][0]=to[yr][x].we;
            for(int y=x+1;y<len;y++)
            {
                int u=to[yr][x].v;
                int v=to[yr][y].v;
                ll wei=to[yr][x].we+to[yr][y].we;
                for(int k=0;k<3;k++)
                if(w[x][y][k]==wei&&st[x][y][k]==0) 
                {
                    st[x][y][k]=1;
                    k=4;
                    del.push_back({x,y,k});
                }
            }
        }   
        dij(n+1);
        cout<<d[n+2]+pre[xr]+pre[yr]<<"\n";
        for(auto x:del)
            st[x.i][x.j][x.k]=0;
        while(g[n+1].size()) g[n+1].pop_back();
        for(int i=1;i<=n;i++)
            if(g[i].back()==n+2)
                g[i].pop_back();
        for(int i=1;i<=n+2;i++) {
            w[i][n+1][0]=inf;
            w[n+1][i][0]=inf;
            w[i][n+2][0]=inf;
            w[n+2][i][0]=inf;
        }
    }
    return 0;
}