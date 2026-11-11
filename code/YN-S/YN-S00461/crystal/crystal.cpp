#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int b[500005];
int c[500005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		c[i] = a[i] - a[i - 1];
	}
	int f = 0;
	for (int i = 1; i < n; i++) {
		if (c[i] != c[i + 1]) {
			f++;
		}
	}
	if (f == 1 || f == 0) {
		int cnt = 0;
		int x = c[2];
		int sum = 1;
		while (m - x >= 0) {
			m -= x;
			cnt++;
			sum++;
			if (cnt == 2) {
				cnt = 0;
				x += c[2];
			}
		}
		cout << sum;
	} else {
		int max1 = INT_MIN;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				b[i] = abs(a[i] - a[j]);
			}
			sort(b + 1, b + 1 + n);
			int sum = 0;
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				sum += b[i];
				ans++;
				if (sum > m) {
					break;
				} else if (sum == m) {
					max1 = max(max1, ans);
					break;
				}
			}
		}
		cout << max1;
	}

	return 0;
}