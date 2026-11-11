#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int NK = 5e5+5;
int c , n , m , d , q;
int W[NK] , a[N][NK] , T[N][NK] , K[N];
bool vis[N];
int dis[N];
struct Edge{
	int v , w;
	bool operator > (Edge e) const{
		return w>e.w;
	}
};
vector<Edge> g[N];
void dijkstra(int s , int t){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<Edge,vector<Edge>,greater<Edge>> q;
	q.push({s,0});
	dis[s] = 0;
	while(!q.empty()){
		int u = q.top().v;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		//cout<<u<<endl;
		for(auto e : g[u]){
			int w = e.w;
			int v = e.v;
			//cout<<v<<endl;
			if(dis[v]>dis[u]+w){
				//cout<<v<<endl;
				dis[v] = dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1 ; i<=m ; i++) cin>>W[i];
	for(int i = 1 ; i<=n ; i++){
		cin>>K[i];
		for(int j = 1 ; j<=K[i] ; j++){
			cin>>a[i][j];
			int xx = a[i][j];
			cin>>T[i][xx];
		} 
	} 
	for(int i = 1 ; i<=n ; i++){
		for(int j = 1 ; j<=K[i] ; j++){
			int c1 = a[i][j];
			for(int k = 1 ; k<=K[i] ; k++){
				int c2 = a[i][k];
				if(c1==c2) continue;
				g[c1].push_back({c2,T[i][c2]+T[k][c2]});
				g[c2].push_back({c1,T[i][c1]+T[j][c1]});
			}
		}
	}
	//~ cout<<endl;
	//~ for(int i =1 ; i<=n ; i++){
		//~ cout<<i<<endl;
		//~ for(auto e : g[i]){
			//~ cout<<e.v<<' '<<e.w<<endl;
		//~ }
	//~ }
	//~ cout<<endl;
	while(q--){
		int s , t;
		cin>>s>>t;
		dijkstra(s,t);
		//cout<<dis[t]<<endl;
		int ccs , cct;
		for(int i = 1 ; i<=n ; i++){
			for(int j = 1; j<=K[i] ; j++){
				if(a[i][j]==s){
					ccs = T[j][a[i][j]];
				}
				if(a[i][j]==t){
					cct = T[j][a[i][j]];
				}
			}
		}
		//cout<<dis[2]<<endl;
		//cout<<dis[3]<<endl;
		cout<<W[s]+ccs+dis[t]-cct+W[t]<<'\n';
	}
	return 0;
}
