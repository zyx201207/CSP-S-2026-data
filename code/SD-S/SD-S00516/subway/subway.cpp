#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
const int INF = 0x3F3F3F3F;

class C_Graph{
public:
	struct Edge{
		int u,v,w;
		
		int operator()(int x)const{
			return u^v^x;
		}
	};
	int n;
	vector<Edge> edges;
	vector<vector<int>> edge;
	void AddEdge(int u,int v,int w){
		edges.push_back({u,v,w});
		edge[u].push_back(edges.size() - 1);
		edge[v].push_back(edges.size() - 1);
	}
	void Init(int n){
		this -> n = n;
		edges.clear();
		edge.assign(n + 1,vector<int>());
	}
};
struct Node{
	ll dist,u;
	int friend operator < (Node a,Node b){
		return a.dist > b.dist; 
	}
};
ll w[N];
ll dist[N],vis[N];
void Dijkstra(const C_Graph &g,int x){
	memset(dist,INF,sizeof dist);
	memset(vis,0,sizeof vis);
	priority_queue<Node> pq;
	dist[x] = 0;
	pq.push({0,x});
	while(!pq.empty()){
		Node x = pq.top();pq.pop();
		if(x.dist > dist[x.u]) continue;
		if(vis[x.u] == 1) continue; 
		vis[x.u] = 1; 
		for(int it : g.edge[x.u]){
			int u = x.u,v = g.edges[it](x.u),w = g.edges[it].w;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push({dist[v],v});
			}
		}
	}
	
//	for(int i = 1;i <= g.n;i++){
//		cout << dist[i] << " ";
//	}
//	cout << "\n";
	return ;
}

void Solve(){
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	C_Graph g;g.Init(m);
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;cin >> k;ll a,b,t_1,t_2;
		cin >> a >> t_1 >> b >> t_2;
		g.AddEdge(a,b,t_1 + t_2);
	}
	
	for(int i = 1;i <= q;i++){
		int l,r;cin >> l >> r;
		Dijkstra(g,l);
		cout << w[l] + dist[r] + w[r] << "\n";
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	Solve();
	return 0;
}

