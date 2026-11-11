#include <bits/stdc++.h>
using namespace std;

const int N = 16;
int Co[1<<N], cnt, lg[1<<N], sum[1<<N], n, k; //表示第i个连通块
int g[N][N], dis[N][N];

int lb(int x) {
	return (x&-x);
}
void solve() {
	memset(dis,0x3f,sizeof dis);
	memset(Co,0,sizeof Co);
	memset(lg,0,sizeof lg);
	memset(sum,0,sizeof sum);
	memset(g,0,sizeof g);
	 
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u][v] = g[v][u] = 1;
		dis[u][v] = dis[v][u] = 1;
		dis[i][i] = dis[i+1][i+1] = 0;
	}
	for (int K = 1; K <= n; K++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][K]+dis[K][j],dis[i][j]);
			}
		}
	}
	for (int S = 1; S < (1<<n); S++) {
		sum[S] = sum[S-lb(S)] + 1;
		lg[S] = lg[S/2] + 1;
		if (sum[S] == 1) Co[S] = 1;
		else {
			int x = lg[lb(S)];
			bool flag = 0;
			for (int j = 1; j <= n; j++) {
				if (j == x) continue;
				if (g[x][j] && ((1<<(j-1)) & S)) {flag = 1; break;}
			}
			Co[S] = flag;
		}
	}
	int Min = 1e9;
	for (int S = 1; S < (1<<n); S++) {
		if (!Co[S]) continue;
		for (int T = 1; T < (1<<n); T++) {
			if (!Co[T]) continue;
			if (sum[S|T] == k) {
				int Max = 0;
				for (int i = 1; i <= n; i++) {
					int minn = 1e9;
					for (int j = 1; j <= n; j++) {
						if ((1<<j-1) & (S|T)) {
							minn = min(minn,dis[i][j]);
						}
					}
					Max = max(Max,minn);
				}
				Min = min(Min,Max);
			}
		}
	}
	cout << Min << "\n";
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, T;
	cin >> c >> T;
	while (T--) solve();
	
	
	return 0;
}
