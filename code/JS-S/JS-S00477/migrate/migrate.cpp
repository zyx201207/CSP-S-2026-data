#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+3,inf=INT_MAX;
int c,t,n,d,dist[N],x[N],d2[N],cnt,ans;
vector<int> g[N];
bool vis[N];
int bfs(int st,int ed)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        dist[i]=inf,vis[i]=0;
    dist[st]=0;
    vis[st]=1;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(auto v:g[u])
            if(dist[v]>dist[u]+1)
            {
                if(!vis[v]) q.push(v);
                dist[v]=dist[u]+1;
            }
    }
    return dist[ed];
}
void mark()
{
    for(int i=1;i<=n;i++)
        vis[i]=0;
    return;
}
void dfs(int u,int ed,int l,int s)
{
    if(u==ed)
    {
        //cout<<s<<"de";
        if(l==s) cnt++;
        return;
    }
    if(s>=l) return;
    for(auto v:g[u])
    {
        if(!vis[v])
        {
            vis[v]=1;
            dfs(v,ed,l,s+1);
            vis[v]=0;
        }
    }
    return;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        ans=cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i],g[i].clear();
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n&&x[j]-x[i]<=d;j++)
                g[i].push_back(j),g[j].push_back(i);
        /*for(int i=1;i<=n;i++)
                for(auto v:g[i])
                    cout<<i<<":"<<v;*/
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                vis[i]=1;
                cnt=0;
                int m=bfs(i,j);
                mark();
                dfs(i,j,m,0);
                if(cnt==2) ans++;
                //cout<<cnt<<" ";
            }
        cout<<ans<<"\n";
    }
    return 0;
}/*0 2
5 3
 -2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6*/
