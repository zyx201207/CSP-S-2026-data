#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
struct edge{
    long long v,t;
};
int c,n,m,d,q;
long long w[500001],dist[500505],vis[500505];
vector<edge> adj[500505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int z=i+m;
        for(int j=1;j<=k;j++){
            int vl,tl;
            cin>>vl>>tl;
            adj[z].push_back({vl,tl});
            adj[vl].push_back({z,tl});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        fill(dist,dist+m+n+1,INF);
        fill(vis,vis+m+n+1,0);
        priority_queue< pair<long long,int>,vector <pair <long long,int> >,greater< pair<long long,int> > > pq;
        dist[x]=0;
        vis[x]=1;
        pq.push({dist[x],x});
        while(!pq.empty()){
            auto[d,u]=pq.top();
            pq.pop();
            for(edge r:adj[u]){
                if(vis[r.v]==0){
                    if(dist[u]+r.t<dist[r.v]){
                        dist[r.v]=dist[u]+r.t;
                        vis[r.v]=1;
                        pq.push({dist[r.v],r.v});
                    }
                }
            }
        }
        cout<<dist[y]+w[x]+w[y]<<endl;
    }
    return 0;
}
