#include<bits/stdc++.h>
using namespace std;
const long long MXW = 1000000000000000000;
int c,n,m,d,Q,vis[501005];
long long dis[501005],W[500005],tim1[500005],tim2[500005],mn = MXW,ans = MXW;
struct edge
{
    int v;
    long long w;
};
vector<edge> T[501005];
struct cmp
{
    bool operator() (edge x,edge y)
    {
        return x.w > y.w;
    }
};
priority_queue<edge,vector<edge>,cmp> q;
void dijkstla(int x,int y)
{
    for(int i = 1;i <= m + n;i++) dis[i] = MXW;
    for(int i = 1;i <= m + n;i++) vis[i] = 0;
    dis[x] = 0;
    q.push((edge){x,0});
    while(!q.empty())
    {
        int u = q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(edge e:T[u])
        {
            int v = e.v;
            long long w = e.w;
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                q.push((edge){v,dis[v]});
            }
        }
    }
    cout<<(dis[y] + W[x] + W[y])<<'\n';
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i = 1;i <= m;i++) cin>>W[i];
    if(c == 20 || c == 21)
    {
        int k,a;
        long long t;
        cin>>k;
        for(int i = 1;i <= k;i++)
        {
            cin>>a>>t;
            tim1[a] = t;
        }
        cin>>k;
        for(int i = 1;i <= k;i++)
        {
            cin>>a>>t;
            tim2[a] = t;
        }
        for(int i = 1;i <= m;i++) if(tim1[i] && tim2[i]) mn = min(mn,tim1[i] + tim2[i]);
        while(Q--)
        {
            int x,y;
            cin>>x>>y;
            ans = MXW;
            if(tim1[x] && tim2[y] && mn != MXW) ans = min(ans,tim1[x] + mn + tim2[y]);
            if(tim1[y] && tim2[x] && mn != MXW) ans = min(ans,tim1[y] + mn + tim2[x]);
            if(tim1[x] && tim1[y]) ans = min(ans,tim1[x] + tim1[y]);
            if(tim2[x] && tim2[y]) ans = min(ans,tim2[x] + tim2[y]);
            cout<<(ans + W[x] + W[y])<<'\n';
        }
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        int k,a;
        long long t;
        cin>>k;
        for(int j = 1;j <= k;j++)
        {
            cin>>a>>t;
            T[a].push_back((edge){m + i,t});
            T[m + i].push_back((edge){a,t});
        }
    }
    while(Q--)
    {
        int x,y;
        cin>>x>>y;
        dijkstla(x,y);
    }
    return 0;
}
