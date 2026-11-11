#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], dp[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int max = -1;
	for (int i = 1; i <= n; i++) {
		int cnt = 1;
		if (i < max) {
			break;
		} else {
			for (int j = i - 1; j >= 1; j--) {
				if (a[j] + m >= a[i]) {
					cnt++;
				} else {
					break;
				}
			}
			if (cnt > max) {
				max = cnt;
			}
		}

	}
	cout << max;
	return 0;
}