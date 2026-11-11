#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N=5010;
int n,dis[N];
bool vis[N];
i64 cnt[N],d,x[N];
vector<int> g[N];
i64 bfs(int x)
{
    i64 res=0;
    queue<int> q;
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    memset(dis,0,sizeof(dis));
    vis[x]=1,dis[x]=0,cnt[x]=1;
    q.push(x);
    while(q.size())
    {
        int u=q.front();q.pop();
        for(auto &v:g[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                dis[v]=dis[u]+1;
                cnt[v]=cnt[u];
                q.push(v);
            }
            else if(dis[u]+1==dis[v]) cnt[v]+=cnt[u];
        }
    }
    for(int i=x+1;i<=n;i++)
        if(vis[i]&&cnt[i]==2)
            res++;
    return res;
}
void solution()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    i64 ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(abs(x[i]-x[j])<=d)
                g[i].push_back(j);
    for(int i=1;i<=n;i++) ans+=bfs(i);
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++) vector<int>{}.swap(g[i]);
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
        solution();
    return 0;
}
