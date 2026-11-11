#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> pii;
const long long N = 5e5+10;

long long task,n,m,d,q;
long long w[N];
vector<pii> graph[N*2];
long long dist[N*2];
bool vis[N*2];
priority_queue<pii,vector<pii>,greater<pii> > pq;

void dijkstra(long long start){
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	while(!pq.empty()) pq.pop();
	
	dist[start] = 0;
	pq.push({0,start});
	
	long long u,w,v;
	while(!pq.empty()){
		
		u=pq.top().second; pq.pop();
		if(vis[u]) continue;
		vis[u] = true;
		
		for(auto nd : graph[u]){
			w=nd.first,v=nd.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u]+w;
				if(!vis[v]) pq.push({dist[v],v});
			}
		}
	}
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>task>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	
	long long nd=m;
	
	for(long long i=1,len;i<=n;i++){
		cin>>len;
		for(long long j=1,sta,t;j<=len;j++){
			cin>>sta>>t;
			++nd;
			graph[sta].push_back({t,nd});
			graph[nd].push_back({t,sta});
			
			if(j != 1){
				graph[nd].push_back({0,nd-1});
				graph[nd-1].push_back({0,nd});
			}
		}
	}
	
	
	long long st,ed;
	while(q--){
		cin>>st>>ed;
		dijkstra(st);
		cout<<dist[ed]+w[st]+w[ed]<<'\n';
	}
	
	
	return 0;
}