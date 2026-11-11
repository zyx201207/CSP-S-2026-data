#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int to,w;
};
vector<node> g[2000005];
int c,n,m,d,q,id;
int w[500005];
int dis[500005],vis[500005];
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int> > q;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto it:g[u]){
            int v=it.to,w=it.w;
            if(dis[u]+w<=dis[v]){
                dis[v]=dis[u]+w;
                q.push({-dis[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        int w;
        cin>>w;
        g[i].push_back({i+m,w});
        g[i+m].push_back({i,w});
    }
    id=2*m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            g[a+m].push_back({++id,t});
            g[id].push_back({a+m,t});
            if(j!=1){
                g[id].push_back({id-1,0});
                g[id-1].push_back({id,0});
            }
        }
    }
    while(q--){
        int s,t;
        cin>>s>>t;
        dij(s);
        cout<<dis[t]<<"\n";
    }
    r
