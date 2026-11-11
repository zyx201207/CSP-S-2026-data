//SN-S00695
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 507, M = 5e5 + 7, inf = 2e18;
int c, n, m, d, q;
int w[M];
int dp[N][N];
struct node{
	int to, w;
};
vector<node> bel[M];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		dp[i][i] = 0;
		int len;
		cin >> len;
		for (int j = 1; j <= len; j++){
			int u, t;
			cin >> u >> t;
			bel[u].push_back({i, t});
		}
	}
	
	for (int u = 1; u <= m; u++){
		int siz = bel[u].size();
		for (int i = 0; i < siz; i++){
			for (int j = i + 1; j < siz; j++){
				int v1 = bel[u][i].to, v2 = bel[u][j].to,
				w1 = bel[u][i].w, w2 = bel[u][j].w;
				int adj = w1 + w2;
				dp[v1][v2] = min(dp[v1][v2], adj);
				dp[v2][v1] = min(dp[v2][v1], adj);
			}
		}
	}
		
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			if (i == k) continue;
			for (int j = i + 1; j <= n; j++){
				if (j == i) continue;
				if (j == k) continue;
				int len = dp[i][k] + dp[k][j];
				dp[i][j] = min(dp[i][j], len);
				dp[j][i] = min(dp[j][i], len);
			}
		}
	}
	for (int _ = 1; _ <= q; _++){
		int u, v, res = 0, ans = inf;
		cin >> u >> v;
		res += w[u] + w[v];
		int sizu = bel[u].size(), sizv = bel[v].size();
		for (int i = 0; i < sizu; i++){
			for (int j = 0; j < sizv; j++){
				int res1 = res;
				int v1 = bel[u][i].to, v2 = bel[v][j].to;
				res1 += bel[u][i].w + bel[v][j].w + dp[v1][v2];
				ans = min(ans, res1);
			}
		}
		cout << ans << '\n';
	}
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
two-way?!?!?!?! 
*/
