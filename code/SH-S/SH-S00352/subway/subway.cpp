#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, d, q;
ll w[500100];
ll a[500100][2];
vector<pair<int, ll>> g[500100];

ll dist[500100];
ll dijkstra(int x, int y){
	for (int i = 1; i <= m; i++) dist[i] = LONG_LONG_MAX;
	dist[x] = 0;
	priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push(make_pair(0, x));
	while (!pq.empty()){
		int u = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		if (d > dist[u]) continue;
		
		for (auto edge : g[u]){
			int v = edge.first;
			ll t = edge.second;
			if (dist[v] > t + dist[u]){
				dist[v] = t + dist[u];
				pq.push({dist[v], v});
			}
		}
	} 
	return dist[y];
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			cin >> a[j][0] >> a[j][1];
//			if (j >= 2){
//				int x = a[j - 1][0];
//				int y = a[j][0];
//				ll t = a[j - 1][1] + a[j][1];
//				g[x].push_back(make_pair(y, t));
//				g[y].push_back(make_pair(x, t));
//			}
		}
		for (int j = 1; j <= k; j++){
			for (int l = 1; l <= k; l++){
				if (j != l){
					int x = a[j][0];
					int y = a[l][0];
					ll t = a[j][1] + a[l][1];
					g[x].push_back(make_pair(y, t));
					g[y].push_back(make_pair(x, t));
				}
			}
		}
	}
	for (int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		cout << dijkstra(x, y) + w[x] + w[y] << endl;
	}
	return 0;
} 
