#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
int n,k;
vector<int> g[N];
int ord[N];
int ans=0;
int vis[N];
int maxn=0;
void dfs2(int t) //O(n)
{
    vis[t]=1;
    for(int i:g[t])
    {
        if(vis[i]||ord[i]==0) continue;
        vis[i]=1;
        dfs2(i);
    }
}
bool check()//O(n^2)
{
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=ord[i]; //O(n)
    if(cnt!=k) return false;
    cnt=0;
    int t=0;
    memset(vis,0,sizeof(t)*maxn+10000);
    for(int i=1;i<=n;i++)
    {
        if(ord[i]&&vis[i]==0)
        {
            cnt++;
            dfs2(i);
        }
    }
    if(cnt>2) return false;
    return true;
}
int dis(int u)
{
    //cout<<114514;
    if(ord[u]) return 0;
    int t=1e18;
    for(int i:g[u])
    {
        if(vis[i]) continue;
        vis[i]=1;
        //cout<<dis(i)<<' ' <<u<<'\n';
        t=min(t,dis(i));
    }
    return t+1;
}
int calc()
{
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        int t=0;
        memset(vis,0,sizeof(t)*maxn+10000);
        //cout<<dis(i);
        vis[i]=1;
        ret=max(ret,dis(i));
    }
    return ret;
}
void dfs(int t)//O(2^n * n^2)
{
    if(t==n+1)
    {
        if(check())
        {
            //cout<<114514;
            //cout<<calc()<<'\n';
            ans=min(ans,calc());
        }
        return ;
    }
    ord[t]=1;
    dfs(t+1);
    ord[t]=0;
    dfs(t+1);
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        ans=1e18;
        cin>>n>>k;
        maxn=max(maxn,n);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
