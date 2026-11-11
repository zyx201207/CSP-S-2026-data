#include<bits/stdc++.h>
using namespace std;
int w[int(5e5+5)];
struct node{int v,w,nxt;}g[int(1e6+10)];
int tot,head[int(6e5+10)];
void add(int x,int y,int w){
    g[++tot]={y,w,head[x]};
    head[x]=tot;
}
int dis[int(6e5+10)];
bool vis[int(6e5+10)];
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<> > pq;
    pq.push({0,s});
    dis[s]=0;
    while(!pq.empty()){
        auto[d,u]=pq.top();pq.pop();
        vis[u]=true;
        for(int i=head[u];i;i=g[i].nxt){
            int v=g[i].v,w=g[i].w;
            if(vis[v]) continue;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
                vis[v]=false;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("subway.in","r",stdin);
    // freopen("subway.out","w",stdout);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;cin>>a>>t;
            add(n+a,i,t);
            add(i,n+a,t);
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        dij(n+x);
        cout<<dis[n+y]+w[x]+w[y]<<'\n';
    }
    return 0;
}

