#include<iostream>
#include<cstdio>
#include<climits>
#include<vector>
#include<utility>
using namespace std;

long long c,n,m,d,q,b[500005];
bool vis[500005];
vector<pair<int,int> > g[600005];
long long minn=LLONG_MAX;
void dfs(int s,int e,long long sum)
{
    if(s==e)
    {
        minn=min(minn,sum);
        return ;
    }
    vis[s]=1;
    for(auto &p:g[s])
    {
        int v=p.first,w=p.second;
        if(!vis[v]) dfs(v,e,sum+w);
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)   cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int v,w;
            cin>>v>>w;
            g[v].push_back({m+i,w});
            g[m+i].push_back({v,w});
        }
    }
    while(q--)
    {
        for(int i=1;i<=m+n;i++)   vis[i]=0;
        int x,y;
        cin>>x>>y;
        minn=LLONG_MAX;
        dfs(x,y,0);
        cout<<b[x]+b[y]+minn<<'\n';
    }
    return 0;
}
