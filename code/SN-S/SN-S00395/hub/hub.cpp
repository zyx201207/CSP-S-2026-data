#include <bits/stdc++.h>
#define int int64_t

const int maxn = 16;
const int inf = 1ll << 50;

int c, t, n, k, u, v;
int dist[maxn][maxn];
bool colored[maxn];

void qualify(int x, int state) {
	if (!(state >> x - 1 & 1)) return;
	if (colored[x]) return;
	colored[x] = true;
	for (int i = 1; i <= n; i++)
		if (dist[x][i] == 1) 
			qualify(i, state);
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	std::cin >> c >> t;
	
	while (t -- ) {
		std::cin >> n >> k;
		int ans = inf;
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = inf * (i != j);
		
		for (int i = 1; i < n; i++) {
			std::cin >> u >> v;
			dist[u][v] = dist[v][u] = 1;
		}
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					dist[j][k] = std::min(dist[j][i] + dist[i][k], dist[j][k]);
		
		for (int i = 1; i < 1 << n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++)
				cnt += (i >> j & 1);
				
			for (int j = 1; j <= n; j++)
				colored[j] = false;
				
			int blocks = 0;
			for (int j = 1; j <= n; j++)
				if ((i >> j - 1 & 1) and not colored[j]) {
					qualify(j, i);
					blocks += 1;
				}
			
			if (cnt == k && blocks <= 2) {				
				int max = 0;
				for (int j = 0; j < n; j++)
					if (!(i >> j & 1)) {
						int min = inf;
						for (int k = 1; k <= n; k++) 
							if (i >> k - 1 & 1)
								min = std::min(min, dist[k][j + 1]);
						max = std::max(max, min);
					} 
				ans = std::min(ans, max);
			}
		}
		
		std::cout << ans << "\n";
	}
	
	return 0;
}
