#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define frt first
#define scd second
const int maxn = 5e5+10;
const int maxe = 2e6+10;
const ll INF = 1e18;

ll c,T,n,d,x[maxe];
vector<pair<ll,ll>> nxt[maxn];
ll dis[maxn];
ll cnt[maxn];

void add(ll u,ll v,ll dist)
{
    nxt[u].push_back({v,dist});
    nxt[v].push_back({u,dist});
}

void Dijkstra(ll root,ll dist0)
{
    for(int i=1;i<=n;i++) dis[i]=INF;
    for(int i=1;i<=n;i++) cnt[i]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    dis[root]=dist0;
    pq.push({dist0,root});

    while(!pq.empty())
    {
        pair<ll,ll> x=pq.top();pq.pop();
        ll d=x.frt,start=x.scd;
        if(d!=dis[start]) continue;

        for(auto it : nxt[start])
        {
            ll to=it.frt,dist=it.scd;
            if(dis[to]==dis[start]+dist&&dis[to]!=0) cnt[to]++;
            if(dis[to]>dis[start]+dist)
            {
                cnt[to]=1;
                dis[to]=dis[start]+dist;
                pq.push({dis[to],to});
            }
        }
    }
}



int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> T;
    while(T--)
    {
        cin >> n >> d;
        for(int i=1;i<=n;i++)
        {
            nxt[i].clear();
            cin >> x[i];
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(abs(x[i]-x[j])<=d)
                {
                    add(i,j,1);
                }
            }
        }
        ll ans=0;

        for(int i=1;i<=n;i++)
        {
            Dijkstra(i,0);

            for(int j=1;j<=n;j++)
            {
                //cout << dis[i] << " " <<  cnt[i] << "\n";
                if(cnt[j]==2) ans++;
            }
            //cout << "\n";

        }
        //cout <<"\nans!!!!" <<  ans/2 << "\n";
        cout << ans/2 << "\n";

    }

    return 0;
}
/*
2023/8/23-2026/10/31
Aetherius AFO
cout << "Bye World!";
Q.E.D
return 0;
*/
