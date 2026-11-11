#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 2e6 + 10;

int c, t, n, d, a[maxn], dist[maxn], cnt[maxn];
vector<int> adj[maxn];


void bfs(int s){
	fill(dist + 1, dist + n + 1, maxn);
	fill(cnt + 1, cnt + n + 1, 0);
	queue<int> que;
	que.push(s);
	fill(dist + 1, dist + n + 1, maxn);
	dist[s] = 0;
	cnt[s] = 1;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int v : adj[u]){
			if(dist[v] > dist[u] + 1){
				dist[v] = dist[u] + 1;
				cnt[v] = 1;
				que.push(v);
			}else if(dist[v] == dist[u] + 1){
				cnt[v] += cnt[u];
			}
			
		}
	}
}

void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(i != j && a[j] - a[i] <= d){
				adj[i].push_back(j);
			}
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		bfs(i);
		for(int j = i + 1; j <= n; j++){
			if(cnt[i] == 2){
				ans++;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		adj[i].clear();
	}
	cout << ans << '\n';
} 

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
