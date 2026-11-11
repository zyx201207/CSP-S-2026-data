#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 100;
int tot, c, n, m, d, q, w[N], k[N], f[5100][5100];
struct segyid {
	int u, v, w;
} sum[N];

bool cmp(segyid x, segyid y) {
	return x.w < y.w;
}
signed main() {
//	system("fc subway.out subway4.ans");
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	
	int aa = 0;
	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= n; i ++) {
		cin >> k[i];
		
		for(int j = 1; j <= k[i]; j ++) {
			int a, t;
			cin >> a >> t;
			sum[++ tot] = {m + k[i], a, t};
//			E[m + k[i]].push_back({a[i][j], t[i][j]});
//			E[a[i][j]].push_back({m + k[i], t[i][j]});
			f[m + i][a] = t;
			f[a][m + i] = t;
		}
		
	}
	aa = n;
//	sort(sum + 1, sum + 1 + tot, cmp);
	
	for(int i = 1; i <= m + aa; i ++) {
		for(int j = 1; j <= m + aa; j ++) {
			for(int k = 1; k <= m + aa; k ++) {
				f[j][k] = min(f[j][k], f[j][i] + f[i][k]);
			}
		}
	}
	
//	for(int i = 1; i <= tot; i ++) {
//		int x = find(sum[i].u), y = find(sum[i].v);
//		if(x != y) {
//			E[sum[i].u].push_back({sum[i].v, sum[i].w});
//			E[sum[i].v].push_back({sum[i].u, sum[i].w});
//			fa[x] = y;
//		}
//	}
	
	
	while(q --) {
		int l, r;
		cin >> l >> r;
		cout << f[l][r] + w[l] + w[r] << "\n";
	}
	return 0;
} 
