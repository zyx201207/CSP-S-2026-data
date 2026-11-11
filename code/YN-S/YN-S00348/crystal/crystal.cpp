#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], ans;
int sum[N];
int w;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 5000) {
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int len = i; len >= 1; len--) {
				w = len * a[i] - sum[i];
				if (w <= m) {
					ans = max(ans, len);
					break;
				}
			}
		}
	} else {
		if (m == 0) {
			cout << "0";
			return 0;
		}
		int d = a[2] - a[1];
		int e = 0, p = -1, ee = 0;
		for (int i = 1; i <= n; i++) {
			p++;
			e += p;
			ee = e * d;
			if (ee <= m) {
				ans = i;
			} else {
				break;
			}
		}
	}
	cout << ans;
	return 0;
}