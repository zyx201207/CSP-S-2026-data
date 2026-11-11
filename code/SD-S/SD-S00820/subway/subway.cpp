#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
struct Node{
	int v;
	long long w;
	bool operator < (Node x) const{
		return w<x.w;
	}
};
int c,n,m,d,Q;
long long w[M],dis[N][N];
vector<Node> sta[M],g[N];
priority_queue<Node> q;
void dij(int s){
	dis[s][s]=0; q.push({s,0});
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		for(Node it:g[u]){
			int v=it.v;
			if(dis[s][u]+it.w<dis[s][v]){
				dis[s][v]=dis[s][u]+it.w;
				q.push({v,dis[s][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int ki; cin>>ki;
		for(int j=1;j<=ki;j++){
			int a; long long t; cin>>a>>t;
			for(Node x:sta[a]){
				g[x.v].push_back({i,t+x.w});
				g[i].push_back({x.v,t+x.w});
			}
			sta[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		dij(i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<"\n";
//	}
	while(Q--){
		int u,v; cin>>u>>v;
		long long ans=0x7ffffffffffff; 
		for(Node x:sta[u])
			for(Node y:sta[v])
				ans=min(ans,w[u]+w[v]+dis[x.v][y.v]+x.w+y.w);
		cout<<ans<<'\n';
	}
	return 0;
} 
