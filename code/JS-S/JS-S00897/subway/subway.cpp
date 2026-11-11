#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
long long dis[10005][10005];
vector<pair<int,int> > v[505],v2[500005];
queue<pair<int,long long> > qu;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int x,y;
            cin>>x>>y;
            v[i].push_back({x,y});
            v2[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;m++)
    {
        dis[i][i]=0;
        qu.push({i,w[i]});
        while(!qu.empty())
        {
            int loc=qu.front().first;
            long long va=qu.front().second;
            qu.pop();
            for(auto [thr,co]:v2[loc])
            {
                for(auto [stat,cost]:v[thr])
                {
                    if(stat!=loc)
                    {
                        dis[i][stat]=min(dis[i][stat],va+co+cost+w[stat]);
                        if(va+co+cost-dis[i][stat]<=100)
                            qu.push({stat,va+co+cost});
                    }
                }
            }
        }
    }
    while(q--)
    {
        int st,en;
        cin>>st>>en;
        cout<<dis[st][en]<<"\n";
    }
}
