#include<bits/stdc++.h>
using namespace std;
int c , n , m , d , q;
int tot = -1 , head[500505] , ver[20000005] , ne[20000005] , w[20000005];
long long dis[500505] , dist[505][505] , cw[500005];
bool vis[500505];
void add(int x , int y , int z) {
	tot++;
	ver[tot] = y;
	w[tot] = z;
	ne[tot] = head[x];
	head[x] = tot;
}
void dijkstra(int s) {
	priority_queue<pair<long long , int> , vector<pair<long long , int> > , greater<pair<long long , int> > > q;
	dis[s] = 0;
	q.push({0 , s});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u] ; i != -1 ; i = ne[i]) {
			int v = ver[i];
			if(!vis[v] && dis[u] + w[i] < dis[v]) {
				dis[v] = dis[u] + w[i];
				q.push({dis[v] , v});
			}
		}
	}
}
int main() {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0); 
	memset(head , -1 , sizeof head);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++) cin >> cw[i];
	for(int i = 1 ; i <= n ; i++) {
		int k;
		cin >> k;
		for(int j = 1 ; j <= k ; j++) {
			int p , t;
			cin >> p >> t;
			add(i + m , p , t);
			add(p , i + m , t);
		}
	}
	for(int i = 1 ; i <= n ; i++) {
		memset(dis , 0x3f , sizeof dis);
		memset(vis , 0 , sizeof vis); 
		dijkstra(i + m);
		for(int j = i ; j <= n ; j++) { 
			dist[i][j] = dist[j][i] = dis[j + m];
		}
	}
	while(q--) {
		long long ans = LONG_LONG_MAX;
		int x , y;
		cin >> x >> y;
		for(int i = head[x] ; i != -1 ; i = ne[i]) {
			int u = ver[i] - m;
			for(int j = head[y] ; j != -1 ; j = ne[j]) {
				int v = ver[j] - m;
				ans = min(ans , dist[u][v] + cw[x] + cw[y] + w[i] + w[j]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
