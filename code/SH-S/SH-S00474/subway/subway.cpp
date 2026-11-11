#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> PII;
int c,lines,stations,limit,plans;
int BFS(vector<vector<pair<int,int> > > &adj, int x,int y){
	vector<bool> certain(stations*limit+1,false);
	vector<int> dist(stations*limit+1,INF);
	dist[x]=0;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int e=q.front();
		q.pop();
		
		if(e==y) return dist[e];
		if(certain[e]) continue;
		certain[e]=true;
		for(auto hh : adj[e]){
			int v=hh.first;
			dist[v]=dist[e]+1;
			q.push(v);
		}
	}
}
int dijkstra(vector<vector<pair<int,int> > > &adj,int x,int y){
	vector<bool> certain(stations*limit+1,false);
	vector<int> dist(stations*limit+1,INF);
	dist[x]=0;
	priority_queue<PII,vector<PII>,greater<PII> > pq;
	pq.push({x,0});
	while(!pq.empty()){
		auto h = pq.top();
		int u=h.first;
		int d=h.second;
		pq.pop();
		
		if(u==y){
			return d;
		}
		if(certain[u]) continue;
		certain[u]=true;
		
		for(auto hh : adj[u]){
			int v=hh.first;
			int w=hh.second;
			if(d+w<dist[v]){
				dist[v]=d+w;
				if(!certain[v]) pq.push({v,dist[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>lines>>stations>>limit>>plans;
	vector<int> port(stations+1);
	for(int i=1;i<=stations;i++){
		cin>>port[i];
	}
	int ID=stations+1;
	vector<vector<pair<int,int> > > adj(stations*limit+1);
	for(int i=1;i<=lines;i++){
		int k;
		cin>>k;
		int last=-1;
		for(int j=0;j<k;j++){
			int u,d;
			cin>>u>>d;
			adj[u].push_back({ID,d});
			adj[ID].push_back({u,d});
			if(last!=-1){
				adj[last].push_back({ID,0});
				adj[ID].push_back({last,0});
			}
			last=ID;
			ID++;
		}
	}
	//cout<<ID<<"\n";
	while(plans--){
		int x,y;
		cin>>x>>y;
		int distance;
		if(c>=16&&c<=19){
			distance=port[x]+port[y]+BFS(adj,x,y);
		}
		else distance=port[x]+port[y]+dijkstra(adj,x,y);
		cout<<distance<<"\n";
	}
	return 0;
}
