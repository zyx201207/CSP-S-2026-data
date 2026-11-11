#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c, t;
int n, d;
ll a[2001000];
ll y[2001000];
vector <int> g[2001000];
ll dist[2001000];
void dij(int x){
	for (int i = 1; i <= n; i++) dist[i] = LONG_LONG_MAX;
	for (int i = 1; i <= n; i++) y[i] = 0;
	dist[x] = 0;
	y[x] = 0;
	priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push(make_pair(0, x));
	while (!pq.empty()){
		int u = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		if (d > dist[u]) continue;
		
		for (int v : g[u]){
			if (dist[v] > 1 + dist[u]){
				dist[v] = 1 + dist[u];
				y[v] = 1;
				pq.push({dist[v], v});
			}
			else if (dist[v] == 1 + dist[u]){
				y[v] += y[u];
			}
		}
	} 
}
void solve1(){
	cin >> n >> d;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (i != j && a[i] - a[j] <= d && a[i] - a[j] >= -d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}ll cnt = 0;
	for (int i = 1; i <= n; i++){
		dij(i);
		for (int j = i + 1; j <= n; j++){
			if (y[j] == 2 && i != j) {
			cnt++;}
		}
	}cout << cnt << endl;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)solve1();
	
	return 0;
} 
