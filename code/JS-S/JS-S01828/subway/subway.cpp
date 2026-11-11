#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int M=5e5+5;
const int N=505;
int c,n,m,d,que;
int inout[M];
struct node
{
    int x;
    int ti;
};
struct graph
{
    int v;
    int w;
};
vector<node>sta[N];
vector<graph>g[M];
int dis[M];
bool vis[M];
priority_queue<pii,vector<pii >,greater<pii > >q;
inline void dj(int s)
{
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    dis[s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u])
            continue;
        vis[u]=true;
        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i].v;
            int w=g[u][i].w;
            if(dis[v]>=dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>que;
    for(int i=1; i<=m; i++)
        cin>>inout[i];
    for(int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        for(int j=1; j<=k; j++)
        {
            int a,t;
            cin>>a>>t;
            sta[i].push_back({a,t});
            for(int o=0; o<sta[i].size(); o++)
            {
                int v=sta[i][o].x;
                int w=sta[i][o].ti+t;
                g[a].push_back({v,w});
                g[v].push_back({a,w});
            }
        }
    }
    while(que--)
    {
        int s,e;
        cin>>s>>e;
        dj(s);
        cout<<dis[e]+inout[s]+inout[e]<<endl;
    }
    return 0;
}
