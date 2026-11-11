/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
#include<bits/stdc++.h>
//#define cerr int
#define int long long
#define eb emplace_back
using namespace std;

const int N=1e6+10000, INF=1e18;
int W[N];
struct Edge{int v, w;};
vector<Edge> g1[N];
int n, m, maxd, Q, ID;
int d[N];
bool vis[N];
struct Node{
	int d, id;
	friend bool operator<(const Node &x, const Node &y){
		return x.d>y.d;
	}
};
priority_queue<Node> q;
void dij(int s){
	for(int i=0; i<=n+m; i++) d[i]=INF, vis[i]=0;
	d[s]=0;
	q.push({0, s});
	while(!q.empty()){
		int u=q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(Edge to:g1[u]){
			int v=to.v, w=to.w;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push({d[v], v});
			}
		}
	}
}
namespace bf1{
	void main(){
		while(Q--){
			int x, y; cin>>x>>y;
			dij(x);
			cout<<d[y]+W[x]+W[y]<<"\n";
		}
	}
}
namespace bf2{
	const int Max=1510;
	int dis[Max][Max];
	void main(){
		for(int i=1; i<=n; i++){
			dij(i);
			for(int j=1; j<=n; j++)
				dis[i][j]=d[j];
		}
		while(Q--){
			int x, y; cin>>x>>y;
			cout<<dis[x][y]+W[x]+W[y]<<"\n";
		}
	}
}
void fastio(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fastio();
	cin>>ID>>m>>n>>maxd>>Q;
	for(int i=1; i<=n; i++) cin>>W[i];
	for(int i=1; i<=m; i++){
		int x; cin>>x;
		int u=i+n, v, w;
		for(int j=1; j<=x; j++){
			cin>>v>>w;
			g1[u].eb(Edge{v, w});
			g1[v].eb(Edge{u, w});
		}
	}
	if(ID>=9 && ID<=11) return bf2::main(), 0;
	return bf1::main(), 0;
//	if(ID>=12 && ID<=15) return bf3::main(), 0;
	return 0;
}
