#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2,M=5e6,INF=1e18;
int w[M+10],k,h[M+10];
int c,n,m,d,q,maxn;
struct node{
    int v,w;
    node(int _v,int _w):
        v(_v),w(_w){}
};
vector<node> e[M+10];
struct edge{
    int d,dis;
    edge(int _d,int _dis):
        d(_d),dis(_dis){}
};
bool operator<(edge x,edge y){
    return x.dis>y.dis;
}
int dist[M+10];
bool vis[M+10];
int dis(int s,int t){
    priority_queue<edge> q;
    q.push(edge(s,0));
    for(int i=1;i<=3*m+maxn*m;i++) dist[i]=INF,vis[i]=false;
    dist[s]=0;
    while(!q.empty()){
        auto u=q.top();
        q.pop();
        if(vis[u.d]) continue;
        vis[u.d]=true;
        for(auto x:e[u.d]){
            int v=x.v,w=x.w;
            if(dist[v]>dist[u.d]+w){
                dist[v]=dist[u.d]+w;
                if(!vis[v]) q.push(edge(v,dist[v]));
            }
        }
    }
    return dist[t];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        e[i+m].push_back(node(i,w[i]));
        e[i].push_back(node(i+m,w[i]));
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int lx=0;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            h[x]++;
            if(lx!=0){
                e[x+m+m*h[x]].push_back(node(lx+m+m*h[lx],0));
                e[lx+m+m*h[lx]].push_back(node(x+m+m*h[x],0));
            }
            lx=x;
            e[x+m+m*h[x]].push_back(node(x,y));
            e[x].push_back(node(x+m+m*h[x],y));
        }
    }
    for(int i=1;i<=m;i++) maxn=max(maxn,h[i]);
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        cout<<dis(u+m,v+m)<<"\n";
    }
    return 0;
}