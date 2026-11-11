#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
const int maxm = 5e4 + 5;
#define LL long long

int c, n, m, d, q;
int w[maxm], k[maxn];
int a[maxn][maxm];
LL t[maxn][maxm];
bool vis[maxm];
struct Node {
	int u, t;
};

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	
	while (q --) {
		int s, t;
		cin >> s >> t;
		queue <Node> qq;
		LL ans = 1e18; 
		qq.push({s, 0});
		for (int i = 1; i <= m; i ++) vis[i] = 0;
		vis[s] = 1;
		while (!qq.empty()) {
			int u = qq.front().u;
			LL t = qq.front().t;
			qq.pop();
			if (u == t) {
				ans = min(ans, t);
				break;
			}
			for (int i = 1; i <= n; i ++) {
				bool found = 0;
				for (int j = 1; j <= k[i]; j ++) {
					if (a[i][j] == u) {
						found = 1;
						break;
					}
				}
				if (!found) continue;
				for (int j = 1; j <= k[i]; j ++) {
					if (!vis[a[i][j]]) {
						vis[a[i][j]] = 1;
						qq.push({a[i][j], ::t[i][u] + ::t[i][j]});
					}
				}
			}
		}
		
		cout << ans + w[s] + w[t] << '\n';
	}
	
	return 0;
}
