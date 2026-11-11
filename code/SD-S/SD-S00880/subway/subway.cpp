#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

const int N = 510;
const int M = 5e5+10;
const ll inf = 1e18;
int c, n, m, d, q, w[M], k[N], sx, tx;
ll f[N][N];
vector<int> a[N], t[N];
vector<pii> sw[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		for(int j = 1; j <= k[i]; j++) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[i].push_back(x);
			t[i].push_back(y);
			sw[x].push_back({i, y});
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			f[i][j] = inf;
		f[i][i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < a[i].size(); j++) {
			int zt = a[i][j], tim = t[i][j];
			for(auto it : sw[zt]) {
				int ti = it.first;
				f[ti][i] = f[i][ti] = min(f[i][ti], 1LL * it.second + tim);
			}
		}
	}
	for(int o = 1; o <= n; o++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][o] + f[o][j]);
		}
	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) {
//			printf("f[%d][%d] = %lld\n", i, j, f[i][j]);
//		}
//	}
	while(q--) {
		scanf("%d%d", &sx, &tx);
		ll mi = inf;
		for(auto it : sw[sx]) {
			int zt = it.first, tim = it.second;
			for(auto tit : sw[tx]) {
				int tzt = tit.first, ttim = tit.second;
				mi = min(mi, tim + f[zt][tzt] + ttim);
			}
		}
		printf("%lld\n", mi + w[sx] + w[tx]);
	}
	return 0;
}
