#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, m1, a[500005], ans, cnt;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
/*	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}*/
	if (n <= 5000) {
		for (int j = 1; j <= n; j++) {
			cnt = 0, m1 = m;
			for (int i = j; i <= n; i++) {
				if ((i - j) * (a[i] - a[i-1]) <= m1) {
					m1 -= (i - j) * (a[i] - a[i-1]);
					cnt++;
				} else {
					break;
				}
			}
			ans = max(ans, cnt);
//			cout << "cnt=" << cnt << ",ans=" << ans << endl;
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if ((i - 1) * (a[i] - a[i-1]) <= m1) {
				m1 -= (i - 1) * (a[i] - a[i-1]);
				cnt++;
			} else {
				break;
			}
		}
		cout << cnt;
	}
	return 0;
}