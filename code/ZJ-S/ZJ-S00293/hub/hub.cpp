#include<bits/stdc++.h>

using namespace std;

#define int long long
#define uint unsigned long long
#define inf (LLONG_MAX>>1)

constexpr int maxn=1e6+10;

int c,T;

int n,k;
vector<int> gra[maxn];
int dep[maxn];

void dfs1(int u,int p)
{
    dep[u]=dep[p]+1;
    for(int v:gra[u])
    {
        if(v==p) continue;
        dfs1(v,u);
    }
}

void solve()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i) gra[i].clear();
    for(int i=1;i<n;++i)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        gra[u].emplace_back(v);
        gra[v].emplace_back(u);
    }
    int m=n>>1;
    int ans=(m-k)>>1;
    ans=((ans+1)>>1)+1;
    printf("%lld\n",ans);
}

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--)
    {
        solve();
    }
    return 0;
}