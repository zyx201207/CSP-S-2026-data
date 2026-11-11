#include<bits/stdc++.h>
#define int long long 
const int N=4e3;
using namespace std;
int c,t,n,k,ans;
int dp[N+5][N+5];
vector <int > q[N+5];
int dep[N+5],u[N+5],siz[N+5],dis[N+5],f[N+5],num[N+5];
void dfs(int x,int fa)
{
    f[x]=fa;
    for(int i=0;i<q[x].size();i++)
    {
        int y=q[x][i];
        if(y==fa) continue;
        dfs(y,x);
        dep[x]=max(dep[x],dep[y]+1);
    }
    siz[dep[x]]++;int sum=0;dp[x][0]=dep[x];
    for(int i=1;i<=k;i++) dp[x][i]=INT_MAX;
    for(int i=dep[x];i>=0;i--) 
    {
        sum+=siz[i];
        if(sum>k) break;
        dp[x][sum]=i;
    }
    for(int i=1;i<=k;i++) dp[x][i]=min(dp[x][i-1],dp[x][i]);
}
int dij(int x,int y)
{
    queue <int > p;
    for(int i=1;i<=n;i++)
        if(f[i]==x||f[i]==y||i==x||i==y) dis[i]=0;
        else dis[i]=INT_MAX;
    p.push(x);p.push(y);
    int maxx=0;
    while(!p.empty())
    {
        int u=p.front();p.pop();
        maxx=max(maxx,dis[u]);
        if(maxx>ans) return n;
        for(int i=0;i<q[u].size();i++)
        {
            int v=q[u][i];
            if(dis[u]+1<dis[v])
                dis[v]=dis[u]+1,p.push(v);
        }
    }
    return maxx;
}
void dfs1(int x,int fa,int lim)
{
    dep[x]=0;
    for(int i=0;i<q[x].size();i++)
    {
        int y=q[x][i];
        if(y==fa||y==lim) continue;
        dfs1(y,x,lim);
        dep[x]=max(dep[x],dep[y]+1);
    }
    siz[dep[x]]++;
    if(x==fa)
    {
        int sum=0;u[0]=dep[x];
        for(int i=1;i<=k;i++) u[i]=INT_MAX;
        for(int i=dep[x];i>=0;i--) 
        {
            sum+=siz[i];
            if(sum>k) break;
            u[sum]=i;
        }
        for(int i=1;i<k;i++) 
        {
            u[i]=min(u[i-1],u[i]);
            ans=min(ans,max(u[i],dp[lim][k-i]));
        }
    }
}
void clear()
{
    for(int i=0;i<=n;i++) q[i].clear(),dep[i]=0,siz[i]=0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;ans=n;k=min(n,k);
        for(int i=1;i<n;i++)
        {
            int x,y;cin>>x>>y;
            q[x].push_back(y);
            q[y].push_back(x);
        }dfs(1,0);
        for(int x=1;x<=n;x++) siz[x]=0;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
            {
                if(i==j)
                {
                    int now=max(dp[i][k],dij(i,i));
                    ans=min(ans,now);
                    continue;
                }
                int u=i;
                while((u!=j)&&u) u=f[u];
                if(u==j) continue; 
                for(int x=0;x<=n;x++) siz[x]=0;
                dfs1(i,i,j);
            }
        cout<<ans<<"\n";clear();
    }
}