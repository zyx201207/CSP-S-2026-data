#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll INF=0x3f3f3f3f3f3f3f3fLL;
const int N=1e5+5;
vector<pair<int,int>> adj[N];
ll dist[N];
void dijkstra(int s,int n){
	for(int i=1;i<=n;i++) dist[i]=INF;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		auto &f=pq.top();
		pq.pop();
		int d=f.first;
		int u=f.second;
		cout<<d<<" "<<u<<endl;
		if(d>dist[u]) continue;
		for(auto &e:adj[u]){
			int v=e.first;
			int w=e.second;
			cout<<u<<" "<<v<<" "<<w<<endl;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
}
int main(){
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	dijkstra(s,n);
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
}
