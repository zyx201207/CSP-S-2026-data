#include<bits/stdc++.h>
using namespace std;
const int N=12,INF=1e9;
int n,k,ans,dis[N],vis[N];
bool col[N];
vector<int> t[N];
void flood(int u)
{
    for(auto v:t[u])
        if(!vis[v]&&col[v])
            vis[v]=1,flood(v);
}
int check()
{
    memset(vis,0,sizeof(vis));
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(col[i]&&!vis[i])
        {
            res++;
            vis[i]=1;
            flood(i);
        }
    }
    return res;
}
int calc()
{
    int res=0;
    if(check()>2) return INF;
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(col[i]) vis[i]=1,q.push(i);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        res=max(res,dis[u]);
        for(auto v:t[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return res;
}
void dfs(int pos,int cnt)
{
    if(cnt==k) return ans=min(ans,calc()),void();
    if(pos==n+1) return ;
    col[pos]=1;
    dfs(pos+1,cnt+1);
    col[pos]=0;
    dfs(pos+1,cnt);
}
void solution()
{
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    ans=INF;
    memset(col,0,sizeof(col));
    dfs(1,0);
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++) vector<int>{}.swap(t[i]);
    return ;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
        solution();
    return 0;
}
