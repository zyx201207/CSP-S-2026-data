#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>v[1000005];
bool vis[1000005],viss[1000005];
int c,t,n,k,ans=1e18,d[1000005];
void dfs1(int x)
{
    viss[x]=1;
    for(int y:v[x])
    {
        if(viss[y]||!vis[y]) continue;
        dfs1(y);
    }
}
void dfs(int x,int cnt)
{
    if(cnt>k||cnt+n-x+1<k) return;
    if(x==n+1)
    {
        if(cnt!=k) return;
        for(int i=1;i<=n;i++) viss[i]=0;
        int tt=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]&&!viss[i])
            {
                tt++;
                if(tt>2) break;
                dfs1(i);
            }
        }
        if(tt>2) return;
        int ma=0;
        for(int i=1;i<=n;i++) viss[i]=0,d[i]=1e18;
        queue<int>q;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                q.push(i);
                d[i]=0;
                viss[i]=1;
            }
        }
        while(!q.empty())
        {
            int xx=q.front();
            q.pop();
            for(int y:v[xx])
            {
                if(viss[y]) continue;
                viss[y]=1;
                d[y]=d[xx]+1;
                q.push(y);
            }
        }
        for(int i=1;i<=n;i++) if(!vis[i]) ma=max(ma,d[i]);
        ans=min(ans,ma);
        return;
    }
    vis[x]=1;
    dfs(x+1,cnt+1);
    vis[x]=0;
    dfs(x+1,cnt);
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        ans=1e18;
        dfs(1,0);
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++) v[i].clear();
    }
    return 0;
}
