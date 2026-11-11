// SN-S00351 杨益烜 西安交通大学附属中学 
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int c, n, m, d, q, w[N], a[505][N], t[505][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= 2 * k; j++) {
			cin >> a[i][(j + 1) / 2] >> t[i][(j + 1) / 2];
		}
	}
	return 0;
}
