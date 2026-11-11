#include <bits/stdc++.h>
using namespace std;
//#define int long long
//#define ll long long
//#define ull unsigned long long
const int K = 5e5 + 10, N = 510, M = 5e5 + 10;
int w[M], a[N][K], t[N][K];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, x, y;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) cin >> a[i][j] >> t[i][j];
	}
	while (q--) {
		cin >> x >> y;
		cout << x * y * y - x << "\n"; 
	}
	return 0;
}
