#include <bits/stdc++.h>
using namespace std;

long long y[10000][10000] = {};
long long dt[1000000];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> dt[i];
	}
	int k;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int bh, t;
			cin >> bh >> t;
		}
	}
	return 0;
}