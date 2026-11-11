#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10004;
int c,t,n,k;
vector<int>g[10004];
int ju[10004][21];
int dep[10004],cnt;
bool ksm[N],vis[N];
int op[N],ans;
void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    ju[x][0]=fa;
    for(int i=1;i<=20;++i)
    {
        ju[x][i]=ju[ju[x][i-1]][i-1];
    }
    for(int u:g[x])
    {
        if(u==fa)
            continue;
        dfs(u,x);
    }
}
int lca(int a,int b)
{
    if(dep[a]<dep[b])
        swap(a,b);
    for(int i=20;i>=0;--i)
    {
        if(dep[ju[a][i]]>=dep[b])
            a=ju[a][i];
    }
    if(a==b)
        return a;
    for(int i=20;i>=0;--i)
    {
        if(ju[a][i]!=ju[b][i])
            a=ju[a][i],b=ju[b][i];
    }
    return ju[a][0];
}
void dfc(int x)
{
    vis[x]=1;
    for(int u:g[x])
    {
        if(vis[u])
        continue;
        if(ksm[u])
            dfc(u);
    }
}
int sol()
{
   int po=0;
   bool flag=1;
  for(int i=1;i<=n;++i)
  vis[i]=0,ksm[i]=0;
  for(int i=1;i<=cnt;++i)
    ksm[op[i]]=1;
   for(int i=1;i<=cnt;++i)
   {
       if(!vis[op[i]])
       {
           dfc(i);
           po++;
       }
       if(po>2)
       {
           flag=0;
           break;
       }
   }
   if(!flag)
    return 0x5f5f5f5f5;
    int dis=0;
   for(int i=1;i<=n;++i)
    {
        if(ksm[i])
        continue;
        int popoo=0x5f55f5f;
        for(int j=1;j<=cnt;++j)
        {
            int a=i,b=op[j];
            int lc=lca(a,b);
            popoo=min(popoo,dep[a]-dep[lc]+dep[b]-dep[lc]);
        }
        dis=max(popoo,dis);
    }
  for(int i=1;i<=cnt;++i)
    ksm[op[i]]=0;
    return dis;
}
void dfsk(int x,int o)
{
    if(o==0)
    {
        ans=min(ans,sol());
        return;
    }
    for(int i=x+1;i<=n-k+1;++i)
    {
        op[++cnt]=i;
        dfsk(i,o-1);
        cnt--;
    }
}
signed main()
{
    freopen("hub1.in","r",stdin);
    //freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        cnt=0;
        ans=0x5f5f5f5f5f;
        for(int i=1;i<=n;++i)
        {
            ksm[i]=vis[i]=0;
            dep[i]=0;
            op[i]=0;
            g[i].clear();
        }
        for(int i=1;i<n;++i)
        {
            int u,v;
            scanf("%lld%lld",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        dfsk(0,k);
        printf("%lld\n",ans);
    }
    return 0;
}
