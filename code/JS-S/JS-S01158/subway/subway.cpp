#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a;i<b;i++)
#define int long long
#define pq priority_queue
#define pb push_back
int c,n,m,d,q;
vector<int> w;
vector<pair<int,int> > nodes[555555];
int djs(int a,int b)
{
    priority_queue<pair<int,pair<int,int> > > pq;

    int vis[555555];
    int dis[555555];
    fore(i,0,m+n)
    {
        vis[i]=-1;
        dis[i]=0x3f;
    }


    fore(i,0,nodes[a].size())
    {
        pq.push({a,nodes[a][i]});
    }

    while(!pq.empty())
    {
        int now=pq.top().first;
        int to=pq.top().second.second;
        int w=pq.top().second.first;
        vis[to]=0;
        if(dis[now]+w<dis[to])
        {
            dis[to]=dis[now]+w;
            fore(i,0,nodes[to].size())
            {
                pq.push({to,nodes[to][i]});
            }
        }

    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    fore(i,0,m)
    {
        int x;
        cin>>x;
        w.pb(x);
    }
    fore(i,0,n)
    {
        int k;
        cin>>k;
        vector<int> xs,ys;
        fore(j,0,k)
        {
            int x,y;
            cin>>x>>y;
            nodes[n+i].pb({y,x});
            nodes[x].pb({y,n+i});
        }
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        int ans=0;
        ans+=w[a];
        ans+=w[b];
        ans+=djs(a,b);
        cout<<ans<<"\n";
    }
    return 0;
}
