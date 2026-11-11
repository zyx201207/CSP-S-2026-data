#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 3e6 + 10;
typedef pair<int, int> pii;
long long c, t, n, m;
long long x[N];

bool check (int l, int r) {
	if (r - l + 1 <= 3) return 0;
	for (int i = l + 1; i <= r; i++) {
		if (x[i] - x[i - 1] > m) return 0;
	}
	long long mi = 1e18, cnt = 0;
	for (int mask = 1; mask <= (1 << (r - l)) - 1; mask++) {
		long long tot = 0, lst = x[l];
		bool fl = 0;
		for (int i = l + 1; i <= r - 1; i++) {
			if (mask & (1 << (i - l - 1))) {
				tot++;
				if (x[i] - lst > m) {
					fl = 1;
					break;
				}
				lst = x[i];
			}
		}
		if (x[r] - lst + 1 > m) fl = 1;
		if (fl) continue;
		if (tot == mi) cnt++;
		if (tot < mi) mi = tot, cnt = 1;
	}
	return cnt == 2;
}
int s[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> t;
	if (11 <= c && c <= 12) {
		while (t--) {
			cin >> n >> m;
			long long d = 0;
			for (int i = 1; i <= n; i++) cin >> x[i];
			d = x[2] - x[1];
			if (m < d * 2 || m >= (d * n)) {
				cout << 0 << '\n';
				continue;
			}
			cout << 1ll * n - 2ll * (m / d) + 1 << "\n";
		}
		return 0;
	}
//	if (13 <= c && c <= 14) {
//		while (t--) {
//			cin >> n >> m;
//			long long d = 0;
//			for (int i = 1; i <= n; i++)
//				cin >> x[i], s[i] = x[i] - x[i - 1];
//			for (int i = 1; i <= n; i++)
//				s[i] += s[i - 1];
//			for (int i = 1; i <= n; i++)
//			{
//				for (int j = ) 
//			} 
//		}
//	}

	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> x[i];
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (check (i, j))
					ans ++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

