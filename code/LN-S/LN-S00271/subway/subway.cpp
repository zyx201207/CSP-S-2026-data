#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
vector<pair<int,ll> > edge[500505];
int ll w[500005];
void dfs(int cur,int y,ll dis,ll &ans,int visited[500505])
{
    if(cur==y)
    {
        ans=min(dis,ans);
        return;
    }
    for(pair<int,ll> i:edge[cur])
    {
        int v=i.first;
        ll d=i.second;
        if(d+dis>=ans || visited[cur])
            return;
        visited[cur]=1;
        dfs(v,y,dis+d,ans,visited);
        visited[cur]=0;
    }
}
int main()
{

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a;
            ll t;
            cin>>a>>t;
            edge[m+i].push_back({a,t});
            edge[a].push_back({m+i,t});
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        int visited[500505]={0};
        dfs(x,y,0,ans,visited);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
