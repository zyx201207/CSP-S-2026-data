#include <bits/stdc++.h>
#define ll long long
#define Inf (1e18+10)
using namespace std;
const int M=500+10;
const int N=5e5+10;
struct Node
{
    int u;
    ll dis;
    bool operator<(const Node &A) const { return dis<A.dis; }
};
int c,n,m,d,q;
ll T;
vector<int> g[N];
map<pair<int,int>,vector<int> > mp;
ll t[M][N];
ll w[N];
ll dis[N];
bool vis[M];
ll ans;
void dfs(int u,int ed,int hag,ll val)
{
    if(u==ed)
    {
        val+=t[hag][ed];
        ans=min(ans,val);
        return ;
    }
    if(vis[u]) return ;
    vis[u]=1;
    for(auto v:g[u])
    {
        for(auto nh:mp[{u,v}])
        {
            if(nh!=hag) val+=t[hag][u]+t[nh][u];
            dfs(v,ed,nh,val);
            if(nh!=hag) val-=t[hag][u]+t[nh][u];
        }
    }
    vis[u]=0;
    return ;
}
ll ont(int st,int ed)
{
    priority_queue<Node> pq;
    pq.push({st,0ll});
    dis[st]=0;
    while(!pq.empty())
    {
        auto tmp=pq.top();
        pq.pop();
        for(auto v:g[tmp.u])
        {
            for(auto nh:mp[{tmp.u,v}])
            {
                ll ndis=dis[tmp.u]+t[nh][tmp.u]+t[nh][v];
                if(ndis<dis[v])
                {
                    dis[v]=ndis;
                    pq.push({v,ndis});
                }
            }
        }
    }
    return dis[ed];
}
ll mh(int st,int ed)
{
    priority_queue<Node> pq;
    pq.push({st,0ll});
    dis[st]=0;
    while(!pq.empty())
    {
        auto tmp=pq.top();
        pq.pop();
        for(auto v:g[tmp.u])
        {
            for(auto nh:mp[{tmp.u,v}])
            {
                ll ndis=dis[tmp.u]+2*T;
                if(ndis<dis[v])
                {
                    dis[v]=ndis;
                    pq.push({v,ndis});
                }
            }
        }
    }
    return dis[ed];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        int lst=-1;
        for(int j=1;j<=k;++j)
        {
            int u;
            cin>>u;
            cin>>t[i][u];
            T=t[i][u];
            if(j!=1)
            {
                g[lst].push_back(u);
                mp[{lst,u}].push_back(i);
            }
            lst=u;
        }
    }
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        if(c<=6 || c>=20)
        {
            for(int i=1;i<=m;++i) vis[i]=0;
            ans=LLONG_MAX;
            dfs(u,v,0,0ll);
            ans+=w[u]+w[v];
            cout<<ans<<'\n';
        }
        else if(c<=11)
        {
            for(int i=1;i<=m;++i) dis[i]=Inf;
            cout<<ont(u,v)+w[u]+w[v]<<'\n';
        }
        else
        {
            for(int i=1;i<=m;++i) dis[i]=Inf;
            cout<<mh(u,v)+w[u]+w[v]<<'\n';
        }
    }
    return 0;
}
