#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 500 + 10;
const int M = 1000 + 10;

int c, n, m, d, q;
int w[N];
vector <int> vec[N];
int k[N];
int a[N][M], t[N][M];
bool vis[N][M];
int dist[M];
int ans[M][M];

void bfs(int x, int y){
	memset(dist, 0x3f, sizeof(dist));
	dist[x] = 0;
	queue <int> q;
	q.push(x);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 1; i <= n; i++){
			if(vis[i][u]){
				int tmp = 0;
				for(int j = 1; j <= k[i]; j++){
					if(a[i][j] == u){
						tmp = t[i][j];
						break;
					}
				}
				for(int j = 1; j <= k[i]; j++){
					int v = a[i][j];
					if(v == u) continue;
					if(dist[v] > dist[u] + tmp + t[i][j]) {
						dist[v] = dist[u] + tmp + t[i][j];
						q.push(v);
					}
				}
			}
		}
	}
	return;
}

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	memset(dist, 0x3f, sizeof(dist));
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			vis[i][a[i][j]] = true;
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			if(i == j) ans[i][j] = 0;
			else {
				bfs(i, j);
				ans[i][j] = w[i] + w[j] + dist[j];
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << ans[x][y] << "\n";
	}
	return 0;
}
