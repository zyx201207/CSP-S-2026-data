#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010;
ll c,t,n,m,a[N],dis[N],cnt[N];
vector<ll> g[N];
ll bfs(ll s)
{
    for(ll i=1;i<=n;i++) dis[i]=1e18;
    for(ll i=1;i<=n;i++) cnt[i]=0;
    queue<ll> q;
    dis[s]=0;
    cnt[s]=1;
    q.push(s);
    while(!q.empty())
    {
        ll x=q.front();
        q.pop();
        for(auto y:g[x])
        {
            if(dis[y]>dis[x]+1)
            {
                dis[y]=dis[x]+1;
                cnt[y]=cnt[x];
                q.push(y);
            }
            else if(dis[y]==dis[x]+1) cnt[y]+=cnt[x];
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(s==i) continue;
        if(cnt[i]==2) ans++;
    }
    return ans;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(ll i=1;i<=n;i++) g[i].clear();
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                if(abs(a[i]-a[j])<=m)
                {
                    g[i].push_back(j);
                }
            }
        }
        ll ans=0;
        for(ll i=1;i<=n;i++) ans+=bfs(i);
        printf("%lld\n",ans/2);
    }
    return 0;
}
