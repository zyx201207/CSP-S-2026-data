#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1005;
const int B = 5e5 + 5;
const int D = 505;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int c,n,m,p,t;
ll w[B];
vector<pair<ll,int>> g[B + D];
ll dist[N + D][N + D];
ll b[B + D];
bool vis[B + D];
bool flagB = true;

void dijkstra(int s){
	dist[s][s] = 0;
	
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
	q.push({0,s});
	
	while(!q.empty()){
		ll d = q.top().first;
		int u = q.top().second;
		q.pop();
		
		if(d > dist[s][u]) continue;
		
		for(auto &i : g[u]){
			int v = i.second;
			ll nd = d + i.first;
			
			if(nd < dist[s][v]){
				dist[s][v] = nd;
				q.push({nd,v});
			}
		}
	}
}

void solveB(){
	queue<pair<ll,int>> q;
	q.push({0,1});
	
	b[1] = 0;
	vis[1] = true;
	
	while(!q.empty()){
		ll d = q.front().first;
		int u = q.front().second;
		q.pop();
		
		for(auto &i : g[u]){
			int v = i.second;
			
			if(vis[v]) continue;
			vis[v] = true;
			
			b[v] = d + 1;
			
			q.push({d + 1,v});
		}
	}
	
	while(t--){
		int u,v;
		cin >> u >> v;
			
		cout << abs(b[u] - b[v]) + w[u] + w[v] << '\n';
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> m >> n >> p >> t;
	for(int i=1;i<=n;i++){
		cin >> w[i];
	}
	
	for(int i=1;i<=m;i++){
		int k;
		cin >> k;
		
		for(int j=1;j<=k;j++){
			int u;
			ll d;
			
			cin >> u >> d;
			
			g[n + i].push_back({d,u});
			g[u].push_back({d,n + i});
			
			if(d != 1) flagB = false;
		}
	}
	
	if(flagB){
		solveB();
		return 0;
	}
	
	memset(dist,0x3f,sizeof dist);
	
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	
	while(t--){
		int u,v;
		cin >> u >> v;
		cout << dist[u][v] + w[u] + w[v] << '\n';
	}
	
	return 0;
}
