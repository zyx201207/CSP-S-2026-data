#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<pair<int,ll>>> g;
int c,n,m,d,q;
ll idx;
vector<ll> dij(int s){
    vector<ll> dis(2*m+n+1,1e18);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    dis[s]=0,pq.push({0,s});
    vector<int> vis(2*m+n+1,false);
    while(!pq.empty()){
        int u=pq.top().second;
        ll di=pq.top().first;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto ve:g[u]){
            int v=ve.first;
            ll w=ve.second;
            if(dis[v]>di+w||dis[v]==1e18) dis[v]=di+w,pq.push({dis[v],v});
        }
    }
    return dis;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    g.resize(2*m+n+1);
    vector<vector<ll>> dist(2*m+n+1,vector<ll>(2*m+n+1,1e18));
    for(int i=1,w;i<=m;i++) cin>>w,g[i].push_back({m+i,w}),g[m+i].push_back({i,w});
    for(int i=1,k;i<=n;i++){
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            g[m+a].push_back({2*m+i,t}),g[2*m+i].push_back({m+a,t});
        }
    }
    for(int i=1;i<=m;i++) dist[i]=dij(i);
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dist[x][y]<<'\n';
    }
    return 0;
}
