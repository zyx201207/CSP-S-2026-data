#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[20005];
int k[505];
int walktime[505][25], stations[505][25];
int g[20005][20005], dis[20005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int a, t;
			cin >> a >> t;
			stations[i][j] = a;
			walktime[i][j] = t;
		}
	}
	

	for(int i = 1; i <= n; i++){
		for(int u = 1; u < k[i]; u++){
			for(int v = u+1; v <= k[i]; v++){
				int eu = stations[i][u];
				int ev = stations[i][v];
				g[eu][ev] = walktime[i][u] + walktime[i][v];
				g[ev][eu] = walktime[i][u] + walktime[i][v];
			}
		}
	}

	while(q--){
		memset(dis, 0x3f, sizeof(dis));
		long long ans = 0;
		int x, y;
		cin >> x >> y;
		ans = ans + w[x] + w[y];
		dis[x] = 0;
		for(int u = 1; u <= m; u++){
			for(int v = 1; v <= m; v++){
				if((g[u][v] != 0 || g[v][u] != 0) && dis[v] > dis[u] + g[u][v])
					dis[v] = dis[u] + g[u][v];
			} 
		}
		cout << ans + dis[y] << "\n";
	}
	return 0;
} 
