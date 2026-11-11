#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
const int M = 500005, N = 505, D = 25;
int C, n, m, d, q;
int a[M], p[M][D], w[M][D], c[M], e[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int u, v;
			cin >> u >> v;
			p[u][++c[u]] = i;
			w[u][c[u]] = v;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++) e[i][j] = e[j][i] = INF;
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= c[i]; j++){
			int u = p[i][j];
			for(int k = j+1; k <= c[i]; k++){
				int v = p[i][k];
				if(w[i][j]+w[i][k] < e[u][v]) e[u][v] = e[v][u] = w[i][j]+w[i][k];
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				e[i][j] = min(e[i][j], e[i][k]+e[k][j]);
			}
		}
	}
	while(q--){
		int u, v;
		cin >> u >> v;
		int ans = INF;
		for(int i = 1; i <= c[u]; i++){
			for(int j = 1; j <= c[v]; j++){
				ans = min(ans, w[u][i]+w[v][j]+e[p[u][i]][p[v][j]]);
			}
		}
		cout << ans+a[u]+a[v] << '\n';
	}
	return 0;
} 
