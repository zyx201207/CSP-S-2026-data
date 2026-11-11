#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const ll N=5e6+5;
ll c,n,m,d,q;
vector<pii> vt[N];//对于每一站：i是地铁口，n+i是站厅,(d+1)n+i是d线站台；
ll dis[N],a[N],t[N];
bool vis[N];

void dij(ll s)
{
    for(int i=1; i<=(d+1)*(m+1); i++)
    {
        dis[i]=1e18;
        vis[i]=0;
    }
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        ll x=pq.top().second;
        pq.pop();
        if(vis[x])
            continue;
        vis[x]=1;
        for(int i=0; i<vt[x].size(); i++)
        {
            ll ed=vt[x][i].first,val=vt[x][i].second;
            if(dis[ed]>dis[x]+val)
            {
                dis[ed]=dis[x]+val;
                if(!vis[ed])
                {
                    pq.push({dis[ed],ed});
                }
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1,w; i<=m; i++)//对于每一站：i是地铁口，n+i是站厅,(d+1)n+i是d线站台；
    {
        cin>>w;
        vt[i].push_back({m+i,w});
        vt[m+i].push_back({i,w});
    }
    for(int i=1,k; i<=n; i++)
    {
        cin>>k;
        for(int j=1; j<=k; j++)
        {
            cin>>a[j]>>t[j];

        }
        for(int j=1; j<=k; j++)
        {
            vt[m+a[j]].push_back({(i+1)*m+a[j],t[j]});
            vt[(i+1)*m+a[j]].push_back({m+a[j],t[j]});
        }
        for(int j=1; j<k; j++)
        {
            vt[(i+1)*m+a[j]].push_back({(i+1)*m+a[j+1],0});
            vt[(i+1)*m+a[j+1]].push_back({(i+1)*m+a[j],0});
        }
    }
    for(int i=1,x,y; i<=q; i++)
    {
        cin>>x>>y;
        dij(x);
        cout<<dis[y]<<"\n";
    }
    return 0;
}