#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=514514;
int n,m,c,fw,q,w[N],d[514][514],vis[N],k[N],cnt[N];
vector<int>a[N],t[N];
vector<pair<int,int>>b[N],e[N],path[N];
map<pair<int,int>,int>mp;
void dfs(int id)
{
    priority_queue<pair<int,int>>p;
    for(int i=1;i<=n;i++)vis[i]=0,d[id][i]=1e18+7;
    d[id][id]=0;
    p.push({0,id});
    while(p.size())
    {
        auto[x,u]=p.top();
        p.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto[v,w]:e[u])
        {
            if(d[id][v]>d[id][u]+w)
            {
                d[id][v]=d[id][u]+w;
                p.push({-d[id][v],v});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>n>>m>>fw>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
            b[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto[j,t1]:b[i])
        {
            for(auto[k,t2]:b[i])
            {
                if(k==j)continue;
                path[j].push_back({k,t1+t2});
                path[k].push_back({j,t1+t2});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        sort(path[i].begin(),path[i].end());
        int j=0;
        for(auto[des,ti]:path[i])
        {
            j++;
            if(j>1&&des==path[i][j-2].first)continue;
            e[i].push_back({des,ti});
        }
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i);
    }
    for(int i=1;i<=q;i++)
    {
        int x,y,ans=1e18+7;
        cin>>x>>y;
        for(auto[j,t1]:b[x])
        {
            for(auto[k,t2]:b[y])
            {
                ans=min(ans,d[j][k]+t1+t2);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
