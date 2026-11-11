#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<pair<int,int>> g[10000005];
int dis[10000005];
bool vis[10000005];
void dijkstra(int st){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push({0,st});
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[st] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u] == 1) continue;
        vis[u] = 1;
        for(pair<int,int> tmp:g[u]){
            int v = tmp.first,w = tmp.second;
            if(dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=n;i++){
        int k,pre = -1;
        cin>>k;
        for(int j = 1;j<=k;j++){
            int x,t;
            cin>>x>>t;
            if(pre!=-1){
                g[pre+(i-1)*m].push_back({x+(i-1)*m,0});
                g[x+(i-1)*m].push_back({pre+(i-1)*m,0});
            }
            for(int l = 1;l<=n;l++){
                if(l == i) continue;
                g[x+(i-1)*m].push_back({x+(l-1)*m,t+w[i]});
            }
            pre = x;
        }
    }
    while(q--){
        int x,y,ans = 0x3f3f3f3f;
        cin>>x>>y;
        for(int i = 1;i<=n;i++){
            dijkstra(x+(i-1)*m);
            for(int j = 1;j<=m;j++){
                ans = min(ans,dis[y+(j-1)*m]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
