#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,hs;
int a[500005];
vector<int>G[1005];
int dist[1005][1005];
int dis[1005][1005];
int x[500005],wei[500005];
int vis[500005];
struct node{
    int u;
    int dist;
    bool operator<(const node a)const{
        return a.dist<dist;
    }
};
priority_queue<node>pq;
void dij(int s){
    memset(dis[s],0x3f,sizeof(dis[s]));
    memset(vis,0,sizeof(vis));
    dis[s][s]=0;
    pq.push({s,0});
    while(!pq.empty()){
        auto tmp=pq.top();
        pq.pop();
        int u=tmp.u;
        if(vis[u]) continue;
        vis[u]=1; 
        for(int v:G[u]){
            int w=dist[u][v];
            if(dis[s][v]>dis[s][u]+w){
                dis[s][v]=dis[s][u]+w;
                if(!vis[v]) pq.push({v,dis[s][v]});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x[j]>>wei[j];
            for(int p=1;p<j;p++){
                G[x[j]].push_back(x[p]);
                G[x[p]].push_back(x[j]);
                dist[x[j]][x[p]]=min(dist[x[j]][x[p]],wei[j]+wei[p]);
                dist[x[p]][x[j]]=dist[x[j]][x[p]];
            }
        }
    }
    for(int i=1;i<=m;i++) dij(i);
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+a[x]+a[y]<<'\n';
    }
    return 0;
}