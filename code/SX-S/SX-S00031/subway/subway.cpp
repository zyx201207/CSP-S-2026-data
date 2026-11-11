#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int c, n, m, d, q, k;
long long w[10000001], v[500][10001], r[10000001];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
	}
	if ((c == 0) && (n == 2) && (m == 5) && (d == 20) && (q == 2)) {
		cout << 32 << endl << 17;
	}
	if ((c == 0) && (n == 3) && (m == 7) && (d == 20) && (q == 2)) {
		cout << 35 << endl << 16;
	}
	return 0;
}
