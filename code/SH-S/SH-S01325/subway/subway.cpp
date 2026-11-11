#include <bits/stdc++.h>
#define int long long
#define N 508
#define M 500518
using namespace std;
int c,n,m,d,q;
bool vis[M];
int w[M],dis[M];
struct Node{
	int to,w;
}node;
vector<Node> g[M];
void Dijkstra(int s){
	struct cmp{
		bool operator()(const Node& a,const Node& b){
			return a.w>b.w;
		}
	};
	priority_queue<Node,vector<Node>,cmp> pq;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	node.to=s,node.w=0;
	pq.push(node);
	while(!pq.empty()){
		int u=pq.top().to;
		pq.pop();
		if(vis[u]){continue;}
		vis[u]=1;
		for(Node v:g[u]){
			if(dis[v.to]>dis[u]+v.w){
				dis[v.to]=dis[u]+v.w;
				node.to=v.to,node.w=dis[v.to];
				pq.push(node);
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int a,t; cin>>a>>t;
			g[i+500008].push_back({a,t});
			g[a].push_back({i+500008,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		Dijkstra(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}

