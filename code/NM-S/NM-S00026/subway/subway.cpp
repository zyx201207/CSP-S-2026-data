#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;//n:line.m:station
ll sta[505];
vector<pair<ll,ll>>g[450005];
ll dis[450005],vis[450005];
void dij(ll kk)
{
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[kk]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,kk});
    while(!pq.empty())
    {
        //cout<<111<<endl;
        ll x=pq.top().first;
        ll y=pq.top().second;
        pq.pop();
        if(vis[y])
        {
            continue;
        }
        vis[y]=1;
        for(auto &edge:g[y])
        {
            ll pp=edge.first;
            ll qq=edge.second;
            //cout<<pp<<endl;
            if(qq+dis[y]<dis[pp])
            {
                dis[pp]=qq+dis[y];
                pq.push({dis[pp],pp});
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        ll k;
        cin>>k;
        g[i].push_back({i+m,k});
        g[i+m].push_back({i,k});
    }
    for(int i=1;i<=n;i++)
    {
        ll k,last_sta;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            ll k1,k2;
            cin>>k1>>k2;
            sta[k1]++;
            g[k1+m].push_back({sta[k1]+m*2+(d*(k1-1)),k2});//?
            g[sta[k1]+m*2+(d*(k1-1))].push_back({k1+m,k2});//?
            if(j>1)
            {
                g[sta[k1]+m*2+(d*(k1-1))].push_back({last_sta,0});//?
                g[last_sta].push_back({sta[k1]+m*2+(d*(k1-1)),0});//?
            }
            last_sta=sta[k1]+m*2+(d*(k1-1));//?
        }
    }



    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        dij(l);
        cout<<dis[r]<<endl;
    }

    return 0;
}
