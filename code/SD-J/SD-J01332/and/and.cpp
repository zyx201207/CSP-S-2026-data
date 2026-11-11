#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	vector<int> bit(30 + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = 0; j <= 30; ++j) {
			if ((1 << j) & a[i]) {
				bit[j]++;
			}
		}
	}
	for (int i = 30; i >= 0; --i) {
		if (bit[i] < m) {
			for (int j = 1; j <= n; ++j) {
				if (a[j] >= (1 << i)) {
					a[j] -= (1 << i);
				}
			}
		}
		else {
			break;
		}
	}
	sort(a.begin() + 1, a.end(), [](int a, int b) {
		return a > b;
	});
	int ans = a[1];
	for (int i = 2; i <= m; ++i) {
		ans &= a[i];
	}
	cout << ans << '\n';
	return 0;
} 
