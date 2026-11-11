#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
struct Edge{
	int ver,weight;
};
struct Node{
	int id,dist;
	bool operator<(const Node&other) const {
		return dist>other.dist;
	}
};
int c,n,m,d,q,cnt,x,y,k[N],dist[N];
vector<Edge> e[N];
void clean(){
	for(int i=1;i<=2*m+n;i++){
		dist[i]=INT_MAX;
	}
}
void dijkstra(int start){
	priority_queue<Node> h;
	h.push({start,0});
	dist[start]=0;
	while(!h.empty()){
		Node t=h.top();
		int u=t.id;
		h.pop();
		for(Edge i:e[u]){
			int v=i.ver;
			if(dist[u]+i.weight<dist[v]){
				h.push({v,dist[u]+i.weight});
			}
			dist[v]=min(dist[v],dist[u]+i.weight);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>x;
		e[i].push_back({m+i,x});
		e[m+i].push_back({i,x});
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			e[x+m].push_back({2*m+i,y});
			e[2*m+i].push_back({x+m,y});
		}
	}
//	for(int i=1;i<=2*m+n;i++){
//		for(Edge j:e[i]){
//			cout<<i<<" "<<j.ver<<" "<<j.weight<<"\n";
//		}
//	}
	while(q--){
		cin>>x>>y;
		clean();
		dijkstra(x);
		cout<<dist[y]<<"\n";
	}
	return 0;
	/*
	表示：地铁口i
	      站厅m+i
		  站台2*m+cnt 
	*/
}