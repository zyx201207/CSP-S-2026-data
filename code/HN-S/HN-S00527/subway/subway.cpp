#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005,M=500005;
const ll INF=1e18;
int c,n,m,d,Q;
struct edge{
    int to,nxt; ll w;
}e[M*4];
int head[N],tot=0;
void add(int u,int v,ll w){
    e[++tot]={v,head[u],w};
    head[u]=tot;
}
struct Node{
    ll d;
    int u;
    bool operator<(const Node&o) const{
        return d>o.d;
    }
};
ll dis[N];
bool vis[N];
priority_queue<Node>q;
void dijkstra(int s){
    dis[s]=0; 
    q.push({0,s}); 
    while(!q.empty()){
        Node cur=q.top(); q.pop();
        int u=cur.u; 
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to; ll w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
void init(){
    for(int i=1;i<=m*(n+2);i++){
        dis[i]=INF; vis[i]=0;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        int w; cin>>w;
        add(i+m,i,w); add(i,i+m,w);
    }
    for(int i=1;i<=n;i++){
        int K,k; cin>>K;
        int a[N];
        for(int j=1;j<=K;j++){
            cin>>a[j]>>k;
            add(a[j]+m,a[j]+m*(i+1),k);
            add(a[j]+m*(i+1),a[j]+m,k);
        } 
        for(int u=1;u<=K;u++){
            for(int v=u+1;v<=K;v++){
                add(a[u]+m*(i+1),a[v]+m*(i+1),0);
                add(a[v]+m*(i+1),a[u]+m*(i+1),0);
            }
        }
    }
    while(Q--){
        int u,v; cin>>u>>v;
        init();
        dijkstra(u);
		cout<<dis[v]<<endl;
    }
    return 0;
}
