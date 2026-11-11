#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10; 
const int M = 1e3 + 10;

int c, n, m, d, q;
int w[M];

int a[N][M], t[N][M];

vector <pair <int, int>> g[M];

int dis[1010][1010];
bool vis[M];
#define pii pair <int, int>
void dijkstra(int s){
	memset(vis, false ,sizeof vis);
	priority_queue <pii, vector <pii>, greater <pii>> q;
	dis[s][s] = 0;
	q.push({dis[s][s], s});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto i : g[u]){
			int v = i.first, w = i.second;
			if(dis[s][v] > dis[s][u] + w){
				dis[s][v] = dis[s][u] + w;
				q.push({dis[s][v], v});
			}
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	int tot = m + m;
	for(int i = 1; i <= n; i ++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j ++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int j = 1; j < k; j ++){
			for(int l = j + 1; l <= k; l ++){
				g[a[i][j]].push_back({a[i][l], t[i][j] + t[i][l]});
				g[a[i][l]].push_back({a[i][j], t[i][j] + t[i][l]});
			}
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= m; i ++){
		dijkstra(i);
	}
	while(q --){
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + dis[x][y] << '\n';
	}
	return 0;
}
