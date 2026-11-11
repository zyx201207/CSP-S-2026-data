#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], pre[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(), cout.tie();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
//		cout << a[i] << " ";
	}
	int l = 0, r = n, q = 5e5 + 5;
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] * (i - 1) - pre[i - 1] <= m && a[i] * (i - 1) - pre[i - 1] > 0) {
			ans = i;
//			cout << l << " " << r << " ";
		} else {
			int o = q;
			if (i != 1)
				for (int j = min(q, (i - ans)); i - j >= ans && j > 0; j--) {
//					cout << i << " " << j << " " << a[i] * (i - j - 1) - pre[i - 1] + pre[j] << "\n";
					if (a[i] * (i - j - 1) - pre[i - 1] + pre[j] <= m) {
						ans = max(ans, i - j);
						o = j;
						break;
					}
				}
			q = o;
		}

	}
	cout << ans;

	return 0;
}
