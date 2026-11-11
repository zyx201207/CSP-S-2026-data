
// t1也没追出正解。。后面不会

//j tooo easy
//s toooooooo difficult TwT
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=1e5+5;
int n,m;
ll dis[MAXN];
bool vis[MAXN];
struct edge{
    ll v,w;
    friend bool operator < (edge a,edge b){
        return a.w>b.w;
    }
};
vector<edge>g[MAXN];
void dijkstra(int s){
    priority_queue<edge>q;
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    q.push({s,dis[s]});
    while(!q.empty()){
        int u=q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].v;
            int w=g[u][i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
    
    cout<<0;
}
int main(){
    freopen("migrate.out","w",stdout);
}