#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
};
int o,n,m,d,p;
bool operator <(node x,node y){
	return x.w>y.w; 
}
vector <node> g[1001];
int c[1001];
int dis[1001];
bool vis[1001];
int dij(int f,int t){
	priority_queue<node>q;
	for(int i=1;i<=m;i++){
		dis[i]=1e9;
		vis[i]=0;
	}
	q.push({f,0});
	dis[f]=0;
	while(!q.empty()){
		int v=q.top().v;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		for(auto i:g[v]){
			if(dis[i.v]>dis[v]+i.w){
				dis[i.v]=dis[v]+i.w;
				q.push({i.v,dis[i.v]});
			}
		}
	}
	return dis[t];
}
//priority_pueue
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>o>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int u,z,v,w;
		cin>>u>>z>>v>>w;
		g[u].push_back({v,w+z});
		g[v].push_back({u,w+z});
	}
	while(p--){
		int f,t;
		cin>>f>>t;
		cout<<dij(f,t)+c[f]+c[t]<<'\n';
	}//xym
	return 0;
}
