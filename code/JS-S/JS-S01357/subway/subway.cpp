#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const int N=505;
const int M=5e5+5;

ll c,n,m,d,q,now_at_line;
ll k,aft,tft,abk,tbk,x,y,id;
ll w[M],vis[M],ex_time[N][M];
bool vis[M];
vector<pair<ll,ll> >g[M];
priority_queue<pll,vector<pll>,greater<pll> >pq;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>k;
        cin>>aft>>tft;
        ex_time[i][aft]=tft;

        for(ll j=2;j<=k;j++)
        {
            cin>>abk>>tbk;
            ex_time[i][abk]=tbk;

            g[aft].push_back({abk,i});
            g[abk].push_back({aft,i});
            aft=abk,tft=tbk;
        }

    }

    while(q--)
    {
        for(ll i=1;i<=m;i++)
        {
            dis[i]=1e9;
            vis[i]=false;
        }
        cin>>x>>y;
        dis[x]=0;
        q.push({dis[x],x});

        for(ll i=1;i<=n;i++)
        {
            if(is_inline[i][x]==true)
            {
                now_at_line=i;

                while(!pq.empty())
                {
                    id=pq.top().second;

                    if(vis[id]==true)
                    {
                        continue;
                    }
                    vis[id]=true;

                    for(auto a:g[id])
                    {

                    }
                }
            }
        }


    }
    return 0;
}
