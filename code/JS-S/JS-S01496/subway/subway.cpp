#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll be,en;
ll c,n,m,d;
ll vi[N];
bool vis[502];
ll way[N];
ll ans[N];
struct node
{
    ll t;
    ll w;
};
vector<node>g[502];
vector<node>g2[N];
vector<node>que[N];
void dfs(ll x,ll num)
{
    if(vi[x]<=num)
    {
        return ;
    }
    vi[x]=num;
    for(int i=0;i<g2[x].size();i++)
    {
        node u=g2[x][i];
        if(vis[u.t])continue;
        vis[u.t]=true;
        for(node v:g[u.t])
        {
            if(v.t==x)continue;
            dfs(v.t,num+u.w+v.w);
        }
        vis[u.t]=false;
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll q;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&way[i]);
    }
    for(int i=1;i<=n;i++)
    {
        ll k;
        scanf("%lld",&k);
        for(int j=1;j<=k;j++)
        {
            ll x,w;
            scanf("%lld%lld",&x,&w);
            g[i].push_back({x,w});
            g2[x].push_back({i,w});
        }
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%lld%lld",&be,&en);
        que[en].push_back({i,be});
    }
    for(int i=1;i<=m;i++)
    {
        if(que[i].size()>0)
        {
            memset(vi,0x3f,sizeof(vi));
            dfs(i,0);
            for(node v:que[i])
            {
                ans[v.t]=vi[v.w]+way[i]+way[v.w];
            }
        }
    }
    for(int i=1;i<=q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}
