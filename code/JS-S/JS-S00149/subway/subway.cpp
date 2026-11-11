#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
const int M1=1010;
const int M2=20010;
typedef long long ll;
int c,n,m,d,q,a[M],u,v,k;
ll w[M],t[M],dis[M1][M1],dis_b[M2];
bool vis[M1];
struct edge{
    int v;
    ll w;
};
vector<edge> g[M];
void dijkstra(int s){
    priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
    for(int i=1;i<=m;i++){
        dis[s][i]=1e18;
        vis[i]=0;
    }
    dis[s][s]=0;q.push({0,s});
    while(!q.empty()){
        pair<ll,int> p=q.top();q.pop();
        if(vis[p.second])continue;
        vis[p.second]=1;
        for(auto k:g[p.second]){
            if(dis[s][k.v]>dis[s][p.second]+k.w){
                dis[s][k.v]=dis[s][p.second]+k.w;
                q.push(make_pair(dis[s][k.v],k.v));
            }
        }
    }
}
void bfs(int s){
    queue<int> q;
    for(int i=1;i<=m;i++)dis_b[i]=1e18;
    dis_b[s]=0;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto k:g[u]){
            if(dis_b[k.v]>dis_b[u]+1){
                dis_b[k.v]=dis_b[u]+1;
                q.push(k.v);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            scanf("%d%lld",&a[i],&t[i]);
            for(int j=1;j<i;j++){
                g[a[i]].push_back({a[j],t[i]+t[j]});
                g[a[j]].push_back({a[i],t[i]+t[j]});
            }
        }
    }
    if(c<=11){
        for(int i=1;i<=m;i++)dijkstra(i);
    }
    while(q--){
        scanf("%d%d",&u,&v);
        if(c<=11)printf("%lld\n",dis[u][v]+w[u]+w[v]);
        else{
            bfs(u);
            printf("%lld\n",1ll*dis_b[v]*2*t[k]+w[u]+w[v]);
        }
    }
    return 0;
}
