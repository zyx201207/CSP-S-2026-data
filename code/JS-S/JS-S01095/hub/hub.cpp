#include<bits/stdc++.h>
using namespace std;
const int N=110;
int c,t,n,m,d[N],fa[N],f[N];
vector<int> g[N];
int fd(int x)
{
    if(x==f[x]) return x;
    return f[x]=fd(f[x]);
}
int add(int x,int y)
{
    x=fd(x);
    y=fd(y);
    if(x==y) return 0;
    f[y]=x;
    return 1;
}
void dfs(int x,int p)
{
    d[x]=d[p]+1;
    fa[x]=p;
    for(auto y:g[x])
    {
        if(y==p) continue;
        dfs(y,x);
    }
}
int lca(int x,int y)
{
    if(d[x]<d[y]) swap(x,y);
    while(d[x]>d[y]) x=fa[x];
    while(x!=y)
    {
        x=fa[x];
        y=fa[y];
    }
    return x;
}
int dist(int x,int y)
{
    int z=lca(x,y);
    return d[x]+d[y]-d[z]-d[z];
}
int check(int x)
{
    for(int i=1;i<=n;i++) f[i]=i;
    int cnt=m;
    for(int i=1;i<=n;i++)
    {
        if(((x>>(i-1))&1)==0) continue;
        for(int j:g[i])
        {
            if(((x>>(j-1))&1)==0) continue;
            cnt-=add(i,j);
        }
    }
    if(cnt>=3) return 1e9;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if((x>>(i-1))&1) continue;
        int dis=1e9;
        for(int j=1;j<=n;j++)
        {
            if(((x>>(j-1))&1)==0) continue;
            dis=min(dis,dist(i,j));
        }
        ans=max(ans,dis);
    }
    return ans;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1,0);
        int ans=1e9;
        for(int i=0;i<(1<<n);i++)
        {
            int cnt=0;
            for(int j=1;j<=n;j++)
            {
                if((i>>(j-1))&1)
                {
                    cnt++;
                }
            }
            if(cnt!=m) continue;
            ans=min(ans,check(i));
        }
        printf("%d\n",ans);
    }
    return 0;
}
