#include<bits/stdc++.h>
#define pli pair<ll,int> 
using namespace std;
typedef long long ll;
int c,n,m,d,q;
vector<pair<ll,int> > e[1005];
ll w[1005],k2[405];
ll dis[1005][1005];
pair<int,int> a[405][405];
void dij(int st)
{
    int N=(n+1)*m;
    priority_queue<pli,vector<pli>,greater<pli> > hq;
    dis[st][st]=0;
    hq.push({0,st});
    while(!hq.empty())
    {
        int u=hq.top().second;
        hq.pop();
        for(auto i:e[u])
        {
            int v=i.second;
            ll w=i.first;
            if(dis[st][u]+w<dis[st][v])
            {
                dis[st][v]=dis[st][u]+w;
                hq.push({dis[st][v],v});
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
    cin>>c>>n>>m>>d>>q;
    if(n<=3&&m<=10)
    {
        for(int i=1;i<=1000;i++)
            for(int j=1;j<=1000;j++)
                dis[i][j]=1e18;
        for(int i=1;i<=m;i++)
            cin>>w[i];
        for(int i=1;i<=n;i++)
        {
            cin>>k2[i];
            int k=k2[i];
            int u1,w1,u2,w2;
            cin>>u1>>w1;
            e[u1+i*m].push_back({w1,u1});
            e[u1].push_back({w1,u1+i*m});
            for(int j=2;j<=k;j++)
            {
                cin>>u2>>w2;
                e[u2+i*m].push_back({0,u1+i*m});
                e[u1+i*m].push_back({0,u2+i*m});
                e[u2+i*m].push_back({w2,u2});
                e[u2].push_back({w2,u2+i*m});
                u1=u2;w1=w2;
            }
        }
        // for(int i=1;i<=m;i++)
        //     dij(i);
        // for(int i=1;i<=m;i++)
        // {
        //     for(int j=1;j<=m;j++)
        //         cout<<dis[i][j]<<" ";
        //     cout<<"\n";
        // }
        while(q--)
        {
            int x,y;
            ll ans;
            cin>>x>>y;
            if(dis[x][y]!=1e18) ans=dis[x][y]+w[x]+w[y];
            else
            {
                dij(x);
                ans=dis[x][y]+w[x]+w[y];
            }
            cout<<ans<<"\n";
        }    
    }
    else
    {
        
    }
    return 0;
}