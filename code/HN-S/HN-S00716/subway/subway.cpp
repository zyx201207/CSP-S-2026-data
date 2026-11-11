#include<iostream>
using namespace std;
const int MAXM = 5e5 + 5, MAXN = 500 + 5;
int c, n, m, d, q, w[MAXM], k[MAXN], a[MAXN][MAXM];
int main () {
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++) cin >> a[i][j] >> t[i][j];
	}
	while (q --) {
		int l, r;
		cin >> l >> r;
		
	}
	return 0;
}
