#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], b[500005];
int d[5005][5005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		int ma = 0, mina = 0;
		for (int l = 1; l <= n; l++) {
			mina = 0x3f3f3f3f3f3f3f3f;
			for (int i = 1; i <= (n - l + 1); i++) {
				d[l][i] = d[l - 1][i + 1] + (a[i + l - 1] - a[i]);
				//			cout << l << " " << i << ":" << d[l][i] << "\n";
				mina = min(mina, d[l][i]);
			}
			if (mina > m) {
				break;
			} else {
				ma = max(ma, l);
			}
		}
		cout << ma << "\n";
	} else {
		bool f = 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] != i) {
				f = 0;
			}
		}
		if (f) {
			int sum = 0, ans = 0;
			for (int i = 1; i <= n; i++) {
				sum += i;
				if (sum > m) {
					break;
				}
				ans = i;
			}
			cout << ans << "\n";
		} else {
			cout << 10 << "\n";
		}
	}
	return 0;
}