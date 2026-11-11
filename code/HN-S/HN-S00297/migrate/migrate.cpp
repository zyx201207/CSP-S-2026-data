#include<bits/stdc++.h>
using int_64=long long;

constexpr int N=2e6;

int_64 x[N+5],bit[N+5],nxt[N+5],d;
int fa[N+5];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int n;

void add(int x,int_64 v){while(x<=n)bit[x]+=v,x+=-x&x;}
int_64 query(int x){int_64 ans=0;while(x){ans+=bit[x];x-=-x&x;}return ans;}
int_64 query(int l,int r){return query(r)-query(l-1);}

void dfs(int);
void modify(int l,int r)
{
    for(int i=l;i&&i<=r;fa[i]=i+1,i=find(i))dfs(i);
}

void dfs(int x)
{
    // std::cerr<<x<<'\n';
    if(fa[x]!=x||!x)return;
    int p=nxt[x];
    if(p==x)return;
    if(p==x+1)
    {
        // std::cerr<<"1#"<<x<<' '<<p<<' '<<nxt[p]<<'\n';
        modify(p,p);
        add(x,query(p,p));
    }
    if(p>=x+2)
    {
        int t1=nxt[p],t2=nxt[p-1],t3=nxt[p-2];
        // std::cerr<<"2#"<<x<<' '<<t1<<' '<<t2<<' '<<t3<<'\n';
        modify(t2+1,t1);
        add(x,t2-t3+query(t2+1,t1));
    }
}

void sol()
{
    std::cin>>n>>d;
    for(int i=1;i<=n;++i)std::cin>>x[i],bit[i]=0,fa[i]=i;
    for(int i=n,j=n;i;--i)
    {
        while(x[j]-x[i]>d)--j;
        nxt[i]=j;
    }
    // for(int i=1;i<=n;++i)std::cerr<<nxt[i]<<" \n"[i==n];

    modify(1,n);
    // for(int i=1;i<=n;++i)std::cerr<<query(i,i)<<" \n"[i==n];
    std::cout<<query(1,n)<<'\n';
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    freopen("migrate.log","w",stderr);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);

    int c,t;
    std::cin>>c>>t;
    while(t--)sol();
}