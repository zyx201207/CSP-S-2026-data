#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, cnt[105], a[N], v[N], ans;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 0; j <= 32; j++) {
			int w = (a[i] >> j) & 1;
			cnt[j] += w;
		}
	}
	for (int j = 32; j >= 0; j--) {
		if (cnt[j] >= m) {
			ans += (1 << j);
			for (int i = 1; i <= n; i++) {
				if (v[i] == 1)
					continue;
				if (((a[i] >> j) & 1) == 0) {
					v[i] = 1;
					for (int k = 0; k <= 32; k++) {
						int w = (a[i] >> k) & 1;
						cnt[k] -= w;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
