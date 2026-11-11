#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM=5e5+10;
const int MAXK=5e5+10;
const int MAXN=500+10;
int c,n,m,d,q;
int AA,TT;
int w[MAXM],dis[MAXN][MAXN];
int k[MAXN];
vector < pair <int,int> > station[MAXM];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>AA>>TT;
            station[AA].push_back({i,TT});
        }
    }
    for(int i=1;i<=m;i++)
    {
        int dd=station[i].size();
        for(int j=0;j<dd;j++)
        {
            for(int k=0;k<dd;k++)
            {
                int u=station[i][j].first;
                int v=station[i][k].first;
                if(u==v) dis[u][v]=0;
                else dis[u][v]=min(dis[u][v],station[i][j].second+station[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int ans=LLONG_MAX;
        for(int i=0;i<station[u].size();i++)
        {
            for(int j=0;j<station[v].size();j++)
            {
                ans=min(ans,dis[station[u][i].first][station[v][j].first]+station[u][i].second+station[v][j].second);
                //cerr<<"LINE"<<station[u][i].first<<" To LINE"<<station[v][j].first<<" "<<dis[station[u][i].first][station[v][j].first]<<" "<<station[u][i].second<<" "<<station[v][j].second<<'\n';
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}
//g++ -o test -O2 -std=c++14 -static subway.cpp
//the essence is the time cost of the line to the other line
//enter depature station + enter depature line + line to line + exit arrvial line + exit arrvial station
//O(1)                     O(20)                                O(20)               O(1)
//                                               O(n^3)
//finished at 15:32
