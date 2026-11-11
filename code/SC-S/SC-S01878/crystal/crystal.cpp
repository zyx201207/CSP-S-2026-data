#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int a[N], s[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans << "\n";
	return 0;
}

/*
14:43 AC 
*/