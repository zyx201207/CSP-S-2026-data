#include<bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f; 
const int N = 5e5+5;
long long dist[N];
bool vist[N];
int c, n, m, d, q;
vector<pair<int, int>> g[N];
int spend[N];
int ans = INF, k, a, t, flo;

int dijkstra(int start, int end){
	memset(dist, INF, sizeof(dist));
	memset(vist, false, sizeof(vist));
	dist[start] = 0;
	vist[start] = true;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start}); // distant, index
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		if (vist[u]) continue;
		vist[u] = true;
		for (int i = 0; i < (int)g[u].size();i++){
			int v = g[u][i].first;
			int w = g[u][i].second;
			if (dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	return dist[end];
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++){
		cin >> spend[i];
	}
	
	for (int i = 1; i <= n; i++){
		k = 0, a = 0, t = 0;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			g[a+m*flo].push_back({m*(n+1)+i, t});
			g[m*(n+1)+i].push_back({a+m*flo, t});
			g[a+m*(flo+1)].push_back({m*(n+1)+i, t});
			g[m*(n+1)+i].push_back({a+m*(flo+1), t});
		}
		flo++;
	}
	
	for(int s = 1; s <= q; s++){
		int x, y;
		cin >> x >> y;
		for(int j = 0; j <= n; j++){
			ans = min(ans, dijkstra(x, y+m*j));
		}
		ans = ans + spend[x] + spend[y];
		cout << ans << endl;
	}
	
	return 0;
}
