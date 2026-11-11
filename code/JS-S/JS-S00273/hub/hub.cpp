#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
bool vis[1000005];
vector<int>e[1000005];
int s[1000005];
bool f(int x)
{
    for(int i=1;i<=k;i++)
    {
        if(x==s[k])return 1;
    }
    return 0;
}
int dfs3(int u)
{
    vis[u]=1;
    if(f(u))return 0;
    int dis=0x3f3f3f3f;
    for(int v:e[u])
    {
        if(!vis[v])
        {
            dis=min(dis,1+dfs3(v));
        }
    }
    return dis;
}
void dfs2(int u)
{
    vis[u]=1;
    for(int v:e[u])
    {
        if(!vis[v]&&f(v))
        {
            dfs2(v);
        }
    }
}
void dfs(int x,int p)
{
    if(x>k)
    {
        int cnt=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(!vis[s[i]])
            {
                dfs2(s[i]);
                cnt++;
            }
        }
        if(cnt<=2)
        {
            int mn=-0x3f3f3f3f;
            for(int i=1;i<=n;i++)
            {
                if(!f(i))
                {
                    memset(vis,0,sizeof(vis));
                    mn=max(mn,dfs3(i));
                }
            }
            ans=min(ans,mn);
        }
        return ;
    }
    for(int i=p+1;i<=n-(k-x);i++)
    {
        s[x]=i;
        dfs(x+1,i);
        s[x]=0;
    }
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        ans=0x3f3f3f3f;
        scanf("%lld%lld",&n,&k);
        for(int i=1,u,v;i<n;i++)
        {
            scanf("%lld%lld",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(n==k)puts("0");
        else if(n>=k-2)puts("1");
        else
        {
            dfs(1,0);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
