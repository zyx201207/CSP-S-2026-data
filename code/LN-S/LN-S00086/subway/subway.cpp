#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define frt first
#define scd second
const int maxn = 5e5+10;
const ll INF = 1e18;

ll c,n,m,d,q,maxinx=1;
vector<pair<ll,ll>> nxt[maxn];
ll dis[maxn];
ll inx=1;

void add(ll u,ll v,ll dist)
{
    nxt[u].push_back({v,dist});
    nxt[v].push_back({u,dist});
}

void Dijkstra(ll root,ll dist0)
{
    for(int i=1;i<=maxinx;i++) dis[i]=INF;
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
            if(dis[to]>dis[start]+dist)
            {
                dis[to]=dis[start]+dist;
                pq.push({dis[to],to});
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    inx=m+1;
    for(int i=1;i<=m;i++)
    {
        ll dist;
        cin >> dist;
        add(i,inx,dist);
        inx++;
    }
    inx--;
    for(int i=1;i<=n;i++)
    {
        ll k;
        cin >> k;
        ll u[k+5]={0};
        for(int j=1;j<=k;j++)
        {
            ll dist;
            cin >> u[j] >> dist;
            add(u[j]+(i+1)*m,u[j]+m,dist);
            inx++;
        }
        for(int j=1;j<k;j++)
        {
            add(u[j]+(i+1)*m,u[j+1]+(i+1)*m,0);
            maxinx=max(maxinx,u[j+1]+(i+1)*m);
        }
    }

    /*for(int i=1;i<=25;i++)
    {
        for(auto it : nxt[i])
        {
            ll to=it.frt,dist=it.scd;
            cout << i << "to" << to << ",dist:" << dist << "\n";
        }
    }*/


    while(q--)
    {
        ll st,en;
        cin >> st >> en;
        Dijkstra(st,0);
        cout << dis[en] << "\n";
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
