#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
inline int read()
{
    int c=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        c=(c<<1)+(c<<3)+ch-48;
        ch=getchar();
    }
    return w*c;
}
#define maxn 1111111
int n,k;
struct node{int v,w;};
vector<node>tree[maxn];
int fa[maxn][30];
int dep[maxn];
void init()
{
    memset(fa,0,sizeof(fa));
    memset(dep,0,sizeof(dep));
}
void dfs(int u,int p)
{
    dep[u]=dep[p]+1;
    fa[u][0]=p;
    for(int i=1;i<=30;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
    for(auto i:tree[u])
        if(i.v==p)continue;
        else dfs(i.v,u);
}
int LCA(int a,int b)
{
    if(dep[a]<dep[b])swap(a,b);
    for(int i=30;i>=0;i--)
        if(dep[fa[a][i]]>dep[b])a=fa[a][i];
    if(a==b)return a;
    for(int i=30;i>=0;i--)
        if(fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
    return a;
}
void Part1()
{
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)continue;
            else
            {
                int lca=LCA(i,j);
                ans=max(ans,dep[i]-dep[lca]+dep[j]-dep[lca]);
            }
    printf("%lld\n",ans);
}
void solve()
{
    init();
    n=read(),k=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        tree[u].push_back({v,1});
        tree[v].push_back({u,1});
    }
    if(k==1){Part1();return;}
    if(k==2){Part2();return;}
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c=read(),T=read();
    while(T--)solve();
    return 0;
}
