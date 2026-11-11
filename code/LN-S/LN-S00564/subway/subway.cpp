
#include<bits/stdc++.h>
using namespace std;
const int N=5e7+5;
struct Node{
    int to,w;
};
vector<Node> G[N];
struct Point{
    int v,dist;
    bool operator<(const Point&p) const{
        return dist>p.dist; 
    }
};
priority_queue<Point> pq;
int dist[N];
int c,n,m,d,q;
void dijk(int start){
    fill(dist,dist+N,INT_MAX);
    dist[start]=0;
    pq.push({start,0});
    while(pq.size()){
        int u=pq.top().v;
        pq.pop();
        for(auto e:G[u]){
            int v=e.to,w=e.w;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({v,dist[v]});
            }
        }
    }
}
void work(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        G[i].push_back({i+m,k});
        G[i+m].push_back({i,k});
    }
    for(int i=1;i<=n;i++){
        int z;
        cin>>z;
        for(int j=1;j<=z;j++){
            int v,w;
            cin>>v>>w;
            G[2*m+i].push_back({v+m,w});
            G[v+m].push_back({2*m+i,w});
        }
    }
    while(q--){
        int from,to;
        cin>>from>>to;
        dijk(from);
        cout<<dist[to]<<'\n';
    }
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	work();
    //dijk(1);
    //for(int i=1;i<=12;i++) cout<<dist[i]<<' ';
    return 0;
}
