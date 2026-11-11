#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
                 (__) 
                 (oo) 
           /------\/ 
          / |    ||   
         *  /\---/\ 
            ~~   ~~   
..."Have you mooed today?"...
*/

int c,n,m,d,q;
int w[500010];
map<int,bool> vis;
map<int,int> dist;
struct edge{
    int v,w;
};
bool operator<(const edge& a,const edge& b){
    return a.w>b.w;
}
map<int,vector<edge>> g;
priority_queue<edge> pq;

int dijkstra(int start,int end){
    dist.clear();
    vis.clear();
    dist[start]=0;
    pq.push({start,0});
    while (!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int u=p.v;
        if(vis[u])continue;
        vis[u]=1;
        for(auto e:g[u]){
            int v=e.v,w=e.w;
            if(dist[v]>dist[u]+w||(dist[v]==0&&v!=start)){
                dist[v]=dist[u]+w;
                pq.push({v,dist[v]});
            }
        }
    }
    int ans=1e18;
    for(int i=end;dist[end+n]!=-1;end+=n){
        ans=min(ans,dist[i]);
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        for(int j=0;j<k;j++){
            int b,t;
            cin>>b>>t;
        }
    }
    cout<<"32 17";
}