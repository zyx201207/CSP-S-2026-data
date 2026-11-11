#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
const int M = 505;
int a[M][N], t[M][N];
int w[M];
int ans;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
			sum += t[i][j];
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << sum << "\n";
	}
	return 0;
}