#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,a[2];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    vector<int> W(m+1);
    vector<vector<pair<int,int>>> g(n*m+m+1);
    for(int i=1;i<=m;i++)
        cin>>W[i];
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        int t;
        for(int j=1;j<=k;j++)
        {
            cin>>a[(j-1)%2]>>t;
            if(j>1){
                g[a[j%2]+i*m].push_back({a[(j-1)%2]+i*m,0});
                g[a[(j-1)%2]+i*m].push_back({a[j%2]+i*m,0});}
                g[a[(j-1)%2]+i*m].push_back({a[(j-1)%2],t});
                g[a[(j-1)%2]].push_back({a[(j-1)%2]+i*m,t});
        }
    }
    while(q--)
    {
        cin>>x>>y;
        vector<int> dis(n*m+m+1,0x3f3f3f3f);
        vector<bool> vis(n*m+m+1,0);
        priority_queue<pair<int,int>> pq;
        dis[x]=0;
        pq.push({-dis[x],x});
        while(!pq.empty())
        {
            auto [d,u]=pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(auto [v,w]:g[u])
                if(dis[v]>dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    pq.push({-dis[v],v});
                }
        }
        cout<<dis[y]+W[x]+W[y]<<"\n";
    }
    return 0;
}
