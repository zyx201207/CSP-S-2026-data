#include<bits/stdc++.h>
#define int long long
#define ll unsigned long long
#define off ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pi pair<int,int>
#define pii pair<int,pair<int,int> >
#define fi first
#define se second
using namespace std;
const int N=500005;
const int M=505;
const int Q=100005;
int c,n,m,d,q,w[N],dis[N+M],ans[Q],vis[N+M];
vector<pi >a[N+M];
vector<int>qs[M];
unordered_map<int,int>mp[N];
pi in[Q];
priority_queue<pi,vector<pi >,greater<pi > >pq;
void dij(int s)//(m+n)lg(m+n)
{
    for(int i=1;i<=n+m;i++)
    {
        dis[i]=1000000000000000000;
        vis[i]=0;
    }
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int u=pq.top().se;
        pq.pop();
        if(vis[u])
        {
            continue;
        }
        vis[u]=1;
        for(pi p:a[u])
        {
            int v=p.fi,w=p.se;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}
signed main()
{
    off;
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
            a[i+m].push_back({x,y});
            a[x].push_back({i+m,y});
            mp[x][i]=y;
        }
    }
    //For every subway, do dij
    /*if(c<=15)//500*20000
    {
        solve1();
    }
    else if(20<=c<=21)//2*500000
    {
        solve2();
    }*/
    //However, the memory is not enough to make it.
    //Noticing that d is below than 20.
    //We can save ins.
    //Then only solve what we need.
    //After solving each subway's dij, make a difference to what need this subway.
    for(int i=1;i<=q;i++)
    {
        cin>>in[i].fi>>in[i].se;
        for(pi p:a[in[i].fi])
        {
            qs[p.fi-m].push_back(i);
        }
        ans[i]=1000000000000000000;
    }
    for(int i=m+1;i<=n+m;i++)
    {
        dij(i);
        for(int x:qs[i-m])
        {
            int u=in[x].fi,v=in[x].se;
            ans[x]=min(ans[x],dis[v]+mp[u][i-m]);
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout<<ans[i]+w[in[i].fi]+w[in[i].se]<<'\n';
    }
    return 0;
}
//file memory long long
