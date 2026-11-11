#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2010;
ll c,n,m,d,q,a[N],dis[N][N];
vector<pair<ll,ll> > g[N];
void djstl(ll s)
{
    for(ll i=1;i<=m+n;i++) dis[s][i]=1e18;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
    dis[s][s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        ll x=q.top().second;
        q.pop();
        for(auto p:g[x])
        {
            ll y=p.first;
            ll z=p.second;
            if(dis[s][y]>dis[s][x]+z)
            {
                dis[s][y]=dis[s][x]+z;
                q.push({dis[s][y],y});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(ll i=1;i<=m;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++)
    {
        ll x;
        scanf("%lld",&x);
        for(ll j=1;j<=x;j++)
        {
            ll y,z;
            scanf("%lld%lld",&y,&z);
            g[y].push_back({i+m,z});
            g[i+m].push_back({y,z});
        }
    }
    for(ll i=1;i<=m;i++) djstl(i);
    while(q--)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",dis[x][y]+a[x]+a[y]);
    }
    return 0;
}
