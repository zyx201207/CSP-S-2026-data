#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 23;

int n, a[N], m;

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 20) {
		int ans = 0;
		for (int mask = 0; mask < (1 << n); mask++) {
			if (__builtin_popcount(mask) == m) {
				int res = (1 << (n + 1)) - 1; 
				
				for (int i = 0; i < n; i++) {
					if ((mask >> i) & 1) 
						res = res & a[i + 1];
				}
				
				ans = max(ans, res); 
			}
		}
		cout << ans; 
	}
	else if (n <= 2000) {
		if (m == 1) {
			int mx = 0;
			for (int i = 1; i <= n; i++) {
				mx = max(mx, a[i]);
			}
			cout << mx;
		}
		else if (m == n) {
			int ans = a[1];
			for (int i = 2; i <= n; i++) {
				ans = ans & a[i];
			}
			cout << ans;
		}
		else if (m == 2) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					ans = max(ans, a[i] & a[j]);
				}
			}
			cout << ans;
		}
	}
	else {
		sort(a + 1, a + 1 + n, cmp);
		int ans = a[1];
		for (int i = 2; i <= m; i++) {
			ans = ans & a[i];
		}
		cout << ans;
	}
	return 0;
}
