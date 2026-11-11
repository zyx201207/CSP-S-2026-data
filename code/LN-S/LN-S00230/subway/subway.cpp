#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=510,M=5e5+10;
const int inf=1e15+243;
//   N road    M station
int c,n,m,d,T;
int w[M];
int k[N];
vector<int> road[N];//road {point }
int t[N][M];
vector<int> cross[M];//which road pass the station
map<int,int> mp[M];//mp[root_point][goal_point]
int ans=0;
int dist[M];
priority_queue<pii,vector<pii >,greater<pii > > q;
bool vis[M];
inline void solve(int root,int goal)
{
    //clear
    for(int i=1;i<=m;i++)dist[i]=inf;
    for(int i=1;i<=m;i++)vis[i]=false;
    dist[root]=w[root];
    pii point;
    point.first=dist[root],point.second=root;
    while(!q.empty())q.pop();
    //q.push({dist[root],dist});
    q.push(point);
    //calc
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(vis[x])continue;
        vis[x]=true;
        //cout<<x<<" "<<dist[x]<<'\n';////check
        for(auto i:cross[x])//for road
        {
            for(auto j:road[i])//for station
            {
                int y=j;
                if(x==y)continue;
                if(dist[y]>dist[x]+t[i][x]+t[i][y])
                {
                    dist[y]=dist[x]+t[i][x]+t[i][y];
                    q.push({dist[y],y});
                }
            }
        }
    }
    for(int i=1;i<=m;i++)if(i!=root)dist[i]+=w[i];//*important
    ans=dist[goal];
    //remember
    for(int i=1;i<=m;i++)mp[root][i]=dist[i];
    return ;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>T;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int a,tt;
            cin>>a>>tt;
            road[i].push_back(a);
            t[i][a]=tt;
            cross[a].push_back(i);
        }
    }
    while(T--)
    {
        int x,y;
        cin>>x>>y;
        if(mp[x][y]!=0)
        {
            cout<<mp[x][y]<<'\n';
            continue;
        }else if(mp[y][x]!=0)
        {
            cout<<mp[y][x]<<'\n';
            continue;
        }
        solve(x,y);
        cout<<ans<<'\n';
    }
    return 0;
}
