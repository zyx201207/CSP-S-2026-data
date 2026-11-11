#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,dist[1000][1000];
vector<pair<int,int> > e[1000005];
struct node{
	int id,w;
	bool operator<(const node &t)const{
		return w>t.w;
	}
};
priority_queue<node> q1;
void djk(int s){
	q1.push({s,0});
	while(!q1.empty()){
		int x=q1.top().id;
		q1.pop();
		if(q1.top().w>dist[x][s])continue;
		for(int i=0;i<e[x].size();i++){
			int v=e[x][i].first,w=e[x][i].second;
			if(dist[v][s]>dist[x][s]+w){
				dist[v][s]=dist[x][s]+w;
				q1.push({v,dist[v][s]});
			}
		}
	}
}
signed main(){
	cin>>n>>m>>k;
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int u,v;
		cin>>u>>v;
		cout<<dist[u][v];
	}
}
